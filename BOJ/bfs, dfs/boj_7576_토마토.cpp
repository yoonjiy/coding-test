// Created by strit on 2022-10-03. gold5 7576 토마토 - bfs
#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
#include <math.h>
#define INF 987654321

using namespace std;

int n, m;
int board[1001][1001];
int cnt;
int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};

void bfs(int r, int c){
    queue<pair<int, int>> q;
    //익은 토마토 q에 넣기
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(board[i][j]==1)
                q.push({i, j});
        }
    }

    while(!q.empty()){
        int r = q.front().first;
        int c = q.front().second;
        q.pop();

        for(int i=0; i<4; i++){
            int nr = r + dr[i];
            int nc = c + dc[i];

            if(nr<0 || nc<0 || nr>=n || nc>=m) continue;

            if(board[nr][nc]==0){
                cnt--;
                board[nr][nc] = board[r][c] + 1;
                q.push({nr, nc});
            }
        }
    }

    int ans = -2;
    if(cnt!=0)
        cout << "-1";
    else{
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(ans < board[i][j])
                    ans = board[i][j];
            }
        }

        cout << ans-1;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> m >> n;
    //익은 토마토 1, 익지 않은 토마토 0, 없으면 -1
    bool check = true;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> board[i][j];
            if(board[i][j]!=1)
                check = false;
            if(board[i][j]==0) cnt++;

        }
    }

    if(check)
        cout << "0";
    else{
        bfs(0, 0);
    }
}
}

