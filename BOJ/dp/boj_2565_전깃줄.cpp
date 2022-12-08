// Created by strit on 2022-03-18. gold5 2565 전깃줄 - dp, 증가하는 수열
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace::std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n; //전깃줄의 개수
    cin >> n;
    int dp[500];
    vector<pair<int, int>> vec;

    for(int i=0; i<n; i++){
        int a, b;
        cin >> a >> b;
        vec.push_back({a, b});
    }

    sort(vec.begin(), vec.end());

    for(int i=0; i<n; i++){
        int cmp = vec[i].second;
        int cnt = 0;
        for(int j=0; j<i; j++){
            if(cmp < vec[j].second)
                continue;
            cnt = max(cnt, dp[j]);
        }
        dp[i] = cnt + 1;
    }

    int answer = 0;
    for(int i=0; i<n; i++){
        answer = max(answer, dp[i]);
    }

    cout << n - answer;

}

