// Created by strit on 2022-08-30. silver1 11052 카드 구매하기 - dp

#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#include <queue>
#include <cstring>

using namespace std;

int N;
int dp[1001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    // N개의 카드를 구매하기 위해 민규가 지불해야 하는 금액의 최댓값 - dp
    cin >> N;

    dp[0] = 0;
    for(int i=1; i<=N; i++){
        cin >> dp[i];
    }

    for(int i=2; i<=N; i++){
        for(int j=1; j<=i/2; j++){
            dp[i] = max(dp[i], dp[i-j]+dp[j]);
        }
    }

    cout << dp[N];

}

