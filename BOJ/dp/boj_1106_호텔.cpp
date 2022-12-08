// Created by strit on 2022-01-22. boj silver1 1106 호텔 - dynamic programming
#include <iostream>
#include <vector>
#include <algorithm>

using namespace::std;

int dp[100001];

int main() {
    //홍보를 할 수 있는 도시, 도시를 홍보하는데 드는 비용, 몇 명의 고객이 늘어나는지.
    //정수배만큼 투자 가능.
    //호텔의 고객을 적어도 c명 늘리기 위해 투자해야 하는 최소 비용을 구하시오.
    int c, n;
    cin >> c >> n;
    vector<pair<int, int>> v(n);

    for(int i=0; i<n; i++) {
        int cost, customer;
        cin >> cost >> customer;
        v[i] = {cost, customer};
    }

    for(int i=1; i<=100000; i++) {
        for (int j = 0; j < n; j++) {
            if(i%v[j].first==0){
                dp[i] = max(dp[i], (i/v[j].first)*v[j].second);
            }
            if(i-v[j].first >= 0){
                dp[i] = max(dp[i], dp[i-v[j].first]+v[j].second);
            }
        }
        if(c<=dp[i]){
            cout << i; //최소 비용
            return 0;
        }
    }
}


