// Created by strit on 2022-10-12. gold5 7579 앱 - dp
#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
#include <math.h>
#define INF 987654321

using namespace std;

int n, m;
int memory[101];
int cost[101];
int dp[10001]; //해당 비활성화 비용으로 확보 가능한 최대 메모리값

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for(int i=0; i<n; i++){
        cin >> memory[i]; //바이트 수 저장
    }
    for(int i=0; i<n; i++){
        cin >> cost[i]; //비활성화할 경우의 비용
    }

    for(int i=0; i<n; i++){
        for(int j=100*100; j>=cost[i]; j--){
            dp[j] = max(dp[j], dp[j-cost[i]]+memory[i]);
        }
    }

    for(int i=0; i<100*100+1; i++){
        if(dp[i]>=m){
            cout << i;
            break;
        }
    }

}

