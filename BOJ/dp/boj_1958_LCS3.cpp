// Created by strit on 2022-12-13. gold3 1958 LCS3
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <cmath>
#include <tuple>
#define INF 987654321

using namespace std;

int dp[101][101][101];

int max(int a, int b, int c) {
    return max(max(a, b), c);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    //문자열 3개의 LCS
    string s1, s2, s3;
    cin >> s1 >> s2 >> s3;
    s1 = ' '+s1;
    s2 = ' '+s2;
    s3 = ' '+s3; //마진 설정

    for(int i=1; i<s1.size(); i++){
        for(int j=1; j<s2.size(); j++){
            for(int k=1; k<s3.size(); k++){
                //일치하는 경우
                if(s1[i]==s2[j] && s2[j]==s3[k]){
                    dp[i][j][k] = dp[i-1][j-1][k-1] + 1;
                }
                    //일치하지 않는 경우
                else{
                    dp[i][j][k] = max(dp[i-1][j][k], dp[i][j-1][k], dp[i][j][k-1]);
                }
            }
        }
    }

    cout << dp[s1.size()-1][s2.size()-1][s3.size()-1];

}

