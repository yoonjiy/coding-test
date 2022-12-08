// Created by strit on 2022-01-31. silver1 1263 시간 관리 - 그리디
#include <iostream>
#include <vector>
#include <algorithm>

using namespace::std;

int main() {
    //걸리는 시간, 끝내야 하는 시간
    //마감시간 내 일을 모두 처리할 수 있는 범위 내에서 최대한 늦게 일을 시작할 수 있는 시간
    int N;
    cin >> N;
    vector<pair<int,int>> v(N);
    for(int i=0; i<N; i++){
        int a, b;
        cin >> a >> b;
        v.push_back({b, a});
    }

    //가장 늦게 끝나도 되는 일을 기준으로 내림차순 정렬
    sort(v.begin(), v.end(), greater<>());

    //20 5
    //16 1
    //14 8
    //5 3
    int diff;
    for(int i=0; i<N; i++){
        diff = v[i].first-v[i].second;
        if(i==N-1)
            break;
        if(diff < v[i+1].first)
            v[i+1].first = diff;
    }

    if(diff>=0)
        cout << diff;
    else
        cout << "-1";

}




