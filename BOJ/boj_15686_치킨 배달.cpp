// Created by strit on 2022-03-07. gold5 15686 치킨 배달 - dfs, 조합
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace::std;
#define MAX 51

int n, m, answer=987654321;
int city[MAX][MAX];
vector<pair<int, int>> res, house, selected;
bool check[13];

int calculate_distance(){
    //selected와 house 간에 치킨 거리의 합
    int sum = 0;
    for(int i=0; i<house.size(); i++){
        int x1 = house[i].first;
        int y1 = house[i].second;
        int m = 987654321;
        for(int j=0; j<selected.size(); j++){
            int x2 = selected[j].first;
            int y2 = selected[j].second;
            int diff = abs(x1-x2) + abs(y1-y2);
            m = min(m, diff);
        }
        sum += m;
    }

    return sum;
}

void dfs(int idx, int depth){
    if(depth==m){
        //거리 비교해서 최솟값이면 answer
        answer = min(answer, calculate_distance());
        return;
    }
    for(int i=idx; i<res.size(); i++){
        if (check[i]) continue;
        check[i] = true;
        selected.push_back(res[i]);
        dfs(i, depth+1);
        check[i] = false;
        selected.pop_back();
    }

}

int main() {
    // 폐업시키지 않을 치킨집을 최대 M개를 골랐을 때, 도시의 치킨 거리의 최솟값을 출력

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin >> city[i][j];
        }
    }

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(city[i][j]==2)
                res.push_back({i, j}); //치킨 집 위치
            else if(city[i][j]==1)
                house.push_back({i, j}); //집 위치
        }
    }

    dfs(0, 0);

    cout << answer;
}


