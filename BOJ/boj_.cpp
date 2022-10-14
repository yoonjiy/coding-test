// Created by strit on 2022-10-14.
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#include <math.h>
#define INF 987654321

using namespace std;

int n, m, d;
int origin_board[16][16];
int board[16][16];
bool visited[16];
int enemy_cnt, kill, ans;
pair<int, int> origin_enemy[300];
pair<int, int> enemy[300];
bool isDie[300];

struct e_info{
    int distance;
    int col;
    int idx;
};

bool compare(e_info e1, e_info e2){
    if(e1.distance == e2.distance){
        return e1.col < e2.col;
    }
    return e1.distance < e2.distance;
}

bool isFinished(){
    for(int i=0; i<enemy_cnt; i++){
        if(!isDie[i]){
            return false;
        }
    }
    return true;
}

void attack(){
    vector<int> killed_enemy;
    for(int i=0; i<m; i++){
        if(visited[i]){ //n행, i열에 위치
            //사정거리에 있고, 가장 가까운 거리부터, 거리가 같으면 왼쪽부터
            vector<e_info> v;
            for(int j=0; j<enemy_cnt; j++){
                if(isDie[j]) continue;
                int dist = abs(enemy[j].first - n) + abs(enemy[j].second - i);
                if(dist > d) continue;
                v.push_back({dist, enemy[j].second, j});
            }

            sort(v.begin(), v.end(), compare);

            killed_enemy.push_back(v[0].idx);
        }
    }

    for(int i=0; i<killed_enemy.size(); i++){
        if(isDie[killed_enemy[i]]) continue;
        isDie[killed_enemy[i]] = true;
        kill++;
    }
}

void move(){
    for(int i=0; i<enemy_cnt; i++){
        if(isDie[i]) continue;
        int row = enemy[i].first;
        row++;

        if(row==n){
            isDie[i] = true;
        }else{
            enemy[i].first = row;
        }
    }
}

void copy_board(){
    kill = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            board[i][j] = origin_board[i][j]; //보드 초기화
        }
    }

    for(int i=0; i<enemy_cnt; i++){
        enemy[i] = origin_enemy[i]; //적 초기화
    }

    memset(isDie, false, sizeof(isDie));
}

void make_combination(int cnt, int index){ //3명의 궁수 조합 백트래킹
    if(cnt==3){
        copy_board();
        while(!isFinished()){
            attack();
            move();
        }
        ans = max(ans, kill); //공격으로 제거할 수 있는 적의 최대 수
        return;
    }

    //n 행에 궁수 3명
    for(int i=index; i<m; i++){
        if(visited[i]) continue;
        visited[i] = true;
        make_combination(cnt+1, i);
        visited[i] = false;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> d;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> origin_board[i][j];
            if(origin_board[i][j]==1){
                //적이 있음
                origin_enemy[enemy_cnt++] = {i, j};
            }
        }
    }

    make_combination(0, 0);

    cout << ans;
}

