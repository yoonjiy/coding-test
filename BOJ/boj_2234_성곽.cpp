// Created by strit on 2022-12-07.
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <cmath>
#include <stack>
#define INF 987654321

using namespace std;

int n, m;
int wall[51][51];
int visited[51][51];
int room_area[2600] = {0, };

int one, two, three;

//서 북 동 남
int dr[4] = {0, -1, 0, 1};
int dc[4] = {-1, 0, 1, 0};

int bfs(int r, int c){
    visited[r][c] = one;
    queue<pair<int, int>> q;
    q.push({r,c});

    int temp_area = 1;
    while(!q.empty()){
        int r = q.front().first;
        int c = q.front().second;
        q.pop();

        for(int i=0; i<4; i++){
            int nr = r + dr[i];
            int nc = c + dc[i];

            if(nr < 0 || nc < 0 || nr >= m || nc >= n || visited[nr][nc]) continue;

            //서 북 동 남 -> 1 2 4 8
            //r,c 에서 벽이 없고 방문 하지 않은 곳으로 이동
            if(((1<<i) & wall[r][c]) == 0){
                visited[nr][nc] = one;
                q.push({nr, nc});
                temp_area++;
            }
        }
    }
    return temp_area;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    //1. 이 성에 있는 방의 개수
    //2. 가장 넓은 방의 넓이
    cin >> n >> m;
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            cin >> wall[i][j];
        }
    }

    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(!visited[i][j]){
                one++;
                room_area[one] = bfs(i, j);
                if(room_area[one] > two)
                    two = room_area[one];
            }
        }
    }

    //3. 하나의 벽을 제거 하여 얻을 수 있는 가장 넓은 방의 크기
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            for(int k=0; k<4; k++){
                int nr = i + dr[k];
                int nc = j + dc[k];

                if(nr < 0 || nc < 0 || nr >= m || nc >= n) continue;

                //벽이 있고 다른 방이라면
                if((((1<<k) & wall[i][j])!=0) && (visited[i][j] != visited[nr][nc])){
                    three = max(three, room_area[visited[i][j]] + room_area[visited[nr][nc]]);
                }
            }
        }
    }

    cout << one << "\n" << two << "\n" << three;

}

