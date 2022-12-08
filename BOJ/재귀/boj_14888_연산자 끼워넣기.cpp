// Created by strit on 2022-08-31. silver1 14888 연산자 끼워넣기 - 백트래킹
#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#include <queue>
#include <cstring>

using namespace std;

int N;
int operands[11];
int operators[4];
int maxx=-987654321, minn=987654321;

void calculate(int ans, int idx){
    if (idx==N){
        if (ans > maxx)
            maxx = ans;
        if (ans < minn)
            minn = ans;
        return;
    }

    for(int i=0; i<4; i++) {
        if (operators[i] <= 0) continue;
        operators[i]--;
        if (i == 0) {
            calculate(ans + operands[idx], idx + 1);
        } else if (i == 1) {
            calculate(ans - operands[idx], idx + 1);
        } else if (i == 2) {
            calculate(ans * operands[idx], idx + 1);
        } else {
            calculate(ans / operands[idx], idx + 1);
        }
        operators[i]++;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    for(int i=0; i<N; i++){
        cin >> operands[i];
    }

    for(int i=0; i<4; i++){
        cin >> operators[i]; //덧셈, 뺄셈, 곱셈, 나눗셈
    }

    calculate(operands[0], 1);

    cout << maxx << "\n" << minn;
}

