package 브루트포스;

import java.util.*;
import java.io.*;

public class boj_16439_치킨치킨치킨 {
    static int n, m;
    static int answer = Integer.MIN_VALUE;
    static int[][] preference;
    static int[] comb;
    static boolean[] visited;
    public static void main(String[] args) throws Exception{
        // 3개의 치킨을 선택할 때, 가능한 만족도의 합의 최댓값을 구해주세요.
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());

        preference = new int[n][m];
        for(int i=0; i<n; i++){
            st = new StringTokenizer(br.readLine());
            for(int j=0; j<m; j++){
                preference[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        //치킨 3개 고르기 - 조합
        comb = new int[3];
        visited = new boolean[m];
        dfs(0, 0, comb);

        System.out.println(answer);
    }

    public static void dfs(int depth, int idx, int[] comb){
        if(depth==3){
            answer = Math.max(answer, calculate(comb));
            return;
        }

        for(int i=idx; i<m; i++){
            if(visited[i]) continue;

            visited[i] = true;
            comb[depth] = i;
            dfs(depth+1, i+1, comb);

            visited[i] = false;
        }
    }

    public static int calculate(int[] comb){
        //3 치킨에 대한 만족도의 합
        int sum = 0;
        //시킨 치킨들 중에 가장 선호도가 큰 값으로 결정
        for(int i=0; i<n; i++){
            int max = -1;
            for(int c:comb){
                max = Math.max(max, preference[i][c]);
            }
            sum += max;
        }

        return sum;
    }
}
