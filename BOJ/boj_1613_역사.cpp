// Created by strit on 2022-11-28. gold3 1613 역사 - 플로이드 와샬
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <cmath>
#include <stack>
#define INF 987654321

using namespace std;

int n, k, s;
int check[401][401];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;
    for(int i=0; i<k; i++){
        int s, e;
        cin >> s >> e;
        check[s][e] = 1; //s가 e보다 먼저 발생
    }

    for(int k=1; k<=n; k++){
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                if(check[i][k] && check[k][j]){
                    check[i][j] = 1;
                }
            }
        }
    }

    cin >> s;
    for(int i=0; i<s; i++){
        int a, b;
        cin >> a >> b;
        if(check[a][b]==1)
            cout << "-1\n";
        else if(check[b][a]==1)
            cout << "1\n";
        else cout << "0\n";
    }

}

