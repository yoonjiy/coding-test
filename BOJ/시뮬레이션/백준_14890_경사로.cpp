// Created by strit on 2022-09-15. gold3 14890 경사로 - 구현
#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#define INF 987654321

using namespace std;

int n, l;
int board[200][100];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> l;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> board[i][j];
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            board[i+n][j] = board[j][i]; //트랜스포즈 행렬 저장 -> 행과 열을 한번에 확인
        }
    }

    int i, j, c, ans = 0; //c 조건을 확인하여 연속된 타일이 l 이상인지 체크함.
    for(i=0; i<2*n; i++){
        c = 1;
        for(j=0; j<n-1; j++){
            if(board[i][j] == board[i][j+1]) c++; //같은 높이인 경우 연속된 타일의 개수 증가
            else if(board[i][j]+1 == board[i][j+1] && c >= l){ //낮은->높은인 경우 연속된 타일이 l 이상이어야 경사로를 놓을 수 있음
                c = 1;//연속된 타일 수 갱신
            }
            else if(board[i][j] == board[i][j+1] + 1 && c >= 0) {
                //높은->낮은인 경우 경사로가 놓인 자리를 반영해줌 -> c+l 자리가 1로 다시 시작하도록
                c = -l + 1;
            }
            else break;
        }

        if(j == n-1 && c >= 0){
            ans++;
        }
    }

    cout << ans;
}

