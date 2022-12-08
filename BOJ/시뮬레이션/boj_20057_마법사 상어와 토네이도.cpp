// Created by strit on 2022-11-30. gold3 20057 마법사 상어와 토네이도 - 시뮬레이션
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <cmath>
#include <stack>
#define INF 987654321

using namespace std;

int n;
int sand[500][500];
int ans;

//서 -> 남 -> 동 -> 북
int dr[4] = {0, 1, 0, -1};
int dc[4] = {-1, 0, 1, 0};

//{x, y} 기준 서 -> 남 -> 동 -> 북
int spreadR[4][10] = {
        {-1, 1, -1, 1, -1, 1, -2, 2, 0, 0},
        {0, 0, 1, 1, 2, 2, 1, 1, 3, 2},
        {-1, 1, -1, 1, -1, 1, -2, 2, 0, 0},
        {0, 0, -1, -1, -2, -2, -1, -1, -3, -2}

};
int spreadC[4][10] = {
        {0, 0, -1, -1, -2, -2, -1, -1, -3, -2},
        {-1, 1, -1, 1, -1, 1, -2, 2, 0, 0},
        {0, 0, 1, 1, 2, 2, 1, 1, 3, 2},
        {-1, 1, -1, 1, -1, 1, -2, 2, 0, 0}
};
int sand_percent[9] = { 1, 1, 7, 7, 10, 10, 2, 2, 5 };

void spread_sand(int r, int c, int dir){
    int nr = r + dr[dir];
    int nc = c + dc[dir];

    int curr_sand = sand[nr][nc];

    for(int i=0; i<9; i++){
        int nnr = r + spreadR[dir][i];
        int nnc = c + spreadC[dir][i];
        int percent = sand_percent[i];
        int plus_sand = (curr_sand*percent)/100;

        //격자 밖으로 나가는 모래들
        if(nnr<1 || nnc<1 || nnr>n || nnc>n){
            ans += plus_sand;
        }
        else{
            sand[nnr][nnc] += plus_sand;
        }

        sand[nr][nc] -= plus_sand;
    }

    //a 계산
    int nextr = r + spreadR[dir][9];
    int nextc = c + spreadC[dir][9];
    if(nextr<1 || nextc<1 || nextr>n || nextc>n){
        ans += sand[nr][nc]; //남은 모래 더해줌
    }
    else{
        sand[nextr][nextc] += sand[nr][nc];
    }
    sand[nr][nc] = 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin >> sand[i][j];
        }
    }

    int r = (n+1)/2;
    int c = (n+1)/2;
    int dir = 0;
    int move_cnt = 1;

    while(1){
        //2번씩 이동한 후 move_cnt 증가
        for(int i=0; i<2; i++){
            for(int j=0; j<move_cnt; j++){
                spread_sand(r, c, dir);
                r += dr[dir];
                c += dc[dir];
            }
            dir = (dir+1)%4;
        }

        move_cnt++;

        //마지막 줄 (1,1) 까지 이동 후 소멸
        if(move_cnt==n){
            for(int i=0; i<move_cnt-1; i++){
                spread_sand(r, c, dir);
                r += dr[dir];
                c += dc[dir];
            }
            break;
        }
    }
    cout << ans;
}




