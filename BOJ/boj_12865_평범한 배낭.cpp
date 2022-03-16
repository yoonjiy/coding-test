// Created by strit on 2022-03-16. gold5 12865 평범한 배낭 - dp
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace::std;

int main() {
    //배낭에 넣을 수 있는 물건들의 가치의 최대값
    int dp[101][100001] = {0, }; //i번째 물건까지, j 무게만큼의 최대 가치합
    int n, k; //물품의 수, 버틸 수 있는 무게
    cin >> n >> k;
    vector<pair<int, int>> vec;
    for(int i=0; i<n; i++){
        int w, v;
        cin >> w >> v;
        vec.push_back({w, v});
    }

    int answer = -987654321;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=k; j++){
            if(vec[i-1].first <= j){
                dp[i][j] = max(dp[i-1][j-vec[i-1].first] + vec[i-1].second, dp[i-1][j]);
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
            answer = max(answer, dp[i][j]);
        }
    }

    cout << answer;

}


