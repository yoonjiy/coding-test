package 브루트포스;

import java.util.*;
import java.io.*;

public class boj_2961_도영이가만든맛있는음식 {
    static int n;
    static long[][] ingredient;
    static boolean[] visited;
    static int answer = Integer.MAX_VALUE;
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        n = Integer.parseInt(br.readLine());
        ingredient = new long[n][2]; //신맛, 쓴맛

        StringTokenizer st;
        for(int i=0; i<n; i++){
            st = new StringTokenizer(br.readLine());

            ingredient[i][0] = Integer.parseInt(st.nextToken());
            ingredient[i][1] = Integer.parseInt(st.nextToken());
        }

        //신맛과 쓴맛의 차이가 가장 작은 요리를 만드는 프로그램을 작성하시오.
        for(int i=1; i<=n; i++){
            visited = new boolean[n];
            dfs(i, 0, 0);
        }

        System.out.println(answer);

    }

    public static void dfs(int cnt, int depth, int idx){
        if(depth==cnt){
            answer = Math.min(answer, (int)calculate());
            return;
        }

        for(int i=idx; i<n; i++){
            if(visited[i]) continue;

            visited[i] = true;

            dfs(cnt, depth+1, i+1);

            visited[i] = false;

        }
    }

    public static long calculate(){
        //신맛 - 곱과 쓴맛 - 합의 차이
        long mul = 1, sum = 0;
        for(int i=0; i<n; i++){
            if(visited[i]){
                mul *= ingredient[i][0];
                sum += ingredient[i][1];
            }
        }

        return Math.abs(mul-sum);
    }
    
}
