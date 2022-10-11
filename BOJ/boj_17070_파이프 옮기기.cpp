// Created by strit on 2022-10-10. gold5 17070 파이프 옮기기 1 - dfs
#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
#include <math.h>
#define INF 987654321

using namespace std;

int n;
int house[17][17];
int dr[3] = {0, 1, 1};
int dc[3] = {1, 0, 1}; //가로, 세로, 대각선
int ans = 0;

void dfs(int r, int c, int dir){
    if(r==n && c==n){
        ans++;
        return;
    }
    for(int i=0; i<3; i++){
        if((dir==1 && i==0) || (dir==0 && i==1)) continue; //세로->가로, 가로->세로 이동 못 함.

        int nr = r + dr[i];
        int nc = c + dc[i];

        if(nr<1 || nc<1 || nr>n || nc>n || house[nr][nc]) continue;

        //대각선 이동 시 벽 고려
        if(i==2 && (house[nr-1][nc] || house[nr][nc-1])) continue;

        dfs(nr, nc, i);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin >> house[i][j];
        }
    }

    dfs(1, 2, 0); // dir 0: 가로, 1: 세로, 2: 대각선
    cout << ans;

}
