// Created by strit on 2022-03-02. gold5 2293 동전 1 - 동적프로그래밍
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace::std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, k; //n개의 종류의 동전으로 가치의 합이 k원이 되게 하는 경우의 수
    cin >> n >> k;
    vector<int> coin(n);
    vector<int> dp(k+1);
    for(int i=0; i<n; i++){
        cin >> coin[i];
    }

    dp[0] = 1; //0원을 만들 수 있는 경우의 수 1가지
    for(int i=0; i<n; i++){
        for(int j=coin[i]; j<=k; j++){
            dp[j] += dp[j-coin[i]];
        }
    }

    cout << dp[k];

}



