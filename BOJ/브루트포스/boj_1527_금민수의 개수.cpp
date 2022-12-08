// Created by strit on 2022-02-16. silver1 1527 금민수의 개수 - 브루트 포스 & 재귀
#include <iostream>
#include <vector>
#include <algorithm>

using namespace::std;

long long a, b;
int cnt;

void solve(long long num){
    if(num > b)
        return;
    else if(a <= num && num <= b){
        cnt++;
    }
    solve(num * 10 + 4);
    solve(num * 10 + 7);
}

int main() {
    //금민수 - 4와 7로만 이루어진 수
    //a이상 b이하의 수 중 금민수의 개수를 구해라.
    cin >> a >> b;

    solve(4);
    solve(7);

    cout << cnt;
}

