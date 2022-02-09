// Created by strit on 2022-02-09. silver1 9461 파도반 수열 - 동적 계획법
#include <iostream>

using namespace std;

long long arr[100];

int main() {
    //파도반 수열
    //1 1 1 2 2 3 4 5 7 9 12 16 21 28
    //1 1 1 1+1 1+1 1+2 1+3 4+1 5+2 7+2 9+3 12+4 16+5 21+7

    int t, n;
    cin >> t;
    arr[0] = arr[1] = arr[2] = 1;

    for (int i = 0; i < t; i++) {
        cin >> n;

        for (int i = 3; i < n; i++) {
            arr[i] = arr[i - 3] + arr[i - 2];
        }

        cout << arr[n - 1] << "\n";

    }

}

