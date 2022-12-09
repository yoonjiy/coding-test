// Created by strit on 2022-12-09. gold3 13904 과제 - 그리디
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <cmath>
#include <tuple>
#define INF 987654321

using namespace std;

int n;
int score[1001]; //해당 마감일에 수행한 과제 점수

bool compare(pair<int, int> v1, pair<int, int> v2){
    if(v1.second > v2.second) return true;
    else return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    vector<pair<int, int>> v;

    for(int i=0; i<n; i++){
        //마감일까지 남은 일수, 과제 점수
        int d, w;
        cin >> d >> w;
        v.push_back({d, w});
    }

    sort(v.begin(), v.end(), compare); //점수 내림차 순 정렬

    int ans = 0;
    for(int i=0; i<n; i++){
        for(int j=v[i].first; j>0; j--){
            if(score[j]==0){
                score[j] = v[i].second;
                ans += score[j];
                break;
            }
        }
    }

    cout << ans;
}

