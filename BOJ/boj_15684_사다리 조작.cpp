// Created by strit on 2022-10-06. gold3 15684 사다리 조작 - dfs
#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
#include <math.h>
#define INF 987654321

using namespace std;

int n, m, h;
int ans = INF;
int ladder[31][11];

bool check(){
    for(int i=1; i<=n; i++){
        int col = i;
        for(int j=1; j<=h; j++){
            if(col+1 <= n && ladder[j][col]){ //오른쪽으로 이동
                col++;
            }
            else if(col-1 >= 1 && ladder[j][col-1]){ //왼쪽으로 이동
                col--;
            }

            //go down
        }

        if(col != i){
            return false;
        }
    }
    return true;
}

void dfs(int curr_depth, int max_depth){
    if(curr_depth == max_depth){
        if(check()){
            ans = curr_depth;
        }
        return;
    }

    for(int i=1; i<=h; i++){
        for(int j=1; j<n; ++j){
            //가로선이 서로 연속될 수 없음
            if(ladder[i][j] || ladder[i][j-1] || ladder[i][j+1]) continue;

            ladder[i][j] = 1;
            dfs(curr_depth+1, max_depth);
            ladder[i][j] = 0;
        }
    }

    return;

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> h;
    for(int i=0; i<m; i++){
        int a, b;
        cin >> a >> b; //b번 세로선과 b+1 세로선을 a 가로선에서 연결함
        ladder[a][b] = 1; //사다리가 연결되어있음.
    }

    for(int i=0; i<4; i++){
        dfs(0, i);

        if(ans!=INF){
            cout << ans;
            return 0;
        }
    }

    cout << "-1";
    return 0;

}

