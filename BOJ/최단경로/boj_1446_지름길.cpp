// Created by strit on 2022-02-14. silver1 1446 지름길 - 다익스트라
#include <iostream>
#include <vector>
#include <algorithm>

using namespace::std;

struct Edge{
    int w, cost;
};

int main() {
    //운전해야 하는 거리의 최솟값
    //지름길의 개수 N 고속도로의 길이 D
    //지름길의 시작위치, 도착위치, 지름길의 길이
    int N, D;
    cin >> N >> D;
    int dist[10001];
    vector<Edge> graph[10001];
    for(int i=0; i<=D; i++){
        dist[i] = i;
    }

    int v, w, cost;
    for(int i=0; i<N; i++){
        cin >> v >> w >> cost;
        if(w-v <= cost) continue; //지름길 의미 없음.
        if(w > D) continue; //도착지점이 d를 넘어가는 경우
        graph[v].push_back({w, cost});
    }

    int prev;
    for(int i=0; i<=D; i++){
        if(i)
            prev = dist[i-1];
        dist[i] = min(dist[i], prev+1);

        for(auto e: graph[i]){
            if(dist[e.w] > dist[i] + e.cost){
                dist[e.w] = dist[i] + e.cost;
            }
        }
    }

    cout << dist[D];

}

