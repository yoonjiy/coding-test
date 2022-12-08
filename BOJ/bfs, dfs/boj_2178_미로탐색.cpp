// Created by strit on 2022-08-29. silver1 2178 미로탐색 - bfs
#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#include <queue>
#include <cstring>

using namespace std;

char board[102][102];
bool visited[102][102];
int cnt[102][102] = {0, };
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int n, m;

void bfs(int xx, int yy){
    queue<pair<int, int>> q;

    visited[xx][yy] = true;
    cnt[xx][yy]++;

    q.push({xx, yy});

    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx<0 || ny<0 || nx>=n || ny>=m || board[nx][ny]=='0') continue;

            if(!visited[nx][ny] && board[nx][ny]=='1'){
                visited[nx][ny] = true;
                cnt[nx][ny] = cnt[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> board[i][j];
        }
    }

    bfs(0, 0);

    cout << cnt[n-1][m-1];

    return 0;
}

