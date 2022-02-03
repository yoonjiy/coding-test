// Created by strit on 2022-02-03. silver1 1309 동물원 - 동적계획법
#include <iostream>

using namespace::std;

int main() {
    //2*N 배열에 사자를 배치하는 경우의 수. 가로, 세로로 붙어있을 수 없음. 한마리도 배치하지 않는 경우도 1로 침.
    int N;
    cin >> N;
    int dp[100001][3];

    dp[0][0] = dp[0][1] = dp[0][2] = 1;

    for(int i=1; i<N; i++){
        dp[i][0] = (dp[i-1][0] + dp[i-1][1] + dp[i-1][2])%9901;
        dp[i][1] = (dp[i-1][0] + dp[i-1][2])%9901;
        dp[i][2] = (dp[i-1][0] + dp[i-1][1])%9901;
    }

    cout << (dp[N-1][0]+dp[N-1][1]+dp[N-1][2])%9901;
}




