package dp;

import java.io.*;
import java.util.*;

public class boj_1912_연속합 {
    static int n;
    static int[] num;
    static int[] dp;
    public static void main(String[] args) throws Exception{
        //연속된 몇 개의 수를 선택해서 구할 수 있는 합 중 가장 큰 합
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.parseInt(br.readLine());
        num = new int[n];
        dp = new int[n]; //0~i까지의 최대 합
        StringTokenizer st = new StringTokenizer(br.readLine());
        for(int i=0; i<n; i++){
            num[i] = Integer.parseInt(st.nextToken());
        }


    
        dp[0] = num[0];
        int answer = dp[0];
        for(int i=1; i<n; i++){
            dp[i] = Math.max(dp[i-1]+num[i], num[i]);
            answer = Math.max(answer, dp[i]);
        }

        System.out.println(answer);
    }
    
}
