// Created by strit on 2022-12-12. gold3 1941 소문난 칠공주 - dfs, bfs
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <cmath>
#include <tuple>
#define INF 987654321

using namespace std;
char map[5][5];
int seat[5][5];
bool visited[5][5];
bool selected[26];
int ans;

int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

bool isConnected(){
    memset(visited, false, sizeof(visited));
    memset(seat, 0, sizeof(seat));

    //좌표 저장
    queue<pair<int, int>> q;
    int temp = 0;
    for(int i=0; i<25; i++){
        if(selected[i]){
            int r = i/5;
            int c = i%5;

            seat[r][c] = 1;

            if(temp==0){
                visited[r][c] = true; //시작 좌표
                q.push({r, c});
                temp++;
            }
        }
    }

    int check = 1;
    while(!q.empty()){
        int r = q.front().first;
        int c = q.front().second;
        q.pop();

        for(int i=0; i<4; i++){
            int nr = r + dr[i];
            int nc = c + dc[i];

            if(nr < 0 || nc < 0 || nr >= 5 || nc >= 5 || visited[nr][nc]) continue;

            if(seat[nr][nc]==1){
                visited[nr][nc] = true;
                q.push({nr, nc});
                check++;
            }
        }
    }
    if(check==7){
        return true; //7명이 모두 인접해있다면
    }
    else return false;
}

bool isOverFour(){
    int cnt = 0;
    for(int i=0; i<25; i++) {
        if (selected[i]) {
            int r = i / 5;
            int c = i % 5;

            if(map[r][c] == 'S'){
                cnt++;
            }
        }
    }

    if(cnt>=4) return true;
    else return false;
}

void dfs(int idx, int cnt){
    if(cnt==7){
        if(isConnected()){ //bfs
            //이다솜파가 4명 이상이라면
            if(isOverFour()){
                ans++;
            }
        }
        return;
    }

    for(int i=idx; i<25; i++){ //조합
        if(selected[i]) continue;
        selected[i] = true;
        dfs(i, cnt+1);
        selected[i] = false;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    for (int i = 0; i < 5; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < 5; j++) {
            map[i][j] = s[j]; //이다솜파 S, 임도연파 Y
        }
    }

    //25명 중 7명의 조합을 뽑음 -> 7명이 가로, 세로로 인접 + 이다솜파가 4명 이상인지 확인
    dfs(0, 0);
    cout << ans;
}

