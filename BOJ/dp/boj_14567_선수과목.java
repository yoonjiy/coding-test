package dp;

import java.io.*;
import java.util.*;

public class boj_14567_선수과목 {
    static int n, m;
    static int[] dp;
    static int[] in;
    static List<Integer>[] list;
    public static void main(String[] args) throws Exception{
        //모든 과목에 대해 각 과목을 이수하려면 최소 몇 학기가 걸리는지 계산하는 프로그램을 작성
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        
        in = new int[n+1];
        dp = new int[n+1]; //dp[i] = k. i번 과목을 이수하기 위한 최소 학기
        list = new ArrayList[n+1];
        for(int i=0; i<=n; i++){
            list[i] = new ArrayList<>();
        }

        for(int i=0; i<m; i++){
            st = new StringTokenizer(br.readLine());
            int f = Integer.parseInt(st.nextToken());
            int s = Integer.parseInt(st.nextToken());

            list[f].add(s);
            in[s]++;
        }

        for(int i=1; i<=n; i++){
            if(in[i]==0){
                dp[i] = 1;
            }
        }

        for(int i=1; i<=n; i++){
            for(int j=0; j<list[i].size(); j++){
                int node = list[i].get(j);
                dp[node] = Math.max(dp[node], dp[i]+1);
            }
        }

        for(int i=1; i<=n; i++){
            System.out.print(dp[i] + " ");
        }
    }
    
}
