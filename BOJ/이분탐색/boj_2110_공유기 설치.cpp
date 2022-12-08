// Created by strit on 2022-03-17. gold5 2110 공유기 설치 - 이분탐색
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace::std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, c;

    cin >> n >> c;

    vector<int> house(n);
    for (int i=0; i < n; i++)
        cin >> house[i];

    sort(house.begin(), house.end()); //이분 탐색은 정렬 후 진행!

    int left = 1, right = house[n-1]-house[0]; //공유기 간격의 최소 거리, 최대 거리

    while (left <= right) {
        int cnt = 1;
        int loc = 0;
        int mid = (left + right) / 2;

        for (int i = 1; i < n; i++) {
            if (house[i] - house[loc] >= mid) { //이전에 공유기가 설치된 집과 다음 집의 간격이 기준 거리보다 같거나 크면 공유기 설치 가능
                loc = i; //공유기가 설치된 마지막 집 위치 갱신
                cnt++;
            }
        }
        if (cnt < c)
            right = mid - 1; //기준거리를 좁혀서 더 많이 설치할 필요 있음.
        else
            left = mid + 1; //기준거리를 늘여서 더 적게 설치할 필요 있음.

    }

    cout << right;
}

