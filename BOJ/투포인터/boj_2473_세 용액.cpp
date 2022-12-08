// Created by strit on 2022-11-24. gold3 2473 세 용액 - 투포인터
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <cmath>
#include <stack>
#define INF 987654321

using namespace std;

int n;
long long liquid[5001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for(int i=0; i<n; i++){
        cin >> liquid[i]; //3개를 혼합해서 0에 가장 가깝게 만들어내는
    }

    sort(liquid, liquid+n);

    long long result = 3000000001;
    int ans[3];

    for(int i=0; i<n-2; i++){
        int l = i+1;
        int r = n-1;
        while(l<r){
            long long total = liquid[i] + liquid[l] + liquid[r];
            if(abs(total) < result){
                result = abs(total);
                ans[0] = liquid[i];
                ans[1] = liquid[l];
                ans[2] = liquid[r];
            }
            if(total < 0) l++;
            else r--;
        }
    }

    for(int i=0; i<3; i++){
        cout << ans[i] << " ";
    }
}

