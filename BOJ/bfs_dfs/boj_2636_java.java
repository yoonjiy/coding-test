package bfs_dfs;

import java.util.*;
import java.io.*;

public class boj_2636_java {
    static int n, m;
    static int[][] cheese;
    static boolean[][] visited;
    static int[] dr = {0, 0, -1, 1};
    static int[] dc = {-1, 1, 0, 0};
    static int t, count;
    public static void main(String[] args) throws Exception{
        // 공기 중에서 치즈가 모두 녹아 없어지는 데 걸리는 시간과 
        //모두 녹기 한 시간 전에 남아있는 치즈조각이 놓여 있는 칸의 개수를 구하는 프로그램을 작성하시오.
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());

        cheese = new int[n][m];
        for(int i=0; i<n; i++){
            st = new StringTokenizer(br.readLine());
            for(int j=0; j<m; j++){
                cheese[i][j] = Integer.parseInt(st.nextToken());
                if(cheese[i][j]==1) count++; //치즈 조각 개수
            }
        }
        
        bfs();
    }

    public static void bfs(){
        //(0,0)부터 치즈 녹이기
        Queue<Point> q = new LinkedList<>();
        q.add(new Point(0, 0));
        visited = new boolean[n][m];
        visited[0][0] = true;

        int melted = 0; //녹은 가장자리 치즈
        t++;
        
        while(!q.isEmpty()){
            Point p = q.poll();
            for(int i=0; i<4; i++){
                int nr = p.r + dr[i];
                int nc = p.c + dc[i];

                if(nr<0 || nc<0 || nr>=n || nc>=m || visited[nr][nc]) continue;

                visited[nr][nc] = true;

                if(cheese[nr][nc]==0){
                    q.add(new Point(nr, nc)); //계속 탐색 진행
                }
                else{
                    //치즈가 녹음
                    cheese[nr][nc] = 0;
                    melted++;
                }
            }
        }

        count -= melted;

        //치즈가 다 녹았다면
        if(count==0){
            System.out.println(t);
            System.out.println(melted);
            return;
        }
        else{
            bfs();
        }
    }

    public static class Point{
        int r, c;
        Point(int r, int c){
            this.r = r;
            this.c = c;
        }
    }
}
