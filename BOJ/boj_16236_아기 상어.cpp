// Created by strit on 2022-04-01. gold3 16236 아기 상어 - bfs
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace::std;

int n;
int map[21][21];
int check[21][21];
int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};
vector<pair<int, pair<int, int>>> eat_fish;
int r, c;
int bs = 2;

void bfs(int y, int x, int bs){ //bs 아기 상어 크기
    memset(check, -1, sizeof(check));
    eat_fish.clear();
    queue<pair<int,int>> q;
    q.push({y,x});
    check[y][x] = 0;

    while(!q.empty()){
        y = q.front().first;
        x = q.front().second;
        q.pop();

        for(int i=0; i<4; i++){
            int nr = y + dy[i];
            int nc = x + dx[i];

            if(nr < 0 || nr >= n || nc < 0 || nc >= n || check[nr][nc]!=-1 || map[nr][nc] > bs) continue;

            if(map[nr][nc]==0 || map[nr][nc]==bs){ //지나갈 수 있음
                check[nr][nc] = check[y][x] + 1; //아기 상어로부터 얼마나 멀리 떨어졌는지 기록
                q.push({nr, nc});
            }

            if(map[nr][nc]<bs && map[nr][nc]>=1){ //잡아 먹고, 지나갈 수 있음
                check[nr][nc] = check[y][x] + 1;
                eat_fish.push_back( {check[nr][nc],{nr, nc}});
                q.push({nr, nc});
            }
        }
    }


}

int main() {

    int count = 0, answer=0;

    cin >> n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> map[i][j];
            if(map[i][j]==9){
                map[i][j] = 0; //크기를 9로 인식해서 아기상어가 해당 위치를 못지나갈 수 있으므로 0으로 초기화
                r = i;
                c = j;
            }
        }
    }

    while(true){

        bfs(r, c, bs);

        if(eat_fish.empty())
            break;

        //1. 가장 가까운 2. 가장 위에 있는(y좌표가 작은) 3. 가장 왼쪽에 있는(x좌표가 작은)
        sort(eat_fish.begin(), eat_fish.end());
        count++; // 아기 상어가 먹은 물고기 수
        answer += eat_fish[0].first; //아기 상어가 물고기를 먹으러 몇 초 이동했는지
        r = eat_fish[0].second.first;
        c = eat_fish[0].second.second; //아기 상어 위치 갱신
        map[r][c] = 0; //아기상어가 잡아먹어서 0이 됨

        if(bs == count){
            bs++; //아기 상어 크기 증가
            count = 0;
        }
    }

    cout << answer;
}

