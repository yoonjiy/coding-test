// Created by strit on 2022-11-16. gold3 16637 괄호 추가하기 - dfs, 브루트포스
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
string s;
int ans = -987654321;

int calculate(int a, int b, char op){
    switch(op){
        case '+': a+=b; break;
        case '-': a-=b; break;
        case '*': a*=b; break;
    }
    return a;
}

void dfs(int idx, int curr){
    //종료 조건
    if(idx>=n){
        ans = max(ans, curr);
        return;
    }

    char op = idx == 0 ? '+' : s[idx-1];

    //괄호를 묶는 경우
    if(idx+2 < n){
        int temp = calculate(s[idx]-'0', s[idx+2]-'0', s[idx+1]);
        dfs(idx+4, calculate(curr, temp, op));
    }

    //괄호를 안묶는 경우
    dfs(idx+2, calculate(curr, s[idx]-'0', op));

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    //괄호를 적절히 추가해 얻을 수 있는 식의 최대값
    cin >> n >> s;

    dfs(0, 0);

    cout << ans;
}

