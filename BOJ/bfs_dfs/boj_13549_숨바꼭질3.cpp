// Created by strit on 2022-10-09. gold5 13549 숨바꼭질 - bfs
#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
#include <math.h>
#define INF 987654321

using namespace std;

int n, k;
bool visited[100001];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k; //수빈이 위치, 동생 위치

    priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

    pq.push({0, n});

    while(!pq.empty()){
        int time = pq.top().first;
        int loc = pq.top().second;
        visited[loc] = true;
        pq.pop();

        if(loc==k){
            cout << time;
            break;
        }

        if(loc+1 <= 100000 && !visited[loc+1]){
            pq.push({time+1, loc+1});
        }
        if(loc-1 >= 0 && !visited[loc-1]){
            pq.push({time+1, loc-1});
        }
        if(loc*2 <= 100000 && !visited[loc*2]){
            pq.push({time, loc*2});
        }
    }


}

