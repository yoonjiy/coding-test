// Created by strit on 2022-10-16. gold3 최소 비용 구하기2 - 다익스트라
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#include <math.h>
#define INF 987654321

using namespace std;

int n, m;
int s, e;
vector<pair<int, int>> node[1001];
int dist[1001];


void dijkstra(int s){
    priority_queue<pair<int, int>> pq;

    dist[s] = 0;
    pq.push({s, 0}); //index, cost

    while(!pq.empty()){
        int curr = pq.top().first;
        int cost = -pq.top().second;

        if(dist[curr] < cost) continue;

        for(int i=0; i<node[curr].size(); i++){
            int c = cost + node[curr][i].second;
            if(c < dist[node[curr][i].first]){
                dist[node[curr][i].first] = c;
                pq.push({node[curr][i].first, -c});
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    //출발 도시, 도착 도시, 비용
    for(int i=0; i<m; i++){
        int s, e, c;
        cin >> s >> e >> c;
        node[s].push_back({e, c});
    }

    cin >> s >> e; //s -> e 최소 비용, 최소 비용을 갖는 경로에 포함되어있는 도시들 출력.

    memset(dist, INF, sizeof(dist));

    dijkstra(s);

    cout << dist[e]; //최소 비용
}

