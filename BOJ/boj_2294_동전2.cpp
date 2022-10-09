#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
#include <math.h>
#define INF 987654321

using namespace std;

int n, k;
int dp[10001];
int coin[101];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    //가치의 합이 k원이 되게 하는 동전의 최소 개수
    cin >> n >> k;
    for(int i=0; i<n; i++){
        cin >> coin[i];
    }

    for(int i=1; i<=k; i++){
        dp[i] = INF;
    }

    //dp[i] = i의 가치를 만들 수 있는 동전의 최소 개수
    for(int i=0; i<n; i++){
        for(int j=coin[i]; j<=k; j++){
            dp[j] = min(dp[j], dp[j-coin[i]]+1);
        }
    }

    if(dp[k]==INF)
        cout << "-1";
    else cout << dp[k];
}
