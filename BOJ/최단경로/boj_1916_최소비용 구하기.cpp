// Created by strit on 2022-02-23. gold5 1916 최소비용 구하기 - 다익스트라
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define INF 987654321
using namespace::std;

int n, m;
int dist[1001];
vector<pair<int,int>> graph[100001];

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
    //출발 도시에서 도착 도시까지 가는데 드는 최소비용을 출력
    //N개의 도시, M개의 버스
    cin >> n >> m;
    for(int i=0; i<m; i++){
        //출발도시 도착도시 버스비용
        int v, w, cost;
        cin >> v >> w >> cost;
        graph[v].push_back({w, cost});
    }

    fill(dist, dist + 1001, INF);

    int s, e; // 출발도시 도착도시
    cin >> s >> e;

    dijkstra(s);

    cout << dist[e];
}



