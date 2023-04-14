package dp;
import java.io.*;
import java.util.*;

public class boj_5557_1학년 {
    static int n;
    static int[] num;
    static long[][] dp;
    public static void main(String[] args) throws Exception{
        //상근이가 만들 수 있는 올바른 등식의 수를 구하는 프로그램을 작성하시오. 
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.parseInt(br.readLine());

        num = new int[n];
        StringTokenizer st = new StringTokenizer(br.readLine());
        for(int i=0; i<n; i++){
            num[i] = Integer.parseInt(st.nextToken());
        }

        int last = num[n-1];
        dp = new long[n][21];

        dp[0][num[0]] = 1;
        for(int i=1; i<n-1; i++){
            for(int j=0; j<=20; j++){
                if(j+num[i] <= 20){
                    dp[i][j+num[i]] += dp[i-1][j];
                } 
                if(j-num[i]>=0){
                    dp[i][j-num[i]] += dp[i-1][j];
                }
            }

        }


        System.out.println(dp[n-2][last]);
    }


}
