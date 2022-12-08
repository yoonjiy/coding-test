// Created by strit on 2022-03-13. gold5 3190 뱀 - 시뮬레이션
#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
using namespace::std;

int n, k;
int map[101][101];
bool visited[101][101];

//오 왼 아래 위
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

int turn_dir(int d, char c){
    if(c=='L'){ //왼쪽으로 90도 회전
        if(d==0) return 3;
        else if(d==1) return 2;
        else if(d==2) return 0;
        else return 1;
    }
    else if(c=='D'){ //오른쪽으로 90도 회전
        if(d==0) return 2;
        else if(d==1) return 3;
        else if(d==2) return 1;
        else return 0;
    }
}

int main() {
    cin >> n >> k;
    for(int i=0; i<k; i++){
        int r, c;
        cin >> r >> c;
        map[r-1][c-1] = 1; //사과 있음.
    }

    int l; //뱀의 방향 전환 횟수
    cin >> l;
    //x초가 끝난 후 L 왼쪽 또는 D 오른쪽으로 90도 회전
    deque<pair<int, char>> v;
    for(int i=0; i<l; i++){
        int x; char c;
        cin >> x >> c;
        v.push_back({x, c});
    }

    deque<pair<int, int>> deq;
    int x = 0, y = 0, d = 0;
    deq.push_back({x, y});
    visited[x][y] = true; //뱀이 방문
    int answer = 0;

    //d=0 오른쪽 d=1 왼쪽 d=2 아래쪽 d=3 위쪽
    while(true){
        int nx = x + dx[d];
        int ny = y + dy[d];
        answer++;

        if(nx<0 || ny<0 || nx>=n || ny>=n || visited[nx][ny]) //벽 또는 자기 자신의 몸과 부딪히면 종료
            break;
        else if(map[nx][ny]==0) { //사과가 없는 경우 꼬리를 비움
            visited[deq.back().first][deq.back().second] = false; //꼬리 비움
            deq.pop_back(); //꼬리 비움
            deq.push_front({nx, ny}); //뱀 머리 이동
            visited[nx][ny] = true;
        }
        else { //사과가 있는 경우 사과 없어지고 머리만 이동
            map[nx][ny] = 0; //사과 먹음
            visited[nx][ny] = true;
            deq.push_front({nx, ny});
        }

        if(!v.empty()){
            if(answer==v.front().first){
                d = turn_dir(d, v.front().second);
                v.pop_front();
            }
        }

        x = nx;
        y = ny;

    }

    cout << answer;

}


