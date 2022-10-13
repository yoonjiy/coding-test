// Created by strit on 2022-10-13. gold3 2638 치즈 - bfs
#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
#include <math.h>
#define INF 987654321

using namespace std;

int n, m;
int board[101][101];
bool visited[101][101];
int cheese[101][101];
int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};
int ans;

void bfs(){
    queue<pair<int, int>> q;
    visited[0][0] = true;
    q.push({0, 0});

    while(!q.empty()){
        int r = q.front().first;
        int c = q.front().second;
        q.pop();

        for(int i=0; i<4; i++){
            int nr = r + dr[i];
            int nc = c + dc[i];

            if (nr < 0 || nc < 0 || nr >= n || nc >= m || visited[nr][nc]) continue;

            if(board[nr][nc]==0){
                visited[nr][nc] = true;
                q.push({nr, nc}); //벽이면 탐색을 계속 함.
            }
            else if(board[nr][nc]==1){
                cheese[nr][nc]++; //외부와 공기와 접촉
            }
        }
    }
}

void melt(){
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(cheese[i][j]>=2){ //2면 이상 외부공기와 접촉해있으면
                board[i][j] = 0;
            }
        }
    }
}

bool check(){
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(board[i][j]){
                return false; //치즈가 남아있으면
            }
        }
    }
    return true;
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

    while(true){
        if(check()){
            break;
        }
        memset(visited, false, sizeof(visited));
        memset(cheese, 0, sizeof(cheese));
        bfs();
        melt();
        ans++;
    }

    cout << ans;
}

