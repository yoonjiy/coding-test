// Created by strit on 2022-10-22. gold3 2533 사회망 서비스 - 트리, dp
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#define INF 987654321

using namespace std;

int n;
vector<int> adj[1000001];
vector<int> tree[1000001];
bool visited[1000001];
int dp[1000001][2]; //얼리어답터일 때, 아닐 때

void dfs(int node){
    dp[node][0] = 0; // 본인이 얼리가 아니면 얼리 개수 0
    dp[node][1] = 1; // 본인이 얼리면 얼리 개수 1

    for(int i=0; i<tree[node].size(); i++){
        int child = tree[node][i];

        dfs(child);

        dp[node][0] += dp[child][1]; // 현재 노드가 얼리가 아니라면, 주변 노드는 얼리어야 한다.
        dp[node][1] += min(dp[child][0], dp[child][1]); // 현재 노드가 얼리라면, 주변은 얼리 또는 얼리가 아니다.
    }
}

void make_tree(int node){
    visited[node] = true;
    for(int i=0; i<adj[node].size(); i++){
        int next = adj[node][i];
        if(visited[next]) continue; //단방향
        tree[node].push_back(next);
        make_tree(next);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for(int i=0; i<n; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    memset(dp, 0, sizeof(dp));
    make_tree(1);
    dfs(1);
    cout << min(dp[1][0], dp[1][1]);

}
