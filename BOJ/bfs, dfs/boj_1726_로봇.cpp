// Created by strit on 2022-12-12. gold3 1726 로봇 - bfs
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <cmath>
#include <tuple>
#define INF 987654321

using namespace std;

int m, n;
int map[101][101];
bool visited[101][101][5];

//출발 지점
int start_r, start_c, start_dir;
//도착 지점
int des_r, des_c, des_dir;

int dr[5] = {0 , 0, 0, 1, -1};
int dc[5] = {0, 1, -1, 0, 0};

int change_dir(int d, char c){
    if (c == 'L')
    {
        if (d == 1) return 4;
        else if (d == 2) return 3;
        else if (d == 3) return 1;
        else if (d == 4) return 2;
    }
    else if (c == 'R')
    {
        if (d == 1) return 3;
        else if (d == 2) return 4;
        else if (d == 3) return 2;
        else if (d == 4) return 1;
    }
}

void bfs(int start_r, int start_c, int start_dir) {
    visited[start_r][start_c][start_dir] = true;
    //r, c, dir, cnt
    queue<tuple<int, int, int, int>> q;
    q.push({start_r, start_c, start_dir, 0});

    while (!q.empty()) {
        int r = get<0>(q.front());
        int c = get<1>(q.front());
        int dir = get<2>(q.front());
        int cnt = get<3>(q.front());
        q.pop();

        if (r == des_r && c == des_c && dir == des_dir) {
            cout << cnt;
            return;
        }

        //go 1,2,3 명령
        for (int i = 1; i <= 3; i++) {
            int nr = r + dr[dir] * i;
            int nc = c + dc[dir] * i;

            if (nr < 1 || nc < 1 || nr > m || nc > n || visited[nr][nc][dir]) continue;

            if (map[nr][nc] == 0) {
                visited[nr][nc][dir] = true;
                q.push({nr, nc, dir, cnt + 1});
            }
            else break; //1로 막혀서 지나갈 수 없음
        }

        //동 서 남 북 1 2 3 4
        //turn right
        int ndir = change_dir(dir, 'R');
        if (!visited[r][c][ndir]) {
            visited[r][c][ndir] = true;
            q.push({r, c, ndir, cnt + 1});
        }
        //turn left
        ndir = change_dir(dir, 'L');
        if (!visited[r][c][ndir]) {
            visited[r][c][ndir] = true;
            q.push({r, c, ndir, cnt + 1});
        }

    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    // 로봇을 원하는 위치로 이동시키고, 원하는 방향으로 바라보도록 하는데 최소 몇 번의 명령이 필요한지
    cin >> m >> n;
    for(int i=1; i<=m; i++){
        for(int j=1; j<=n; j++){
            cin >> map[i][j]; //0은 로봇이 갈 수 있는 지점이고, 1은 로봇이 갈 수 없는 지점
        }
    }

    //동 서 남 북 1 2 3 4
    cin >> start_r >> start_c >> start_dir;
    cin >> des_r >> des_c >> des_dir;

    bfs(start_r, start_c, start_dir);

}

