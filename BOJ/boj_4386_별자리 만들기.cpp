// Created by strit on 2022-10-24. gold3 4386 별자리 만들기 - 최소신장트리 mst(크루스칼)
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <cmath>
#define INF 987654321

using namespace std;

int n;
vector<pair<double,double>> star;
vector<pair<double, pair<int, int>>> edge;
int parent[101];

//부모 노드 찾기
int find(int u){
    if(parent[u] == u) return u;

    return parent[u] = find(parent[u]);
}

//연결되어있는지
bool union_node(int u, int v){
    u = find(u);
    v = find(v);

    if(u==v) return false; //사이클 생김
    else{
        parent[u] = v;
        return true;
    }
}

double cal_dist(double x, double y, double x2, double y2){
    return sqrt(pow(x - x2, 2) + pow(y - y2, 2));
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for(int i=0; i<n; i++){
        double x, y;
        cin >> x >> y;
        star.push_back({x, y});
    }

    //별들 사이 거리 계산
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            double r = cal_dist(star[i].first, star[i].second, star[j].first, star[j].second);
            edge.push_back({r, {i, j}});
        }
    }

    sort(edge.begin(), edge.end());

    for(int i=0; i<n; i++){
        parent[i] = i;
    }

    double ans = 0.0;
    for(int i=0; i<edge.size(); i++){
        int x = edge[i].second.first;
        int y = edge[i].second.second;
        double cost = edge[i].first;

        if(union_node(x, y)){
            ans += cost;
        }
    }

    printf("%.2f", ans);
}

