// Created by strit on 2022-01-30. silver1 1932 정수 삼각형 - 동적 계획법
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    // 정수 삼각형, 합이 최대가 되는 경로
    int n;
    int tri[502][502];
    int path[502][502];

    cin >> n; // 삼각형 크기
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            cin >> tri[i][j];
        }
    }

    path[1][1] = tri[1][1];

    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            path[i][j] = max(path[i - 1][j - 1], path[i - 1][j]) + tri[i][j];
        }
    }

    int m = 0;
    for (int i = 1; i <= n; i++) {
        m = max(m, path[n][i]);
    }

    cout << m;
}

