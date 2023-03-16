// Created by strit on 2022-09-23. gold3 2206 벽 부수고 이동하기 - bfs
#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
#include <math.h>
#define INF 987654321

using namespace std;

int n, m;
int map[1001][1001];
bool visited[1001][1001][2] = {false, }; //벽을 부수고 왔는지, 아닌지 체크
int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, 1, -1};

struct position{
    int r, c;
    int destroyed;
    int distance;
};

int bfs(){
    position p;
    p.r = p.c = 0;
    p.distance = 1;
    p.destroyed = 0;

    queue<position> q;
    q.push(p);

    visited[0][0][0] = true;

    while(!q.empty()) {
        position p = q.front();
        q.pop();

        if (p.r == n - 1 && p.c == m - 1) {
            return p.distance;
        }

        for (int i = 0; i < 4; i++) {
            int nr = p.r + dr[i];
            int nc = p.c + dc[i];

            if (nr < 0 || nc < 0 || nr >= n || nc >= m) continue;

            //벽이 있고, 안 부순 상태 -> 벽을 부수고 갈 수 있음
            if (map[nr][nc] && !p.destroyed) {
                visited[nr][nc][1] = true;
                q.push(position{nr, nc, 1, p.distance + 1});
            }

            //길이 있고, 방문 하지 않은 경우
            if (!map[nr][nc] && !visited[nr][nc][p.destroyed]) {
                visited[nr][nc][p.destroyed] = true;
                q.push(position{nr, nc, p.destroyed, p.distance + 1});
            }
        }
    }

    return -1;

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for(int i=0; i<n; i++){
        string s;
        cin >> s;
        for(int j=0; j<m; j++){
            map[i][j] = s[j] - '0';
        }
    }

    cout << bfs();

}

