// Created by strit on 2022-02-06. silver1 1743 음식물 피하기 - dfs
#include <iostream>
#include <vector>

using namespace::std;

int N, M, K;
int board[101][101];
bool visited[101][101];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int cnt;

void dfs(int x, int y){
    visited[x][y] = true;
    cnt++;
    for(int i=0; i<4; i++){
        int newy = y+dy[i];
        int newx = x+dx[i];
        if(newx>=1 && newx<=N && newy>=1 && newy<=M && board[x][y] && board[newx][newy] && !visited[newx][newy]){
            dfs(newx, newy);
        }
    }

}

int main() {
    //세로 길이, 가로 길이, 음식물 쓰레기 개수
    cin >> N >> M >> K;

    for(int i=0; i<K; i++){
        int a, b;
        cin >> a >> b;
        board[a][b] = 1;
    }

    int answer = -1000;
    for(int i=1; i<=N; i++){
        for(int j=1; j<=M; j++){
            if(!visited[i][j] && board[i][j]){
                cnt = 0;
                dfs(i, j);
                answer = max(cnt, answer);
            }
        }
    }

    cout << answer;
}

