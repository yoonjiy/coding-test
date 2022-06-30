// Created by strit on 2022-06-30. 2636 치즈 - bfs
#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#include <queue>
#include <cstring>

using namespace std;

char graph[101][101];
bool visited[101][101];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int n, m;
int result, t;

bool bfs() {
    visited[0][0] = true;
    int cnt=0;
    queue<pair<int, int>> q;
    q.push({ 0,0 });
    t++;
    while (!q.empty()) {
        int r = q.front().first;
        int c = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nr = r + dx[i];
            int nc = c + dy[i];
            if (nr >= 0 && nr < n && nc >= 0 && nc < m && !visited[nr][nc]) {
                //인접한 칸이 0이면 계속 탐색
                if (graph[nr][nc] == '0') {
                    q.push({ nr,nc });
                }
                    //인접한 칸이 치즈면 치즈를0으로 바꿔주고 카운팅
                else {
                    graph[nr][nc] = '0';
                    cnt++;
                }
                visited[nr][nc] = true;
            }
        }
    }

    //치즈가 없다면 시간과, 이전 bfs에서 나온 치즈의 개수를 출력한 후 false반환
    if (cnt == 0) {
        cout << --t <<'\n'<<result;
        return true;
    }
        //치즈가 있다면 결과(치즈의 개수) 갱신
    else {
        result = cnt;
        return false;
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> graph[i][j];
        }
    }
    //치즈가 없을 때까지
    while (true) {
        if (bfs())
            break;
        memset(visited, false, sizeof(visited));
    }

    return 0;
}

