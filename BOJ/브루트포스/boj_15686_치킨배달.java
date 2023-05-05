package 브루트포스;

import java.util.*;
import java.io.*;

public class boj_15686_치킨배달 {
    static int n, m, k;
    static int[][] map;
    static int[] dr = {0, 0, 1, -1};
    static int[] dc = {1, -1, 0, 0};
    static List<int[]> chickens;
    static List<int[]> homes;
    static boolean[] visited;
    static int answer = Integer.MAX_VALUE;
    public static void main(String[] args) throws Exception{
        //도시에 있는 치킨집 중에서 최대 M개를 고르고, 나머지 치킨집은 모두 폐업시켜야 한다. 
        //어떻게 고르면, 도시의 치킨 거리가 가장 작게 될지 구하는 프로그램을 작성하시오.
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());

        map = new int[n][n];

        chickens = new ArrayList<>();
        homes = new ArrayList<>();
        for(int i=0; i<n; i++){
            st = new StringTokenizer(br.readLine());
            for(int j=0; j<n; j++){
                map[i][j] = Integer.parseInt(st.nextToken());
                if(map[i][j]==2){
                    chickens.add(new int[]{i, j});
                }
                else if(map[i][j]==1){
                    homes.add(new int[]{i, j});
                }
            }
        }

        k = chickens.size(); //치킨 집 개수
        visited = new boolean[k];
        //폐업시키지 않을 치킨집 m개 고르기
        dfs(0, 0);

        System.out.println(answer);
    }

    public static void dfs(int depth, int idx){
        if(depth==m){
            answer = Math.min(answer, calculate());
            return;
        }

        for(int i=idx; i<k; i++){
            if(visited[i]) continue;

            visited[i] = true;
            dfs(depth+1, i+1);
            visited[i] = false;
        }
    }

    public static int calculate(){
        //모든 집들의 치킨 거리의 합
        int sum = 0;
        for(int[] p:homes){
            //가장 가까운 치킨 집의 치킨 거리
            int min = Integer.MAX_VALUE;
            for(int j=0; j<k; j++){
                if(!visited[j]) continue; //폐업한 치킨 집
                int dist = Math.abs(p[0]-chickens.get(j)[0]) + Math.abs(p[1]-chickens.get(j)[1]);
                if(dist < min){
                    min = dist;
                }
            }
            sum += min;
        }
        return sum;
    }

    
}
