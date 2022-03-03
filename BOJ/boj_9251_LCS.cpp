// Created by strit on 2022-03-03. gold5 9251 LCS - 동적프로그래밍
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace::std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string s1, s2;
    cin >> s1 >> s2;

    int dp[1001][1001];

    for(int i=1; i<=s1.length(); i++){
        for(int j=1; j<=s2.length() ; j++){
            if(s1[i-1] == s2[j-1])
                dp[i][j] = dp[i-1][j-1] + 1;
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }

    cout << dp[s1.length()][s2.length()];

}



