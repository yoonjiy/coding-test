// Created by strit on 2022-09-26. gold3 1520 내리막 길 - dfs, dp
#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
#include <math.h>
#define INF 987654321

using namespace std;

int n, m;
int board[501][501];
int dp[501][501];
int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

int dfs(int r, int c) {
    if (r == n - 1 && c == m - 1) return 1;
    if (dp[r][c] != -1) return dp[r][c];

    dp[r][c] = 0;
    for (int i = 0; i < 4; i++) {
        int nr = r + dr[i];
        int nc = c + dc[i];

        if (nr < 0 || nc < 0 || nr >= n || nc >= m) continue;
        if (board[nr][nc] < board[r][c]) {
            dp[r][c] += dfs(nr, nc);
        }
    }

    return dp[r][c];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> board[i][j];
        }
    }

    memset(dp, -1, sizeof(dp));
    cout << dfs(0, 0);

}

