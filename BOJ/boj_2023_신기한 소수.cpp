// Created by strit on 2022-02-27. gold5 2023 신기한 소수 - dfs
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace::std;

int n;

bool check(int num){
    //소수인지 판별
    if(num==0 || num==1)
        return false;
    for(int i=2; i<num; i++){
        if(num%i==0)
            return false;
    }
    return true;
}

void solve(int s, int depth){
    if(depth==n){
        cout << s << endl;
        return;
    }

    for(int i=1; i<=9; i+=2){ // 홀수만
        if(check(s*10+i))
            solve(s*10+i, depth+1);
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    solve(2, 1);
    solve(3, 1);
    solve(5, 1);
    solve(7, 1);

}



