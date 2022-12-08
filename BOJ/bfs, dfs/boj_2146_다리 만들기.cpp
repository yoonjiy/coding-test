// Created by strit on 2022-10-05. gold3 2146 다리 만들기
#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
#include <math.h>
#define INF 987654321

using namespace std;

int n;
int island[101][101];
int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};
bool visited[101][101];

struct bridge{
    int r, c;
    int length;
};

void label_bfs(int r, int c, int label){
    queue<pair<int, int>> q;

    q.push({r, c});
    visited[r][c] = true;
    island[r][c] = label;

    while(!q.empty()){
        int r = q.front().first;
        int c = q.front().second;
        q.pop();

        for(int i=0; i<4; i++){
            int nr = r + dr[i];
            int nc = c + dc[i];

            if(nr<0 || nc<0 || nr>=n || nc>=n) continue;

            if(!visited[nr][nc] && island[nr][nc]==-1){
                island[nr][nc] = label;
                visited[nr][nc] = true;
                q.push({nr, nc});
            }
        }
    }
}

int bfs(int idx){
    queue<bridge> q;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(island[i][j]==idx){
                visited[i][j] = true;
                q.push({i, j, 0});
            }
        }
    }

    while(!q.empty()){
        int r = q.front().r;
        int c = q.front().c;
        int len = q.front().length;
        q.pop();

        for(int i=0; i<4; i++){
            int nr = r + dr[i];
            int nc = c + dc[i];

            if(nr<0 || nc<0 || nr>=n || nc>=n) continue;

            //다른 섬에 도달한 경우
            if(island[nr][nc]!=0 && island[nr][nc] != idx){
                return len;
            }

            //바다이면서 방문하지 않은 경우
            if(island[nr][nc]==0 && !visited[nr][nc]){
                visited[nr][nc] = true;
                q.push({nr, nc, len+1});
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> island[i][j];
            if(island[i][j]!=0)
                island[i][j] = -1;
        }
    }

    int label = 1;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(island[i][j]==-1 && !visited[i][j]){
                label_bfs(i, j, label++);
            }
        }
    }

    int ans = 987654321;
    for(int i=1; i<label; i++){
        memset(visited, false, sizeof(visited));
        ans = min(ans, bfs(i));
    }

    cout << ans;
}

