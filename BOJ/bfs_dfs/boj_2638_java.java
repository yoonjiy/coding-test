package bfs_dfs;

import java.util.*;
import java.io.*;

public class boj_2638_java {
    static int n, m;
    static int[][] board;
    static int rest;
    static int time;
    static int[][] cheese;
    static boolean[][] visited;
    static int[] dr = {0, 0, -1, 1};
    static int[] dc = {-1, 1, 0, 0};
    public static class Point{
        int r, c;
        Point(int r, int c){
            this.r = r;
            this.c = c;
        }
    }
    public static void main(String[] args) throws Exception{
        //치즈가 모두 녹아 없어지는데 걸리는 정확한 시간을 구하는 프로그램을 작성하시오
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
    
        board = new int[n][m];
        for(int i=0; i<n; i++){
            st = new StringTokenizer(br.readLine());
            for(int j=0; j<m; j++){
                board[i][j] = Integer.parseInt(st.nextToken());
                if(board[i][j]==1) rest++; //치즈 조각 개수
            }
        }

        bfs();
    }

    public static void bfs(){
        visited = new boolean[n][m];
        cheese = new int[n][m];
        Queue<Point> q = new LinkedList<>();
        q.add(new Point(0, 0));
        visited[0][0] = true;

        time++;

        int melted = 0;

        while(!q.isEmpty()){
            Point p = q.poll();

            for(int i=0; i<4; i++){
                int nr = p.r + dr[i];
                int nc = p.c + dc[i];

                if( nr<0 || nc<0 || nr>=n || nc>=m || visited[nr][nc]) continue;
                
                if(board[nr][nc]==1){
                    cheese[nr][nc]++;
                    if(cheese[nr][nc]>=2){
                        //치즈가 녹음
                        visited[nr][nc] = true;
                        board[nr][nc] = 0;
                        melted++;
                    }
                }
                else{
                    //벽이면 탐색을 계속 진행함.
                    visited[nr][nc] = true;
                    q.add(new Point(nr, nc));
                }
            }
        }

        rest -= melted;

        if(rest==0){
            System.out.println(time);
            return;
        }
        else{
            bfs();
        }
    }
}
