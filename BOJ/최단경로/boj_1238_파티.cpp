// Created by strit on 2022-09-13. gold3 1238 파티 - 다익스트라
#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#define INF 987654321

using namespace std;

int n, m, x;
vector<pair<int, int>> v1[1001];
vector<pair<int, int>> v2[1001];
int dist[1001];
int answer[1001];

void dijkstra(int start, vector<pair<int, int>> v[1001]){

    fill(dist, dist+1001, INF);

    dist[start] = 0;
    priority_queue<pair<int, int>> pq; //거리, 노드
    pq.push({0, start});

    while(!pq.empty()){
        int d = -pq.top().first;
        int curr = pq.top().second;
        pq.pop();

        if(dist[curr] < d)
            continue;

        for(int i=0; i<v[curr].size(); i++){
            int nnode = v[curr][i].first;
            int ncost = d + v[curr][i].second;
            if(dist[nnode] > ncost ){
                dist[nnode] = ncost;
                pq.push({-ncost, nnode});
            }
        }
    }

    for (int i=1; i<=n; i++){
        answer[i] += dist[i];
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> x;

    for(int i=0; i<m; i++){
        int s, e, t;
        cin >> s >> e >> t;

        v1[s].push_back({e, t});
        //역간선 정보
        v2[e].push_back({s, t});
    }

    dijkstra(x, v1);
    dijkstra(x, v2);

    int max = 0;
    //저장된 값중에 가장 큰값이 정답(최단거리)
    for (int i = 1; i <= n; i++)
    {
        if (max < answer[i])
            max = answer[i];
    }
    cout << max << '\n';
}

