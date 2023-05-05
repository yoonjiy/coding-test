package 브루트포스;

import java.io.*;
import java.util.*;
import java.util.stream.Collectors;

public class boj_15661_스타트링크 {
    static int n;
    static int answer = Integer.MAX_VALUE;
    static int[][] score;
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        //스타트 팀의 능력치와 링크 팀의 능력치의 차이를 최소로 하려고 한다
        n = Integer.parseInt(br.readLine());

        StringTokenizer st;
        score = new int[n][n];
        for(int i=0; i<n; i++){
            st = new StringTokenizer(br.readLine());
            for(int j=0; j<n; j++){
                score[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        boolean[] visited;
        for(int i=1; i<=n/2; i++){
            //i명, n-i명으로 팀을 나눈다.

            //i명 선택하기. 조합
            visited = new boolean[n];
            dfs(0, i, 0, visited);
        }

        System.out.println(answer);

    }

    public static void dfs(int depth, int cnt, int idx, boolean[] visited){
        if(depth==cnt){
            //i명이 선택되었으면, 두 팀의 능력치 차이 비교
            answer = Math.min(answer, calculate(visited));
            if(answer == 0) {
				System.out.println(answer);
				System.exit(0);
			}
            return;
        }

        for(int i=idx; i<n; i++){
            if(visited[i]) continue;

            visited[i] = true;
            dfs(depth+1, cnt, i+1, visited);

            visited[i] = false;
        }
    }

    public static int calculate(boolean[] visited){
        //능력치 차이 비교
        int t1sum = 0;
        int t2sum = 0;
 
        for(int i=0; i<n-1; i++){
            for(int j=i; j<n; j++){
                //둘다 team1 선수라면
                if(visited[i] && visited[j]){
                    t1sum += score[i][j];
                    t1sum += score[j][i];
                }
                else if(!visited[i] && !visited[j]) {
                    t2sum += score[i][j];
                    t2sum += score[j][i];
                }
            }
        }

        return Math.abs(t1sum-t2sum);
    }
    
}
