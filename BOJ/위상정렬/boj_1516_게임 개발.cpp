// Created by strit on 2022-10-13. gold3 1516 게임 개발 - 위상정렬
#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
#include <math.h>
#define INF 987654321

using namespace std;

int n;
int duration[501];
vector<int> node[501];
int in[501];
int ans[501];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    //위상정렬
    cin >> n;
    for(int i=1; i<=n; i++){
        //시간 선수건물번호 -1
        cin >> duration[i];
        int pre = 1;
        while(pre!=-1){
            cin >> pre;
            if(pre!=-1){
                in[i]++; //진입 차수 증가
                node[pre].push_back(i);
            }
        }
    }


    queue<int> q;
    for(int i=1; i<=n; i++){
        if(in[i]==0){
            q.push(i);
            ans[i] = duration[i];
        }
    }

    while(!q.empty()){
        int v = q.front();
        q.pop();

        for(int i=0; i<node[v].size(); i++){
            int curr = node[v][i];
            in[curr]--;
            ans[curr] = max(ans[curr], ans[v]+duration[curr]);
            if(in[curr]==0){
                q.push(curr);
            }
        }
    }

    for(int i=1; i<=n; i++){
        cout << ans[i] << " ";
    }
}

