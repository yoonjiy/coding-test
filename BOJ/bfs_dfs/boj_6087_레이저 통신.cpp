// Created by strit on 2022-12-13. gold3 6087 레이저 통신 - bfs
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <cmath>
#include <tuple>
#define INF 987654321

using namespace std;

int h, w;
char map[101][101];
int visited[101][101];
pair<int, int> s, e;
//동 서 남 북
int dr[4] = {0, 0 ,1, -1};
int dc[4] = {1, -1, 0, 0};

int bfs(){
    queue<pair<pair<int, int>, pair<int, int>>> q; //r, c, 거울 갯수, 방향
    int r = s.first;
    int c = s.second;
    visited[r][c] = 0;

    for(int i=0; i<4; i++){
        q.push({{r, c}, {0, i}});
    }

    while(!q.empty()){
        int r = q.front().first.first;
        int c = q.front().first.second;
        int mirror = q.front().second.first;
        int dir = q.front().second.second;
        q.pop();

        for(int i=0; i<4; i++){
            int nr = r + dr[i];
            int nc = c + dc[i];

            int temp = mirror;

            if(nr < 0 || nc < 0 || nr >= h || nc >= w || map[nr][nc]=='*') continue;

            //이동하고자 하는 방향이 다르면 거울 설치가 필요
            if(dir!=i){
                temp++;
            }
            if(visited[nr][nc] >= temp){
                visited[nr][nc] = temp;
                q.push({{nr, nc},{temp, i}});
            }
        }
    }

    return visited[e.first][e.second];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> w >> h;
    int temp = 0;
    for(int i=0; i<h; i++){
        for(int j=0; j<w; j++){
            cin >> map[i][j]; //. 빈 칸, * 벽, C 레이저로 연결해야 하는 칸
            if(map[i][j]=='C'){
                if(temp==0){
                    s.first = i;
                    s.second = j;
                    temp++;
                }
                else{
                    e.first = i;
                    e.second = j;
                }
            }
            visited[i][j] = INF;
        }
    }

    cout << bfs();


}

