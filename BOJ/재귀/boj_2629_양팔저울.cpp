// Created by strit on 2022-11-22. gold3 2629 양팔저울 - dp, 재귀
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <cmath>
#include <stack>
#define INF 987654321

using namespace std;

int n, m;
bool dp[31][15001]; //i번째까지 추를 올렸을 때, j의 무게를 만들 수 있는지
int weight[31];

void solve(int cnt, int w){
    if(cnt > n || dp[cnt][w]) return;
    dp[cnt][w] = true;

    solve(cnt+1, w+weight[cnt]);
    solve(cnt+1, w); //추를 안올리는 경우
    solve(cnt+1, abs(w-weight[cnt])); //구슬이 있는 쪽에 올리는 경우
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for(int i=0; i<n; i++){
        cin >> weight[i];//추의 무게
    }

    solve(0, 0);

    cin >> m;
    for(int i=0; i<m; i++){
        //확인하고자 하는 구슬의 무게
        int temp;
        cin >> temp; //구슬의 무게가 확인 가능하면 Y, 불가능하면 N

        if(temp > 15000) cout << "N ";
        else if(dp[n][temp]) cout << "Y ";
        else cout << "N ";
    }


}

