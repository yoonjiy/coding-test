// Created by strit on 2022-10-26. gold3 1939 중량제한 - 다익스트라
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <cmath>
#define INF 987654321

using namespace std;

int n, m;
int u, v;
int weight[10001];
vector<pair<int, int>> node[10001];

void dijkstra(int s){
    weight[s] = 1000000001;
    priority_queue<pair<int, int>> q;
    q.push({1000000001, s}); //cost, index

    while(!q.empty()){
        int c = q.top().first;
        int curr = q.top().second;
        q.pop();

        if(weight[curr] > c) continue;

        for(int i=0; i<node[curr].size(); i++){
            int next = node[curr][i].first;
            int cost = min(node[curr][i].second, c); //더 적은 중량만큼 옮길 수 있음
            if(weight[next] < cost) {
                weight[next] = cost;
                q.push({cost, next});
            }
        }
    }

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for(int i=0; i<m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        node[a].push_back({b, c});
        node[b].push_back({a, c});
    }
    cin >> u >> v; //공장이 있는 섬의 번호

    fill(weight, weight+10001, -1);
    //u->v 한번에 이동해서 옮길 수 있는 물품들의 중량의 최댓값
    dijkstra(u);
    cout << weight[v];
}

