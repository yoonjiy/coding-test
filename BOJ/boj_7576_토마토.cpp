// Created by strit on 2022-02-07. silver1 7576 토마토 - bfs
#include <iostream>
#include <queue>
using namespace std;
int n, m, cnt;
int row, col;
queue<pair<int, int>> q;
int c[4] = {1, -1, 0, 0};
int r[4] = {0, 0, 1, -1};

int solution(int** box){
    //bfs. 익은 토마토는 큐에 넣기.
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(box[i][j]==1){
                q.push(make_pair(i, j));
            }
        }
    }
    while(!q.empty()){
        int nrow, ncol;
        row = q.front().first;
        col = q.front().second;
        q.pop();
        for(int i=0; i<4; i++){
            nrow = row + r[i];
            ncol = col + c[i];
            if(nrow<m && nrow>=0 && ncol<n && ncol>=0){
                if(box[nrow][ncol]==0){
                    box[nrow][ncol] = box[row][col] + 1;
                    q.push(make_pair(nrow, ncol));
                    cnt--;
                }
            }
        }
    }
    if(cnt == 0)
        return box[row][col]-1;
    else {
        return -1;
    }
}

int main() {
    cin >> n >> m;
    int** box = new int*[m];
    for(int i=0; i<m; i++){
        box[i] = new int[n];
    }

    int check = 0;
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            cin >> box[i][j];
            if(box[i][j]!=1)
                check = 1;
            if(box[i][j]==0)
                cnt++;
        }
    }

    if(!check)
        cout << 0;
    else
        cout << solution(box);

    return 0;
}

