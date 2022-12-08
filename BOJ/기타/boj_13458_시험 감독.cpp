// Created by strit on 2022-02-12. 13458 시험 감독
#include <iostream>

using namespace std;

int p[1000001];


int main() {
    //시험장 개수, 응시자 수, 총감독관이 감시할 수 있는 학생 수, 부감독관이 감시할 수 있는 학생 수
    int n, b, c;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> p[i]; //각 시험장 응시자 수
    cin >> b >> c;

    //최소 감독관 수
    long long total = 0;
    for (int i = 0; i < n; i++) {
        int rest = p[i] - b;
        total++;
        if (rest <= 0) continue;
        if (rest % c == 0)
            total += rest / c;
        else
            total += rest / c + 1;

    }

    cout << total;

    return 0;
}

