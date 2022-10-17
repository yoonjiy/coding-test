// Created by strit on 2022-10-17. gold3 1623 음악프로그램 - 위상정렬
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#include <math.h>
#define INF 987654321

using namespace std;

int n, m;
vector<int> node[1001];
int in[1001];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    //위상정렬
    cin >> n >> m;
    for(int i=0; i<m; i++){
        int cnt;
        int temp[101];
        cin >> cnt;
        for(int j=0; j<cnt; j++){
            cin >> temp[j];
        }
        for(int j=0; j<cnt-1; j++){
            node[temp[j]].push_back(temp[j+1]);
            in[temp[j+1]]++;
        }
    }

    queue<int> q;
    vector<int> path;
    for(int i=1; i<=n; i++){
        if(in[i]==0){
            q.push(i);
        }
    }

    while(!q.empty()){
        int v = q.front();
        path.push_back(v);
        q.pop();

        for(int i=0; i<node[v].size(); i++){
            int curr = node[v][i];
            in[curr]--;
            if(in[curr]==0){
                q.push(curr);
            }
        }
    }

    if(path.size()!=n) cout << "0";
    else{
        for(int i=0; i<path.size(); i++){
            cout << path[i] << "\n";
        }
    }


}

