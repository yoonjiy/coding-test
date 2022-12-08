// Created by strit on 2022-12-08. gold3 1774 우주신과의 교감 - mst(kruskal)
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <cmath>
#include <tuple>
#define INF 987654321

using namespace std;

int n, m;
int parent[1001];
vector<tuple<double, int ,int>> dist;

struct position {
    int x, y;
};

int find(int u){
    if(parent[u]==u) return u;
    else return parent[u] = find(parent[u]);
}

bool union_node(int u, int v){
    u = find(u);
    v = find(v);

    if(u==v) return false; //연결하면 사이클 생김
    else {
        parent[u] = v;
        return true;
    }
}

double cal_dist(int x1, int y1, int x2, int y2){
    return sqrt(pow(x1-x2, 2) + pow(y1-y2, 2));
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    //mst

    cin >> n >> m;

    vector<position> god;
    god.push_back({0, 0});
    for(int i=0; i<n; i++){
        int x, y;
        cin >> x >> y;
        god.push_back({x, y}); //우주신 위치
    }

    for(int i=1; i<=n; i++){
        parent[i] = i;
    }

    for(int i=0; i<m; i++){
        int u, v;
        cin >> u >> v;
        union_node(u, v); //이미 연결된 통로들
    }

    for(int i=1; i<=n-1; i++) {
        for (int j = i + 1; j <= n; j++) {
            double r = cal_dist(god[i].x, god[i].y, god[j].x, god[j].y);
            dist.push_back({r, i, j});
        }
    }

    sort(dist.begin(), dist.end());

    double ans = 0.0;
    for(int i=0; i<dist.size(); i++){
        int u = get<1>(dist[i]);
        int v = get<2>(dist[i]);
        double cost = get<0>(dist[i]);
        if (union_node(u, v))
            ans += cost;
    }

    printf("%.2lf", ans);
}

