// Created by strit on 2022-10-25. gold3 1865 웜홀 - 벨만포드
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <cmath>
#define INF 987654321

using namespace std;

int t;
int dist[501];

bool bellman_ford(int n, vector<pair<int, pair<int ,int >>> edge){
dist[1] = 0;
for(int i=0; i<n-1; i++){
for(int j=0; j<edge.size(); j++){
int cost = edge[j].first;
int s = edge[j].second.first;
int e = edge[j].second.second;

if(dist[e] > dist[s] + cost)
dist[e] = dist[s] + cost;
}
}

for(int j=0; j<edge.size(); j++){
int cost = edge[j].first;
int s = edge[j].second.first;
int e = edge[j].second.second;

if(dist[e] > dist[s] + cost){
return true; //음의 사이클이 생김
}
}
return false;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> t;
    while(t--){
        int n, m, w;
        cin >> n >> m >> w;
        vector<pair<int, pair<int, int>>> edge;

        for(int i=0; i<m; i++){ //도로 정보, 무방향
            int s, e, t;
            cin >> s >> e >> t;
            edge.push_back({t, {s,e}});
            edge.push_back({t, {e, s}});
        }
        for(int i=0; i<w; i++){ //웜홀 정보
            int s, e, t;
            cin >> s >> e >> t;
            edge.push_back({-t, {s, e}});
        }

        fill(dist, dist+501, INF);

        if(bellman_ford(n, edge))
            cout << "YES\n";
        else cout << "NO\n";

    }
}

