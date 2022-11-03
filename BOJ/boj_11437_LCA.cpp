// Created by strit on 2022-11-03. gold3 11437 LCA
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <cmath>
#define INF 987654321

using namespace std;

int n, m;
vector<int> node[50001];
int parent[50001];
int depth[50001];
bool visited[50001];

void bfs(int s){
    queue<int> q;
    visited[s] = true;
    depth[s] = 0;
    q.push(s);

    while(!q.empty()){
        int u = q.front();
        q.pop();

        for(int i=0; i<node[u].size(); i++){
            int curr = node[u][i];
            if(!visited[curr]){
                depth[curr] = depth[u] + 1;
                visited[curr] = true;
                parent[curr] = u;
                q.push(curr);
            }
        }
    }
}

int LCA(int u, int v){
    if(depth[u] > depth[v])
        swap(u, v);

    //깊이가 같을 때까지 v를 조상노드로 이동시킴
    while(depth[u]!=depth[v]){
        v = parent[v];
    }

    while(u!=v){
        u = parent[u];
        v = parent[v];
    }

    return u;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for(int i=0; i<n-1; i++){
        int u,v;
        cin >> u >> v;
        node[u].push_back(v);
        node[v].push_back(u);
    }

    bfs(1);

    cin >> m;
    for(int i=0; i<m; i++){
        //가장 가까운 공통 조상을 알고 싶은 쌍
        int u,v;
        cin >> u >> v;
        cout << LCA(u, v) << "\n";
    }
}

