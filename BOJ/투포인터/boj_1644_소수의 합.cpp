// Created by strit on 2022-09-22. gold3 1644 소수의 합 - 투포인터
#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
#include <math.h>
#define INF 987654321

using namespace std;

int n;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    vector<bool> isPrime(n+1, true);
    vector<int> primeNum;

    //에라토스테네스의 체
    isPrime[0] = isPrime[1] = false; //소수가 아님
    for(int i=2; i<=sqrt(n); i++){
        if(!isPrime[i])
            continue;
        for(int j=i+i; j<=n; j += i){
            isPrime[j] = false;
        }
    }

    for(int i=2; i<=n; i++){
        if(isPrime[i])
            primeNum.push_back(i);
    }

    int cnt = 0, low = 0, high = 0;
    int sum = 0;
    while(true){
        if(sum >= n){
            sum -= primeNum[low++];
        }
        else if(high>=primeNum.size()){
            break;
        }
        else{
            sum += primeNum[high++];
        }

        if(sum==n) cnt++;
    }

    cout << cnt;


}

