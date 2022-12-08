// Created by strit on 2022-10-04. gold3 11049 행렬 곱셈 순서 - dp
#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
#include <math.h>
#define INF 987654321

using namespace std;

int n;
int dp[501][501];
pair<int, int> matrix[501];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for(int i=1; i<=n; i++){
        cin >> matrix[i].first >> matrix[i].second;
    }

    for(int i=1; i<=n; i++){ //구간 범위 크기
        for(int j=1; i+j<=n; j++){ //시작 지점
            dp[j][i+j] = INF;
            for(int k=j; k<=i+j; k++){ //중간 지점
                dp[j][i+j] = min(dp[j][i+j], dp[j][k] + dp[k+1][i+j] + matrix[j].first * matrix[k].second * matrix[i+j].second);
            }
        }
    }

    cout << dp[1][n];

}

