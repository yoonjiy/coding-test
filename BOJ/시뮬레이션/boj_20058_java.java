package 시뮬레이션;

import java.util.*;
import java.io.*;

public class boj_20058_java{
    static int n, q;
    static int[][] board;
    static int[] order;
    static int len;
    static int[] dr = {0, 0, -1, 1};
    static int[] dc = {-1, 1, 0, 0};
    static boolean[][] visited;
    static int sum, count;
    public static class Point{
        int r, c;
        Point(int r, int c){
            this.r = r;
            this.c = c;
        }
    }
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        q = Integer.parseInt(st.nextToken());

        len = (int)Math.pow(2, n);//2^n
        board = new int[len][len];
        for(int i=0; i<len; i++){
            st = new StringTokenizer(br.readLine());
            for(int j=0; j<len; j++){
                board[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        order = new int[q];
        st = new StringTokenizer(br.readLine());
        for(int i=0; i<q; i++){
            //마법사 상어가 시전한 단계
            order[i] = Integer.parseInt(st.nextToken());
        }

        for(int i=0; i<q; i++){
            //격자를 나누고 시계 방향 90도 회전시킨다
            board = divide(order[i]);
            //얼음이 있는 칸 3개 이상과 인접해있지 않은 칸은 얼음양이 1 줄어든다
            board = melt();
        }

        //남아있는 얼음의 합, 가장 큰 덩어리가 차지하는 칸의 개수
        for(int i=0; i<len; i++){
            for(int j=0; j<len; j++){
                if(board[i][j]==0) continue;
                sum += board[i][j];
            }
        }

        visited = new boolean[len][len];
        for(int i=0; i<len; i++){
            for(int j=0; j<len; j++){
                if(!visited[i][j] && board[i][j]!=0) {
                    count = Math.max(count, bfs(i, j));
            
                }
            }
        }

        System.out.println(sum);
        System.out.println(count);
        
    }

    public static int bfs(int r, int c){
        Queue<Point> q = new LinkedList<>();
        q.add(new Point(r, c));
        visited[r][c] = true;

        int cnt = 1; //칸의 개수

        while(!q.isEmpty()){
            Point p = q.poll();

            for(int i=0; i<4; i++){
                int nr = p.r + dr[i];
                int nc = p.c + dc[i];

                if(nr<0 || nc<0 || nr>=len || nc>=len || visited[nr][nc] || board[nr][nc]==0) continue;

                visited[nr][nc] = true;
                cnt++;
                q.add(new Point(nr, nc));
            }
        }

        return cnt;
    }

    public static int[][] divide(int l){
        int[][] temp = new int[len][len];

        l = (int)Math.pow(2, l);

        //배열 시계 방향 90도 회전
        for(int i=0; i<len; i+=l){
            for(int j=0; j<len; j+=l){
                rotate(i, j, l, temp);
            }
        }

        return temp;
    }

    public static void rotate(int r, int c, int w, int[][] temp){
        for (int i=0; i<w; i++) {
            for (int j=0; j<w; j++) {
                temp[r+i][c+j] = board[r+w-1-j][c+i];
            }
        }
    }

    //얼음은 동시에 녹음
    public static int[][] melt(){

        int[][] temp = new int[len][len];
        for (int i=0; i<len; i++) 
            temp[i] = Arrays.copyOf(board[i], len); //얼음이 녹은 걸 반영해줄 배열

        for(int i=0; i<len; i++){
            for(int j=0; j<len; j++){

                if(board[i][j]==0) continue;

                int cnt = 0;
                for(int k=0; k<4; k++){
                    int nr = i + dr[k];
                    int nc = j + dc[k];

                    if(nr<0 || nc<0 || nr>=len || nc>=len || board[nr][nc]==0) continue;

                    cnt++;
                }

                if(cnt<=2){
                    //얼음이 녹음
                    temp[i][j]--;
                }
            }
        }

        return temp;
    }
        
}