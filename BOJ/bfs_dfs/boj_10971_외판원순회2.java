package bfs_dfs;

import java.io.*;
import java.util.*;

public class boj_10971_외판원순회2 {
    //가장 적은 비용을 들이는 외판원의 순회 여행 경로를 구하는 프로그램을 작성하시오.

    static int n;
    static int[][] w;
    static boolean[] visited;
    static int answer = Integer.MAX_VALUE;
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.parseInt(br.readLine());
        w = new int[n][n];
        for(int i=0; i<n; i++){
            StringTokenizer st = new StringTokenizer(br.readLine());
            for(int j=0; j<n; j++){
                w[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        for(int i=0; i<n; i++){
            visited = new boolean[n];
            visited[i] = true;
            dfs(i, i, 0, 0); //시작지점 0
        }
        

        System.out.println(answer);
    }

    public static void dfs(int s, int now, int sum, int depth){
        if(depth==n-1){
            if(w[now][s]==0) return;
            answer = Math.min(answer, sum+w[now][s]);
            return;
        }

        for(int i=0; i<n; i++){
            if(visited[i]) continue;
            if(w[now][i]!=0){
                visited[i] = true;
                dfs(s, i, sum+w[now][i], depth+1);
                visited[i] = false;
            }
        }

        return;
        
    }
    
}
