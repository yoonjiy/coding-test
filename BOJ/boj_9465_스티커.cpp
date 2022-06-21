// Created by strit on 2022-06-21. silver1 9465 스티커 - dp
#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <cstring>

using namespace::std;

struct node{
    bool detachable;
    int value;
    int r, c;
};

int sticker[2][100000];
bool visited[2][100000] = {false, };
bool detachable[2][100000] = {true, };

int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

int sol(int width, int r, int c){
    queue<int> q;
    int sum;

    if(!visited[r][c]){
        q.push(sticker[r][c]);
        visited[r][c] = true;
    }

    while(!q.empty()){
        int v = q.front();
        q.pop();


        for(int i=0; i<4; i++){
            int nr = r + dx[i];
            int nc = c + dy[i];

            if(nr < 0 || nc < 0 || nr>=2 || nc>=width || visited[nr][nc]) continue;

            if(detachable[r][c]){
                sum += v;
                detachable[nr][nc] = false;
            }

            q.push(sticker[nr][nc]);
            visited[nr][nc] = true;
        }
    }

    return sum;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    for(int i=0; i<t; i++){
        int max = -1;

        int n;
        cin >> n;

        for(int i=0; i<2; i++){
            for(int j=0; j<n; j++){
                int value;
                cin >> value;
                sticker[i][j] = value;
            }
        }

        for(int i=0; i<2; i++) {
            for (int j = 0; j < n; j++) {
                memset(visited, false, sizeof(visited));
                memset(detachable, true, sizeof(detachable));

                if(max < sol(n, i, j))
                    max = sol(n, i, j);
            }
        }

        cout << max << "\n";
    }


}

