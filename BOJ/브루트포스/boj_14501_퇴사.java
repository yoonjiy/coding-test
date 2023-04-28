package 브루트포스;

import java.util.*;
import java.io.*;

public class boj_14501_퇴사 {
    static int n;
    static int[] ti;
    static int[] pi;
    static int answer = -1;
    public static void main(String[] args) throws Exception{
        //백준이가 얻을 수 있는 최대 수익을 구하는 프로그램을 작성하시오.
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.parseInt(br.readLine());

        ti = new int[n];
        pi = new int[n];
        StringTokenizer st;
        for(int i=0; i<n; i++){
            st = new StringTokenizer(br.readLine());
            int t = Integer.parseInt(st.nextToken()); //기간
            int p = Integer.parseInt(st.nextToken()); //비용
            
            ti[i] = t;
            pi[i] = p;
        }

        dfs(0, 0);

        System.out.println(answer);

    }

    public static void dfs(int now, int sum){
        if(now==n){
            //종료조건. 마지막 날까지 탐색
            answer = Math.max(answer, sum);
            return;
        }

        //상담을 하는 경우
        if(now+ti[now]<=n)
            dfs(now+ti[now], sum+pi[now]);

        //상담을 안하는 경우
        if(now+1<=n) dfs(now+1, sum);
        
        return;
    }
    
}
