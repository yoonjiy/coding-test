// Created by strit on 2022-05-20. gold2 1766 문제집 - 위상정렬
#include <iostream>
#include <vector>
#include <queue>

using namespace::std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    //위상 정렬

    int n, m; //문제의 개수, 정보의 개수
    int in[32001]; //진입 차수 저장
    vector<int> node[32001];
    priority_queue<int> q;

    int a, b;
    cin >> n >> m;
    for(int i=0; i<m; i++){
        //a가 b보다 먼저 푸는 게 좋다
        cin >> a >> b;
        in[b]++;
        node[a].push_back(b); //인접 관계
    }

    //가능하면 쉬운 문제부터 풀어야 한다. -> 문제 번호가 작은 것부터 출력

    //진입 차수가 0이면 q에 넣기
    for(int i=1; i<=n; i++){
        if(in[i]==0){
            q.push((-1)*i);
        }
    }

    while(!q.empty()){
        int v = (-1)*q.top();
        q.pop();
        cout << v << " ";

        //진입차수 재계산
        for(int i=0; i<node[v].size(); i++){
            in[node[v][i]]--;
            if(in[node[v][i]]==0){
                q.push((-1)*node[v][i]);
            }
        }
    }
}