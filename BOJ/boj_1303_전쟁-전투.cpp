// Created by strit on 2022-02-05. silver1 1303 전쟁-전투 - dfs
#include <iostream>

using namespace::std;

int N, M;
char board[100][100];
bool visited[100][100];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int cnt;

void dfs(int x, int y){
    visited[x][y] = true;
    cnt++;
    for(int i=0; i<4; i++){
        int newy = y+dy[i];
        int newx = x+dx[i];
        if(newx>=0 && newx<M && newy>=0 && newy<N && board[x][y]==board[newx][newy] && !visited[newx][newy]){
            dfs(newx, newy);
        }
    }
}

int main() {
    int bcnt = 0, wcnt = 0;
    //아군 병사의 위력과 적군 병사의 위력의 합. N명이 모이면 N^2의 위력.
    cin >> N >> M;
    for(int i=0; i<M; i++){
        for(int j=0; j<N; j++){
            cin >> board[i][j];
        }
    }

    for(int i=0; i<M; i++){
        for(int j=0; j<N; j++){
            if(!visited[i][j]){
                cnt = 0;
                dfs(i, j);
                if(board[i][j]=='B')
                    bcnt += cnt*cnt;
                if(board[i][j]=='W')
                    wcnt += cnt*cnt;
            }
        }
    }

    cout << wcnt << " " << bcnt;

}




