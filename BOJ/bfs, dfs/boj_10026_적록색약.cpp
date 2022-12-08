// Created by strit on 2022-03-06. gold5 10026 적록색약 - bfs
#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
using namespace::std;

int n;
char section[100][100];

int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

bool visited[100][100];

void bfs(int row, int col){
    queue<pair<int,int>> q;
    q.push({row, col});
    visited[row][col] = true;

    while(!q.empty()){
        int r = q.front().first;
        int c = q.front().second;
        q.pop();
        for(int i=0; i<4; i++) {
            int new_r = r + dx[i];
            int new_c = c + dy[i];
            if (new_r < 0 || new_r >= n || new_c < 0 || new_c >= n) continue;
            if(!visited[new_r][new_c] && section[r][c] == section[new_r][new_c]) {
                visited[new_r][new_c] = true;
                q.push({new_r, new_c});
            }
        }
    }

}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++)
            cin >> section[i][j];
    }

    int cnt = 0, cnt_rg = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(!visited[i][j]){
                bfs(i, j);
                cnt++;
            }
        }
    }

    fill(visited[0], visited[0]+10000, false);

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(section[i][j]=='G') {
                section[i][j] = 'R';
            }
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(!visited[i][j]){
                bfs(i, j);
                cnt_rg++;
            }
        }

    }

    cout << cnt << " " << cnt_rg;

}



