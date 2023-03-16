// Created by strit on 2022-09-22. gold5 5014 스타트링크 - bfs
#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
#include <math.h>
#define INF 987654321

using namespace std;

int f, s, g, u, d;
int visited[1000001] = {0, };

void bfs(){
    queue<int> q;
    visited[s] = true;
    q.push(s);

    while(!q.empty()){
        int curr = q.front();
        q.pop();

        if(curr==g){
            cout << visited[curr] - 1;
            return;
        }

        int next;
        next = curr + u;
        if(next <= f && !visited[next]){
            visited[next] = visited[curr] + 1;
            q.push(next);
        }

        next = curr - d;
        if(next >= 1 && !visited[next]){
            visited[next] = visited[curr] + 1;
            q.push(next);
        }
    }

    cout << "use the stairs";

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> f >> s >> g >> u >> d;

    bfs();
}

