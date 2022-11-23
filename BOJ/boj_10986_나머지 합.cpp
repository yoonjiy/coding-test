// Created by strit on 2022-11-23. gold3 10986 나머지 합
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
long long sum;
int cnt[1001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    int temp;
    for (int i = 0; i < n; i++) {
        cin >> temp;
        sum += temp;
        cnt[sum % m]++;
    }

    long long result = cnt[0];
    //nC2
    for(int i=0; i<m; i++){
        result += (long long)cnt[i]*(cnt[i]-1) / 2;
    }

    cout << result;

}







