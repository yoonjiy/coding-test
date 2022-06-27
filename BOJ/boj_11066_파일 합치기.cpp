// Created by strit on 2022-06-27. gold3 11066 파일 합치기 - dp
#include <iostream>
#include <algorithm>
#include <map>
#include <string>

using namespace std;

int file[501];
int sum[501];
int dp[501][501];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int t, k;
    cin >> t;
    for(int i=0; i<t; i++){
        cin >> k;
        for(int i=1; i<=k; i++){
            cin >> file[i];
            sum[i] = sum[i-1] + file[i];
        }

        for(int i=1; i<=k; i++){ //구해야 하는 범위 크기
            for(int j=1; j<=k-i; j++){ //합치는 범위 시작 인덱스
                dp[j][i+j] = 987654321;
                for(int m=j; m<i+j; m++){
                    dp[j][i+j] = min(dp[j][i+j], dp[j][m] + dp[m+1][i+j] + sum[i+j] - sum[j-1]);
                }
            }
        }

        cout << dp[1][k] << "\n";
    }
}

