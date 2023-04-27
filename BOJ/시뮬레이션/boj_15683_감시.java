package 시뮬레이션;

import java.util.*;
import java.io.*;

public class boj_15683_감시 {
    static int n, m;
    static int[][] board;
    static boolean[] visited;
    static int answer = Integer.MAX_VALUE;
    static class CCTV{
        int num;
        int r, c;
        CCTV(int num, int r, int c){
            this.num = num;
            this.r = r;
            this.c = c;
        }
    }
    static List<CCTV> list;
    public static void main(String[] args) throws Exception{
        // CCTV의 방향을 적절히 정해서, 사각 지대의 최소 크기를 구하는 프로그램을 작성하시오.
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());

        board = new int[n][m];
        list = new ArrayList<>();

        for(int i=0; i<n; i++){
            st = new StringTokenizer(br.readLine());
            for(int j=0; j<m; j++){
                board[i][j] = Integer.parseInt(st.nextToken());
                if(board[i][j]>=1 && board[i][j]<=5) {
                    list.add(new CCTV(board[i][j], i, j));
                }
            }
        }

        visited = new boolean[list.size()];
        dfs(0, board);
    }

    public static void dfs(int depth, int[][] temp){
        if(depth==list.size()){
            //모든 cctv 탐색 완료
            answer = Math.min(answer, count(temp)); //사각 지대 개수 세기
            return;
        }
        //4가지 방향 탐색
        for(int i=0; i<4; i++){
            if(visited[i]) continue;
            visited[i] = true;

            //i방향으로 cctv 검사
            CCTV now = list.get(depth);
            int[][] t = new int[n][m];
            for(int j=0; j<n; j++){
                t[j] = temp[j].clone();
            }
            t = simulation(now, t, i);

            dfs(depth+1, t);

            visited[i] = false;
        }
    }

    public static int[][] simulation(CCTV now, int[][] t, int dir){
        int type = now.num;
        if(type==1){
            //한쪽 방향만
        }
        else if(type==2){
            //양쪽 방향
         
        }
        else if(type==3){
            //직각 방향
        }
        else if(type==4){
            //세 방향
        }
        else{
            //4방향
        }
    }

    public static int count(int[][] temp){
        int cnt = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(temp[i][j]==1) cnt++;
            }
        }
        return cnt;
    }
}