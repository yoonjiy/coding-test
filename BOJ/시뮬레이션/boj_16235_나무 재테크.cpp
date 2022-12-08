// Created by strit on 2022-10-18. gold3 16235 나무 재테크 - 시뮬레이션
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define INF 987654321

using namespace std;

int n, m, k;
int A[11][11];
int land[11][11];
int dead[11][11];
vector<int> v[11][11];
int dr[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dc[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

void spring(){
    //어린나무부터 나이만큼 양분을 먹고 나이가 1 증가, 못먹으면 죽음
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            sort(v[i][j].begin(), v[i][j].end());
            for(int k=0; k<v[i][j].size(); k++){
                if(land[i][j] >= v[i][j][k]) {
                    land[i][j] -= v[i][j][k];
                    v[i][j][k]++;
                }
                else{
                    dead[i][j] += v[i][j][k]/2;
                    v[i][j].erase(v[i][j].begin()+k);
                    k--;
                }
            }
        }
    }
}

void summer(){
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            land[i][j] += dead[i][j];
            dead[i][j] = 0;
        }
    }
}

void fall(){
    //5의 배수 나이인 나무가 인접 8개 칸에 번식, 나무의 나이는 1
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            for(int k=0; k<v[i][j].size(); k++){
                if(v[i][j][k]%5 != 0 || v[i][j][k]==0) continue;
                for(int idx=0; idx<8; idx++){
                    int nr = i + dr[idx];
                    int nc = j + dc[idx];
                    if(nr <= 0 || nc <= 0 || nr > n || nc > n ) continue;
                    v[nr][nc].push_back(1);
                }
            }
        }
    }
}

void winter(){
    //양분을 추가
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            land[i][j] += A[i][j];
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> k;

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            land[i][j] = 5;
            //양분 추가
            cin >> A[i][j];
        }
    }

    for(int i=0; i<m; i++){
        //나무의 위치, 나이
        int r, c, age;
        cin >> r >> c >> age;
        v[r][c].push_back(age);
    }

    //k년이 지난 후 살아 남은 나무의 수
    while(k--){
        //봄, 여름, 가을, 겨울
        spring();
        summer();
        fall();
        winter();
    }

    int ans = 0;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            ans += v[i][j].size();
        }
    }

    cout << ans;
}

