package bfs_or_dfs.bfs_or_dfs;

import java.util.*;

public class Pro_level2_86971 {
    static List<List<Integer>> graph;
    static boolean[] visited;
    public int solution(int n, int[][] wires) {
        int answer = Integer.MAX_VALUE;
        //두 전력망이 가지고 있는 송전탑 개수의 차이(절대값)를 return
        
        int idx = 0;
        while(idx < wires.length){
            graph = new ArrayList<>();
            for(int i=0; i<=n; i++){
                graph.add(new ArrayList<>());
            }
             
            for(int i=0; i<wires.length; i++){
                if(i==idx) continue;
                graph.get(wires[i][0]).add(wires[i][1]);
                graph.get(wires[i][1]).add(wires[i][0]);
            }
        
            
            int[] cnt = new int[2];
            int id = 0;
            visited = new boolean[n+1];
            for(int i=1; i<=n; i++){
                if(visited[i]) continue;
                cnt[id++] = bfs(i, visited);
            }
            
            answer = Math.min(answer, Math.abs(cnt[1]-cnt[0]));
            
            idx++;
        }
    
        
        return answer;
    }
    
    public static int bfs(int curr, boolean[] visited){
        visited[curr] = true;
        Queue<Integer> q = new LinkedList<>();
        q.add(curr);
        int cnt = 1;
        
        while(!q.isEmpty()){
            int p = q.poll();
            
            for(int i=0; i<graph.get(p).size(); i++){
                int next = graph.get(p).get(i);

                if(visited[next]) continue;

                visited[next] = true;
                cnt++;
                q.add(next);
            }
        }
        
        return cnt;
    }
}
