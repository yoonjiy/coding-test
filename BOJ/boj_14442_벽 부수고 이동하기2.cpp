// Created by strit on 2022-12-02. gold3 14442 벽 부수고 이동하기 - bfs
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <cmath>
#include <stack>
#define INF 987654321

using namespace std;
int n, m, k;
int map[1001][1001];
bool visited[1001][1001][11]; //벽을 몇 번 부수고 왔는지
int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

struct position{
    int r, c;
    int destroy_cnt; //벽을 몇 번 부수고 왔는지
    int distance;
};

int bfs(){
    queue<position> q;
    position p;
    p.r = 0; p.c = 0; p.distance = 1; p.destroy_cnt = 0;
    visited[0][0][0] = true;
    q.push(p);

    while(!q.empty()){
        position p = q.front();
        if(p.r == n-1 && p.c == m-1){
            return p.distance;
        }
        q.pop();
        for(int i=0; i<4; i++){
            int nr = p.r + dr[i];
            int nc = p.c + dc[i];

            if(nr < 0 || nc < 0 || nr >= n || nc >= m || visited[nr][nc][p.destroy_cnt]) continue;

            //벽이 있고, 아직 k번 부수지 않았다면 벽을 부수고 이동
            if(map[nr][nc] && p.destroy_cnt < k){
                visited[nr][nc][p.destroy_cnt] = true;
                q.push({nr, nc, p.destroy_cnt+1, p.distance+1});
            }

            //길이 있고 방문하지 않은 경우, 길로 이동
            if(!map[nr][nc] && !visited[nr][nc][p.destroy_cnt]){
                visited[nr][nc][p.destroy_cnt] = true;
                q.push({nr, nc, p.destroy_cnt, p.distance+1});
            }
        }
    }

    return -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> k;
    for(int i=0; i<n; i++){
        string s;
        cin >> s;
        for(int j=0; j<m; j++){
            map[i][j] = s[j] - '0';
        }
    }

    cout << bfs();

}

