package 시뮬레이션;

import java.io.*;
import java.util.*;

public class boj_23288_java {
    static int n, m, k;
    static int[][] board;
    static int[] dr = {0, 1, 0, -1}; //동남서북
    static int[] dc = {1, 0, -1, 0};
    static int answer;
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        k = Integer.parseInt(st.nextToken());

        board = new int[n+1][m+1];

        for(int i=1; i<=n; i++){
            st = new StringTokenizer(br.readLine());
            for(int j=1; j<=m; j++){
                board[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        //(1,1) 에 주사위가 놓여있고, 처음에는 동쪽으로 이동
        //k번만큼 이동
        int r = 1, c = 1;
        int dir = 0; //동남서북 0123

        //초기 주사위 전개도
        int[] rdice = {4, 1, 3, 6};
        int[] cdice = {2, 1, 5, 6};

        while(k-- > 0){
            //주사위 굴리기
            if(r+dr[dir]>=1 && r+dr[dir]<=n && c+dc[dir]>=1 && c+dc[dir]<=m){
                rollDice(dir, rdice, cdice);
                r = r+dr[dir];
                c = c+dc[dir];
            }
            else{
                //이동 방향을 반대로 한다음 한칸 이동
                dir = (dir+2)%4;
                rollDice(dir, rdice, cdice);
                r = r+dr[dir];
                c = c+dc[dir];
            }

            //아랫면 정수 a와 정수 b
            int a = rdice[3];
            int b = board[r][c];

            //bfs로 점수 구하기. b*c값
            int cnt = bfs(r, c)*b;
            answer += cnt;

            //이동방향 결정. 동남서북
            //A > B인 경우 이동 방향 90도 시계 방향으로 회전
            //A < B인 경우 이동 방향 90도 반시계 방향으로 회전
            if(a>b){
                dir = (dir+1)%4;
            }
            else if(a<b) {
                if(dir==0) dir = 3;
                else dir = (dir-1)%4;
            }

        }

        System.out.println(answer);

    }
    public static int bfs(int r, int c){
        boolean[][] visited = new boolean[n+1][m+1];
        visited[r][c] = true;
        Queue<int[]> q = new LinkedList<>();
        q.add(new int[]{r, c});
        
        int cnt = 1;
        int num = board[r][c];

        while(!q.isEmpty()){
            int[] p = q.poll();

            for(int i=0; i<4; i++){
                int nr = p[0] + dr[i];
                int nc = p[1] + dc[i];

                if(nr<1||nc<1||nr>n||nc>m||board[nr][nc]!=num||visited[nr][nc]) continue;

                cnt++;
                visited[nr][nc] = true;
                q.add(new int[]{nr, nc});
            }
        }

        return cnt;

    }

    public static void rollDice(int dir, int[] rdice, int[] cdice){
        //가로 방향, 세로 방향 따로 두고 1번 자리만 교체시키기
    
        if(dir==0){
            //오른쪽 방향으로 한칸씩 회전
            int temp = rdice[3];
            for(int i=2; i>=0; i--){
                rdice[i+1] = rdice[i];
            }
            rdice[0] = temp;

            cdice[1] = rdice[1];
            cdice[3] = rdice[3];
        }
        else if(dir==2){
            //왼쪽 방향으로 한칸씩 회전
            int temp = rdice[0];
            for(int i=1; i<=3; i++){
                rdice[i-1] = rdice[i];
            }
            rdice[3] = temp;  

            cdice[1] = rdice[1];
            cdice[3] = rdice[3];
        }
        else if(dir==1){
            //남쪽 방향으로 한칸 굴리기 - 오른쪽 회전
            int temp = cdice[3];
            for(int i=2; i>=0; i--){
                cdice[i+1] = cdice[i];
            }
            cdice[0] = temp;

            rdice[1] = cdice[1];
            rdice[3] = cdice[3];
        }
        else{
            //북쪽 방향으로 한칸 굴리기 - 왼쪽 회전
            int temp = cdice[0];
            for(int i=1; i<=3; i++){
                cdice[i-1] = cdice[i];
            }
            cdice[3] = temp;

            rdice[1] = cdice[1];
            rdice[3] = cdice[3];
        }

    }

    
}
