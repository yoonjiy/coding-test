// Created by strit on 2022-09-19. gold5 2225 합분해 - dp
#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
#define INF 987654321

using namespace std;

int n, k;
long long dp[201][201];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;

    //dp[k][n] -> k개의 수를 더해 합이 n이 되는 경우의 수
    for(int i=0; i<=n; i++){
        dp[1][i] = 1;
    }

    for(int i=1; i<=k; i++){
        for(int j=0; j<=n; j++){
            for(int l=0; l<=j; l++){
                dp[i][j] += dp[i-1][j-l];
                dp[i][j] %= 1000000000;
            }
        }
    }

    cout << dp[k][n];

}

