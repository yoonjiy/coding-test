// Created by strit on 2022-09-28. gold3 1937 욕심쟁이 판다 - dfs, dp
#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
#include <math.h>
#define INF 987654321

using namespace std;

int n;
int forest[501][501];
int dp[501][501];
int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};

int dfs(int r, int c){

    if(dp[r][c]!=-1) return dp[r][c];

    dp[r][c] = 1;

    for(int i=0; i<4; i++){
        int nr = r + dr[i];
        int nc = c + dc[i];

        if(nr<0 || nc<0 || nr>=n || nc>=n) continue;

        if(forest[r][c] < forest[nr][nc]){
            dp[r][c] = max(1 + dfs(nr, nc), dp[r][c]);
        }
    }

    return dp[r][c];

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    //dfs, 메모이제이션
    //대나무가 더 많은 지역으로만 이동, 최대한 많은 칸을 방문
    cin >> n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> forest[i][j];
        }
    }

    int ans = -1;
    memset(dp, -1, sizeof(dp));
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            ans = max(dfs(i, j), ans);
        }
    }

    cout << ans;

}

