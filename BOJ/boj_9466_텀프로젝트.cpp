// Created by strit on 2022-10-21. gold3 9466 텀프로젝트 - dfs
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#define INF 987654321

using namespace std;

int t;
bool visited[100001];
bool isFinished[100001];
int graph[100001];
int cnt;

void dfs(int i){
    visited[i] = true;
    int next = graph[i];
    if(!visited[next]){
        dfs(next);
    }
    else if(!isFinished[next]){ //사이클을 이룸
        for(int j=next; j!=i; j=graph[j]){
            cnt++;
        }
        cnt++;
    }
    isFinished[i] = true;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> t;
    while(t--){
        int n;

        cin >> n;

        for(int i=1; i<=n; i++){
            cin >> graph[i];
        }
        for(int i=1; i<=n; i++){
            if(!visited[i]){
                dfs(i);
            }
        }
        cout << n-cnt << "\n";

        cnt = 0;
        memset(visited, false, sizeof(visited));
        memset(isFinished, false, sizeof(isFinished));
    }
}

