// Created by strit on 2022-05-18. gold1 2098 외판원 순회 - TSP(비트마스킹,dp,dfs)
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <queue>

#define MAX 16
#define INF 987654321

using namespace::std;

int n; //도시의 수 n개
int w[MAX][MAX]; //도시 i에서 j로 가기 위한 비용
int dp[MAX][1 << MAX]; //i: 현재 방문 도시, j: 지금 까지 지나온 경로(비트마스킹) 일 때 최소 비용을 저장,

int dfs(int current, int visited){
    if(visited == ((1 << n) - 1)){ //모든 도시를 방문한 상태, 2^n - 1
        if(w[current][0] != 0){ //current에서 0번째 인덱스로 돌아갈 수 있는지
            return w[current][0];
        }
        else
            return INF;
    }

    if(dp[current][visited] != -1)
        return dp[current][visited];

    dp[current][visited] = INF;

    for(int i=0; i<n; i++){
        if((visited & (1 << i))|| w[current][i]==0){ //i번째 도시를 이미 방문을 했거나, current에서 i로 가는 길이 없을 때
            continue;
        }
        dp[current][visited] = min(dp[current][visited], w[current][i] + dfs(i, visited | 1 << i)); //dp 갱신
    }

    return dp[current][visited];
}

int main() {
    cin >> n;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> w[i][j];
        }
    }
    memset(dp, -1, sizeof(dp));

    //외판원 순회에 필요한 최소 비용 출력
    cout << dfs(0, 1);
}

