// Created by strit on 2022-06-21. silver1 9465 스티커 - dp
#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <cstring>

using namespace::std;

#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <cstring>

using namespace::std;

int sticker[2][100001];
int dp[2][100001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    for(int i=0; i<t; i++){
        int n;
        cin >> n;

        for(int i=0; i<2; i++){
            for(int j=0; j<n; j++){
                int value;
                cin >> value;
                sticker[i][j] = value;
            }
        }

        dp[0][0] = sticker[0][0];
        dp[0][1] = sticker[0][1] + sticker[1][0];
        dp[1][0] = sticker[1][0];
        dp[1][1] = sticker[0][0] + sticker[1][1];

        for(int i=2; i<n; i++){
            dp[0][i] = sticker[0][i] + max(dp[1][i-1], dp[1][i-2]);
            dp[1][i] = sticker[1][i] + max(dp[0][i-1], dp[0][i-2]);
        }

        cout << max(dp[0][n-1], dp[1][n-1]) << "\n";

    }


}
