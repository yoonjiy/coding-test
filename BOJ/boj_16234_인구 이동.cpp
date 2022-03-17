// Created by strit on 2022-03-17. gold5 16234 인구 이동 - bfs
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace::std;
int n, l, r; //l이상 r이하면 국경이 열림. 인구 이동 가능 -> 연합
int A[50][50] = {0, };
bool visited[50][50];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> l >> r;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> A[i][j];
        }
    }
    int answer = 0;

    while(true){
        bool check = false;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if(!visited[i][j]){
                    queue<pair<int, int>> q;
                    queue<pair<int, int>> loc; // 연합국에 포함될 수 있는 나라
                    visited[i][j] = true;
                    q.push({i, j});
                    loc.push({i, j});

                    int sum = 0;
                    int cnt = 0;

                    while(!q.empty()){
                        int y = q.front().first;
                        int x = q.front().second;
                        q.pop();

                        visited[y][x] = true;
                        sum += A[y][x];
                        cnt++;

                        for(int i=0; i<4; i++){
                            int ny = y + dy[i];
                            int nx = x + dx[i];

                            int diff = abs(A[ny][nx] - A[y][x]);

                            if(ny<0 || ny>=n || nx<0 || nx>=n || visited[ny][nx])
                                continue;

                            if(!visited[ny][nx] && diff >= l && diff <= r){
                                q.push({ny, nx});
                                loc.push({ny, nx});
                                visited[ny][nx] = true;
                                check = true;
                            }
                        }
                    }

                    int newPopulation = sum / cnt;
                    while(!loc.empty()){
                        int y = loc.front().first;
                        int x = loc.front().second;
                        loc.pop();

                        A[y][x] = newPopulation; //인구 갱신
                    }
                }
            }
        }
        if(!check){
            break;
        }
        else{
            answer++;
            memset(visited, false, sizeof(visited));
        }
    }

    cout << answer;

}

