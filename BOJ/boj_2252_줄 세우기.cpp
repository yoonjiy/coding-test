// Created by strit on 2022-03-30. gold3 2252 줄 세우기 - 위상정렬
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace::std;

int main() {
    int n, m; //n명의 학생, m은 키를 비교한 회수
    int in[100001];
    vector<int> node[32001];

    cin >> n >> m;

    int a, b;
    for(int i=0; i<m; i++){
        cin >> a >> b;
        in[b]++; //진입 차수
        node[a].push_back(b); //인접 관계
    }

    queue<int> q;
    for(int i=1; i<=n; i++){
        if(in[i]==0)
            q.push(i);
    }

    while(!q.empty()){
        int v = q.front();
        q.pop();
        cout << v << " ";

        for(int i=0; i<node[v].size(); i++){
            in[node[v][i]]--;
            if(in[node[v][i]]==0)
                q.push(node[v][i]);
        }
    }
}

