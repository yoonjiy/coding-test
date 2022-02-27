// Created by strit on 2022-02-27. gold5 1753 최단경로 - 다익스트라
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define INF 987654321
using namespace::std;

int v, e, k;
int dist[20001];
vector<pair<int,int>> graph[300001];

void dijkstra(int start){
    priority_queue<pair<int,int>> pq;

    dist[start] = 0;
    pq.push({0, start});

    while(!pq.empty()){
        int d = -pq.top().first;
        int now = pq.top().second;
        pq.pop();

        if(dist[now] < d)
            continue;

        for(int i=0; i<graph[now].size(); i++){
            int cost = d + graph[now][i].second;
            if(cost < dist[graph[now][i].first]) {
                dist[graph[now][i].first] = cost;
                pq.push({-cost, graph[now][i].first});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    cin >> v >> e;
    cin >> k;

    for(int i=1; i<=v; i++){
        dist[i] = INF;
    }

    for(int i=0; i<e; i++){
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
    }

    dijkstra(k);

    for(int i=1; i<=v; i++){
        if(dist[i]==INF)
            cout << "INF" << endl;
        else
            cout << dist[i] << endl;
    }

}

