// Created by strit on 2022-03-12. gold5 14503 로봇 청소기 - 시뮬레이션
#include <iostream>
using namespace::std;

int n, m;
int r, c, d;
int map[50][50];
bool visited[50][50];
//북 동 남 서
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

void turn_left(){
    //북 0 동 1 남 2 서 3
    if(d==0)
        d = 3;
    else
        d = d-1;
}

int main() {
    //청소하는 영역의 개수를 구하여라
    cin >> n >> m;
    cin >> r >> c >> d;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> map[i][j]; //1이면 벽
        }
    }

    visited[r][c] = true;
    int sum = 1;
    int turn_cnt = 0;

    int nx, ny;
    while(true){
        bool check = false;
        for(int i=0; i<4; i++){
            turn_left();
            nx = r + dx[d];
            ny = c + dy[d];

            if(map[nx][ny]==0 && !visited[nx][ny]){
                check = true;
                r = nx;
                c = ny;
                visited[r][c] = true;
                sum++;
                break; //네 방향을 모두 탐색하기 전에 청소하러 감.
            }
        }

        if(!check){
            nx = r - dx[d];
            ny = c - dy[d];
            if(map[nx][ny]==1) break;

            r = nx;
            c = ny;
        }

    }

    cout << sum;
}



