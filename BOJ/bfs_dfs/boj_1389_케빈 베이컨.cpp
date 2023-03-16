// Created by strit on 2022-02-03. silver1 1389 케빈 베이컨의 6단계 법칙 - bfs, floyd warshall
#include <iostream>
#include <queue>
#include <cstring>

using namespace::std;

int relation[101][101];
int connect[101];
int result[101];
bool visited[101];
int N, M; //유저의 수, 친구 관계의 수

void bfs(int v){
    queue<int> q;
    q.push(v);
    visited[v] = true;

    while(!q.empty()){
        int u = q.front();
        q.pop();

        for(int i=1; i<=N; i++){
            if(relation[u][i]==1 && visited[i]==false){
                visited[i]=true;
                q.push(i);
                connect[i] = connect[u]+1;
            }
        }
    }
}

int main() {
    //케빈 베이컨 수가 가장 작은 사람 출력.
    cin >> N >> M;
    for(int i=0; i<M; i++){
        int a, b;
        cin >> a >> b;
        relation[a][b] = 1;
        relation[b][a] = 1;
    }

    for(int i=1; i<=N; i++){
        bfs(i);
        for(int j=1; j<=N; j++){
            result[i] += connect[j];
        }
        memset(visited, false, sizeof(visited));
        memset(connect, 0, sizeof(connect));

    }

    int min = result[1];
    int min_person = 1;
    for(int i=2; i<=N; i++){
        if(result[i]<min) {
            min = result[i];
            min_person = i;
        }
    }

    cout << min_person;

}




