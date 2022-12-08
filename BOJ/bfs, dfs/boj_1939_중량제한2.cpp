// Created by strit on 2022-10-26. gold3 1939 중량제한 - 이분탐색, bfs
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
bool visited[10001];
vector<pair<int, int>> node[10001];

bool bfs(int mid){
    visited[u] = true;
    queue<int> q;
    q.push(u);

    while(!q.empty()){
        int s = q.front();
        q.pop();

        if(s==v) return true;

        for(int i=0; i<node[s].size(); i++){
            int next = node[s][i].first;
            int weight = node[s][i].second;

            if(!visited[next] && weight>=mid){
                visited[next] = true;
                q.push(next);
            }
        }
    }

    return false;
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

    int low = 0;
    int high = 1000000001;
    int mid, ans;
    while(low<=high){
        memset(visited, false, sizeof(visited));

        mid = (low+high)/2;
        if(bfs(mid)){
            ans = mid;
            low = mid+1;
        }
        else{
            high = mid-1;
        }
    }

    cout << ans << "\n";
}

