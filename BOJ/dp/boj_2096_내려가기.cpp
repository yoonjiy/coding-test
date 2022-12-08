// Created by strit on 2022-09-08. gold5 2096 내려가기 - dp
#include <iostream>
#include <algorithm>
#include <string>
#include <queue>

using namespace std;

int n;
int input[3];
int min_dp[3];
int max_dp[3];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for(int i=0; i<3; i++){
        cin >> max_dp[i];
    }
    min_dp[0] = max_dp[0];
    min_dp[1] = max_dp[1];
    min_dp[2] = max_dp[2];

    for(int i=1; i<n; i++){
        for(int j=0; j<3; j++){
            cin >> input[j];
        }

        int temp0 = max_dp[0];
        int temp2 = max_dp[2];
        max_dp[0] = max(max_dp[0], max_dp[1]) + input[0];
        max_dp[2] = max(max_dp[1], max_dp[2]) + input[2];
        max_dp[1] = max(max(temp0, max_dp[1]), temp2) + input[1];

        temp0 = min_dp[0];
        temp2 = min_dp[2];
        min_dp[0] = min(min_dp[0], min_dp[1]) + input[0];
        min_dp[2] = min(min_dp[1], min_dp[2]) + input[2];
        min_dp[1] = min(min(temp0, min_dp[1]), temp2) + input[1];
    }

    cout << max(max(max_dp[0], max_dp[1]), max_dp[2]) << " " << min(min(min_dp[0], min_dp[1]), min_dp[2]);


}

