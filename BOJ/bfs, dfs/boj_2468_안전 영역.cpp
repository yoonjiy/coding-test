// Created by strit on 2022-09-18. silver1 2468 안전 영역 - dfs
#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
#define INF 987654321

using namespace std;

int n;
int board[101][101];
int temp[101][101];
bool visited[101][101];
int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, 1, -1};

void dfs(int r, int c){
    visited[r][c] = true;

    for(int i=0; i<4; i++){
        int nr = r + dr[i];
        int nc = c + dc[i];

        if(nr<0 || nc<0 || nr>=n || nc>=n) continue;

        if(!visited[nr][nc] && temp[nr][nc]){
            dfs(nr, nc);
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    int max_height = -1;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> board[i][j];
            if(board[i][j] > max_height)
                max_height = board[i][j];
        }
    }

    int ans = 1;
    for(int h=1; h<=max_height; h++){

        int cnt = 0;

        memset(visited, false, sizeof(visited));
        memset(temp, 0, sizeof(temp));

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(board[i][j] <= h)
                    temp[i][j] = 0;
                else
                    temp[i][j] = 1; //잠기지 않는 영역은 1
            }
        }

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(!visited[i][j] && temp[i][j]){ //연결 영역 탐색
                    dfs(i, j);
                    cnt++;
                }
            }
        }

        ans = max(ans, cnt);
    }

    cout << ans;

}

