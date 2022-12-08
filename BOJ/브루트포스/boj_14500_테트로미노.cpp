// Created by strit on 2022-03-15. gold5 14500 테트로미노 - dfs, 브루트포스
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace::std;

int n, m, sum;
int map[500][500];
int visited[500][500];
int answer = -987654321;
int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};

void dfs(int r, int c, int depth, int sum){
    if(depth==3){
        answer = max(answer, sum);
        return;
    }

    for(int i=0; i<4; i++){
        int nr = r + dx[i];
        int nc = c + dy[i];

        if(nr<0 || nr>=n || nc<0 || nc>=m || visited[nr][nc])
            continue;
        visited[nr][nc] = true;
        dfs(nr, nc, depth+1, sum+map[nr][nc]);
        visited[nr][nc] = false;
    }

}

void shape1(int r, int c){ //ㅗ
    int tmp = 0;
    tmp = map[r][c]  + map[r][c+1] + map[r][c+2] + map[r-1][c+1];
    answer = max(answer, tmp);
};

void shape2(int r, int c){ //ㅜ
    int tmp = 0;
    tmp = map[r][c] + map[r][c+1] + map[r][c+2] + map[r+1][c+1];
    answer = max(answer, tmp);

}

void shape3(int r, int c){ //ㅏ
    int tmp = 0;
    tmp = map[r][c] + map[r+1][c] + map[r+2][c] + map[r+1][c+1];
    answer = max(answer, tmp);
}

void shape4(int r, int c){ //ㅓ
    int tmp = 0;
    tmp = map[r][c] + map[r][c+1] + map[r-1][c+1] + map[r+1][c+1];
    answer = max(answer, tmp);
}

int main() {
    //테트로미노 최대값
    cin >> n >> m;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> map[i][j];
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            visited[i][j] = true;
            dfs(i, j, 0, map[i][j]);
            visited[i][j] = false;
            if (i - 1 >= 0 && j + 2 < m) shape1(i, j); //ㅗ
            if (j + 2 < m && i + 1 < n) shape2(i, j); //ㅜ
            if (i + 2 < n && j + 1 < m) shape3(i, j); //ㅏ
            if (i + 1 < n && i - 1 >= 0 && j + 1 < m) shape4(i, j); //ㅓ
        }
    }

    cout << answer;

}


