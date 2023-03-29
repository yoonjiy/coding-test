package 시뮬레이션;

import java.util.*;
import java.io.*;

public class boj_20057_java {
    static int[] dr = {0, 1, 0, -1}; //서, 남, 동, 북
    static int[] dc = {-1, 0, 1, 0};
    //1 1 2 2 7 7 10 10 5 a
    static int[][] spreadR = {
        {-1, 1, -2, 2, -1, 1, -1, 1, 0, 0},
        {0, 0, 1, 1, 1, 1, 2, 2, 3, 2},
        {-1, 1, -2, 2, -1, 1, -1, 1, 0, 0},
        {0, 0, -1, -1, -1, -1, -2, -2, -3, -2}
    };
    static int[][] spreadC = {
        {0, 0, -1, -1, -1, -1, -2, -2, -3, -2},
        {-1, 1, -2, 2, -1, 1, -1, 1, 0, 0},
        {0, 0, 1, 1, 1, 1, 2, 2, 3, 2},
        {-1, 1, -2, 2, -1, 1, -1, 1, 0, 0}
    };
    static int[] percent = {1, 1, 2, 2, 7, 7, 10, 10, 5};
    
    static int[][] sand;
    static int answer;
    static int n;
    
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.parseInt(br.readLine());
        sand = new int[n][n];
        
        for(int i=0; i<n; i++){
            StringTokenizer st= new StringTokenizer(br.readLine());
            for(int j=0; j<n; j++){
                sand[i][j] = Integer.parseInt(st.nextToken());
            }
        }
        
        
        int moveCnt = 1;
        int r = n/2;
        int c = n/2;
        int dir = 0; //서, 남, 동, 북으로 이동
        while(true){
            for(int i=0; i<2; i++){
                for(int j=0; j<moveCnt; j++){
                    spreadSand(r, c, dir);
                    r += dr[dir];
                    c += dc[dir];
                }
                dir = (dir+1)%4; 
            }
            
            moveCnt++;

            if(moveCnt==n){
                //마지막 이동
                for(int i=0; i<moveCnt-1; i++){
                    spreadSand(r, c, dir);
                    r += dr[dir];
                    c += dc[dir];
                }
                break;
            }
        }

        System.out.println(answer);

    }
    
    public static void spreadSand(int r, int c, int dir){
        int nr = r + dr[dir];
        int nc = c + dc[dir];
        int s = sand[nr][nc];

        for(int i=0; i<9; i++){
            //모래 흩날림
            int nnr = r + spreadR[dir][i];
            int nnc = c + spreadC[dir][i];

            int add = s*percent[i]/100;

            if(nnr<0 || nnc<0 || nnr>=n || nnc>=n) {
                //범위를 벗어나는 모래 
                answer += add;
            }
            else{
                sand[nnr][nnc] += add;
            }

            sand[nr][nc] -= add;
        }

        //a칸으로 모래 이동
        int nnr = r + spreadR[dir][9];
        int nnc = c + spreadC[dir][9];

        if(nnr<0 || nnc<0 || nnr>=n || nnc>=n) {
            //범위를 벗어나는 모래 
            answer += sand[nr][nc];
        }
        else{
            sand[nnr][nnc] += sand[nr][nc];
        }

        sand[nr][nc] = 0;

    }
}