package 시뮬레이션;

import java.io.*;
import java.util.*;

public class boj_21610_java {
    static int n, m;
    static int[][] A;
    static List<Cloud> clouds;
    static boolean[][] visited;
    static int[] dr = {0, -1, -1, -1, 0, 1, 1, 1}; // ←, ↖, ↑, ↗, →, ↘, ↓, ↙ 
    static int[] dc = {-1, -1, 0, 1, 1, 1, 0, -1};
    public static class Cloud{
        int r, c;
        Cloud(int r, int c){
            this.r = r; 
            this.c = c;
        }
    }
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());

        A = new int[n+1][n+1]; //바구니의 물의 양
        
        clouds = new ArrayList<>();
        // (N, 1), (N, 2), (N-1, 1), (N-1, 2)에 비구름이 생긴다
        clouds.add(new Cloud(n, 1)); clouds.add(new Cloud(n, 2));
        clouds.add(new Cloud(n-1, 1)); clouds.add(new Cloud(n-1, 2));

        for(int i=1; i<=n; i++){
            st = new StringTokenizer(br.readLine());
            for(int j=1; j<=n; j++){
                A[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        for(int i=0; i<m; i++){
            st = new StringTokenizer(br.readLine());
            int d = Integer.parseInt(st.nextToken()); //di방향으로 si만큼 이동
            int s = Integer.parseInt(st.nextToken());

            //모든 구름 이동
            moveCloud(d, s);

        } 

        //바구니에 들어있는 물의 양의 합
        int answer = 0;
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                answer += A[i][j];
            }
        }

        System.out.println(answer);


    }

    public static void moveCloud(int d, int s){
        visited = new boolean[n+1][n+1];
        List<Cloud> temp = new ArrayList<>(); //물이 증가한 칸
        for(Cloud c:clouds){
            int nr = c.r + (dr[d-1]*s%n);
            int nc = c.c + (dc[d-1]*s%n);

            if(nr>n) nr -= n;
            if(nc>n) nc -= n;
            if(nr<=0) nr += n;
            if(nc<=0) nc += n;

            //비 내려서 +1 증가
            A[nr][nc]++;
            temp.add(new Cloud(nr, nc));
            visited[nr][nc] = true; //원래 구름이 있었던 칸 표시
        }

        //구름 사라짐, 대각선 방향으로 물이 있는 바구니 수만큼 r,c칸 물의 양 증가
        for(Cloud c:temp){
            int cnt = 0; //물이 있는 바구니 수

            for(int i=1; i<8; i+=2){ //1, 3, 5, 7 번째
                int nr = c.r + dr[i]; 
                int nc = c.c + dc[i];

                if(nr<1 || nc<1 || nr>n || nc>n) continue;

                if(A[nr][nc]>0) cnt++; //물이 들어있는 바구니의 개수 세기
            }

            //cnt만큼 물의 양 증가
            A[c.r][c.c] += cnt;
        }

        //물의 양이 2이상인 모든 칸에 구름이 생기고, 물의 양이 2씩 줄어든다
        clouds = new ArrayList<>();
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                if(visited[i][j]) continue; //구름이 사라진 칸에서 구름이 생기지 않음
                if(A[i][j]>=2){
                    A[i][j] -= 2; //물의 양 줄어든다
                    clouds.add(new Cloud(i, j)); //구름이 생김
                }
            }
        }
    }
}
