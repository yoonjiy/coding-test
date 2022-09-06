// Created by strit on 2022-09-06. silver1 11403 경로찾기 - 플로이드 워셜

#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#include <queue>
#include <cstring>
#define INF 987654321

using namespace std;

int N;
int adj[101][101];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> adj[i][j];
            if(adj[i][j] == 0)
                adj[i][j] = INF;
        }
    }


    //플로이드-워셜
    for (int k=0; k<N; k++){
        for (int i=0; i<N; i++){
            for (int j=0; j<N; j++){
                adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
            }
        }
    }

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(adj[i][j] == INF)
                cout << "0 ";
            else
                cout << "1 ";
        }
        cout << "\n";
    }

}

