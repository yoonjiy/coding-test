// Created by strit on 2022-11-17. gold3 10159 저울 - 플로이드 와샬
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <cmath>
#include <stack>
#define INF 987654321

using namespace std;

int n, m;
int node[101][101];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    for(int i=0; i<m; i++){
        int a, b;
        cin >> a >> b;
        node[a][b] = 1; //a > b
    }

    //플로이드-와샬
    for(int k=1; k<=n; k++){
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                if(node[i][k] && node[k][j]) {
                    //처음 > 중간, 중간 > 끝이면 처음 > 끝임.
                    node[i][j] = 1;
                }
            }
        }
    }

    int cnt;
    for(int i=1; i<=n; i++){
        cnt = 0;
        for(int j=1; j<=n; j++){
            if(i==j) continue;
            if(!node[i][j] && !node[j][i]) cnt++;
        }
        cout << cnt << "\n";
    }

}

