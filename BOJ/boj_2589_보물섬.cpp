// Created by strit on 2022-09-20. gold5 2589 보물섬 - bfs
#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
#define INF 987654321

using namespace std;

int n, m;
char map[51][51];
int path[51][51];
bool visited[51][51];
int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

int bfs(int r, int c){
    queue<pair<int, int>> q;

    int max_len = -1;

    visited[r][c] = true;
    q.push({r, c});

    while(!q.empty()){
        int r = q.front().first;
        int c = q.front().second;
        q.pop();

        for(int i=0; i<4; i++){
            int nr = r + dr[i];
            int nc = c + dc[i];

            if(nr<0 || nc<0 || nr>=n || nc>=m) continue;

            if(!visited[nr][nc] && map[nr][nc]=='L'){
                visited[nr][nc] = true;
                path[nr][nc] = path[r][c] + 1;
                q.push({nr, nc});

                max_len = max(max_len, path[nr][nc]);
            }
        }
    }

    return max_len;
}

void reset(){
    memset(visited, false, sizeof(visited));
    memset(path, 0, sizeof(path));
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> map[i][j];
        }
    }

    int ans = -1;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(map[i][j]=='L'){
                reset();
                int len = bfs(i, j);
                ans = max(ans, len);
            }
        }
    }

    cout << ans;

}

