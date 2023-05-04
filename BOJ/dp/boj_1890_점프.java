package dp;

import java.io.*;
import java.util.*;

public class boj_1890_점프 {
    static int n;
    static int[][] board;
    static long[][] dp;
    public static void main(String[] args) throws Exception{
        //가장 왼쪽 위 칸에서 가장 오른쪽 아래 칸으로 규칙에 맞게 이동할 수 있는 경로의 개수를 구하는 프로그램을 작성하시오.
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.parseInt(br.readLine());
        board = new int[n][n];
        dp = new long[n][n];
        StringTokenizer st;
        for(int i=0; i<n; i++){
            st = new StringTokenizer(br.readLine());
            for(int j=0; j<n; j++){
                board[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        dp[0][0] = 1; 

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(i==n-1 && j==n-1) continue;
                
                int move = board[i][j];
                if (i + move < n) { //아래로 이동 가능
                    dp[i + move][j] += dp[i][j];
                }
                if (j + move < n) { //오른쪽으로 이동 가능
                    dp[i][j + move] += dp[i][j];
                }
            }
        }
        
        System.out.println(dp[n-1][n-1]);
    }


}
