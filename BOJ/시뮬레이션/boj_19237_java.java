package 시뮬레이션;

import java.util.*;
import java.io.*;

public class boj_19237_java{
    public static int n, m, k;
    public static int[][] map;
    public static Shark[] sharks;
    public static class Shark{
        //상하좌우에 대한 우선 방향
        int idx;
        int[][] dir;
        Shark(int idx, int[][] dir){
            this.idx = idx;
            this.dir = dir;
        }
    }

    public static void main(String[] args) throws Exception{
        //1번 상어만 격자에 남게 되기까지 몇 초가 걸리는지를 구하는 프로그램을 작성하시오.

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        k = Integer.parseInt(st.nextToken());

        map = new int[n][n];
        sharks = new Shark[m];

        for(int i=0; i<n; i++){
            st = new StringTokenizer(br.readLine());
            for(int j=0; j<n; j++){
                map[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        for(int i=0; i<m; i++){
            sharks[i] = new Shark(i+1, new int[4][4]);
            for(int j=0; j<4; j++){
                st = new StringTokenizer(br.readLine());
                for(int k=0; k<4; k++){
                    sharks[i].dir[j][k] = Integer.parseInt(st.nextToken());
                }
            }
        }

        


    }
}