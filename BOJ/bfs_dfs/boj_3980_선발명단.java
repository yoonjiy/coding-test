package bfs_dfs;

import java.io.*;
import java.util.*;

public class boj_3980_선발명단 {
    static int t;
    static int[][] s;
    static boolean[] visited;
    static int answer = Integer.MIN_VALUE;
    static int[] pos;
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        t = Integer.parseInt(br.readLine());

        while(t-- > 0){
            s = new int[11][11];
            visited = new boolean[11];

            for(int i=0; i<11; i++){
                StringTokenizer st = new StringTokenizer(br.readLine());
                for(int j=0; j<11; j++){
                    s[i][j] = Integer.parseInt(st.nextToken());
                }
            }

            dfs(0, 0);

            System.out.println(answer);
        }
    }

    public static void dfs(int position, int sum){
        if(position==11){
            answer = Math.max(answer, sum);
            return;
        }

        for(int i=0; i<11; i++){
            //해당 포지션에 플레이어의 능력치가 0거나 이미 다른 포지션을 가졌다면 패스
            if(!visited[i] && s[i][position]!=0) {
                visited[i] = true;
                dfs(position+1, sum+s[i][position]);
                visited[i] = false;
            }
            
        }
    }
     
}
