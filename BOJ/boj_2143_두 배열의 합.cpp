// Created by strit on 2022-10-27

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <cmath>
#define INF 987654321

using namespace std;

int t, n, m;
int a[1001], b[1001];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> t;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    cin >> m;
    for(int i=0; i<m; i++){
        cin >> b[i];
    }

    vector<int> av, bv;

    //a배열의 모든 부분합
    int sum;
    for(int i=0; i<n; i++){
        sum = 0;
        for(int j=i; j<n; j++){
            sum += a[j];
            av.push_back(sum);
        }
    }

    //b배열의 모든 부분합
    for(int i=0; i<m; i++){
        sum = 0;
        for(int j=i; j<m; j++){
            sum += b[j];
            bv.push_back(sum);
        }
    }

    sort(av.begin(), av.end());
    sort(bv.begin(), bv.end());

    long long ans = 0;
    for(auto value : av){
        int temp = t - value;
        long long upper_index = upper_bound(bv.begin(), bv.end(), temp) - bv.begin();
        long long lower_index = lower_bound(bv.begin(), bv.end(), temp) - bv.begin();
        ans += upper_index - lower_index;
    }

    cout << ans;
}
