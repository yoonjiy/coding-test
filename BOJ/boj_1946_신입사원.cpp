// Created by strit on 2022-02-15. silver1 1946 신입 사원 - 그리디
#include <iostream>
#include <vector>
#include <algorithm>

using namespace::std;

int main() {
    //선발할 수 있는 신입사원의 최대 인원
    //서류 심사 순위,면접 순위
    int t, n, a, b, cnt;
    cin >> t;
    vector<pair<int, int>> v;
    int list[21];
    //서류 순위 기준으로 정렬한 후 비교
    for(int i=0; i<t; i++){
        cnt = 1;
        cin >> n;
        for(int j=0; j<n; j++){
            cin >> a >> b;
            v.push_back({a, b});
        }
        sort(v.begin(), v.end());
        //면접 순위까지 더 낮으면 탈락
        int max =  v[0].second;
        for(int k=1; k<n; k++){
            if(max >= v[k].second) {
                max = v[k].second;
                cnt++;
            }
        }
        list[i] = cnt;
        v.clear();
    }

    for(int i=0; i<t; i++){
        cout << list[i] << endl;
    }
}



