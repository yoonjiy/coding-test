package bfs_dfs;

import java.util.*;
import java.io.*;


public class sof_635_java
{
    static int n;
    static List<Node>[] nodes;
    static long[] subtree;
    static long[] sum;
    static long[] answer; 
    public static class Node{
        int u, cost;
        Node(int u, int cost){
            this.u = u;
            this.cost = cost;
        }
    }  
    public static void main(String args[]) throws Exception
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.parseInt(br.readLine());

        nodes = new ArrayList[n+1];
        for(int i=0; i<=n; i++) 
            nodes[i] = new ArrayList<>();
        
        for(int i=1; i<=n-1; i++){
           String[] str = br.readLine().split(" ");
           nodes[Integer.parseInt(str[0])].add(new Node(Integer.parseInt(str[1]),Integer.parseInt(str[2])));
           nodes[Integer.parseInt(str[1])].add(new Node(Integer.parseInt(str[0]), Integer.parseInt(str[2])));
        }

        subtree = new long[n+1];
        sum = new long[n+1];

        dfs1(1, 0); 

        //for(int i=1; i<=n; i++) System.out.println(sum[i]);
        
        dfs2(1, 0);
        for(int i=1; i<=n; i++) System.out.println(sum[i]);
        
    }

    public static void dfs1(int curr, int parent) {
		subtree[curr] = 1;

        for(Node node:nodes[curr]){
            int child = node.u;
            int cost = node.cost;
            if(child!=parent){
                dfs1(child, curr);
                sum[curr] += sum[child] + subtree[child]*cost;
                subtree[curr] += subtree[child]; //자신 포함 서브트리 개수 구하기
            }
        }
	}

    public static void dfs2(int curr, int parent){
        for(Node node:nodes[curr]){
            int child = node.u;
            int cost = node.cost;
            if(child!=parent){
                sum[child] = sum[curr] + cost*(n-2*subtree[child]);
                dfs2(child, curr);
            }
        }
    }
}