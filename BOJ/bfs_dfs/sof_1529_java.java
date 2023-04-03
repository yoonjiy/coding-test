package bfs_dfs;

import java.util.*;
import java.io.*;


public class sof_1529_java
{
    static int n, m;
    static int s, t;
    public static void main(String args[]) throws Exception
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());

        List<List<Integer>> edge = new ArrayList<>();
        List<List<Integer>> edgeR = new ArrayList<>();

        for(int i=0; i<=n; i++){
            edge.add(new ArrayList<>());
            edgeR.add(new ArrayList<>());
        }

        for(int i=0; i<m; i++){

            st = new StringTokenizer(br.readLine());
            int u = Integer.parseInt(st.nextToken());
            int v = Integer.parseInt(st.nextToken());

            edge.get(u).add(v);
            edgeR.get(v).add(u);
        }

        st = new StringTokenizer(br.readLine());
        s = Integer.parseInt(st.nextToken());
        t = Integer.parseInt(st.nextToken());

        Set<Integer> s1, s2, s3, s4;

        s1 = new HashSet<>();
        s2 = new HashSet<>();
        dfs(s, edge, new boolean[n+1], s1, t); //s에서 도달 가능한 정점들
        dfs(t, edgeR, new boolean[n+1], s2, s); //s에서 도달 가능한 정점들이 t로 도달하는지
        //둘의 교집합이 출근길 경로에 등장하는 정점들
        s1.retainAll(s2);
        // System.out.println(s1);
        // System.out.println(s2);

        s3 = new HashSet<>();
        s4 = new HashSet<>();
        dfs(t, edge, new boolean[n+1], s3, s);
        dfs(s, edgeR, new boolean[n+1], s4, t);
        // System.out.println(s3);
        // System.out.println(s4);
        s3.retainAll(s4);


        s1.retainAll(s3);
        int cnt = s1.size();
        if(s1.contains(s)) cnt--;
        if(s1.contains(t)) cnt--;
        System.out.println(cnt);

    }

    public static void dfs(int u, List<List<Integer>> edge, boolean[] visited, Set<Integer> set, int e){
        if(u==e) return;
        for(int i=0; i<edge.get(u).size(); i++){
            int next = edge.get(u).get(i);
            if(visited[next]) continue;

            visited[next] = true;
            set.add(next);

            dfs(next, edge, visited, set, e);

            visited[next] = false;
        }
    }
}
