// Created by strit on 2022-02-01. silver1 2156 포도주 시식 - 동적 계획법
#include <iostream>
#include <algorithm>

using namespace std;

int juice[10001];
int max[10001];

int main() {
    int n;//포도주 잔
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> juice[i];

    max[0] = 0;
    max[1] = juice[1];
    max[2] = max[1] + juice[2];

    for (int i = 3; i <= n; i++) {
        max[i] = max(max[i - 3] + juice[i - 1] + juice[i], max[i - 2] + juice[i]);
        max[i] = max(max[i], max[i - 1]);
    }

    cout << max[n];

}
