// Created by strit on 2022-02-18. gold5 1107 리모컨 - 브루트포스
#include <iostream>
#include <vector>
#include <algorithm>

using namespace::std;

bool broken[10];

bool possible(string sn){
    for(int i=0; i<sn.length(); i++){
        int num = sn[i]-'0';
        if(broken[num]){
            return false;
        }
    }
    return true;
}

int solve(int n){
    int answer = abs(n-100);
    for(int i=0; i<=1000000; i++){
        string sn = to_string(i);
        if(possible(sn)){
            //버튼을 누른 횟수
            int cnt = sn.length();
            cnt += abs(n-i);
            answer = min(cnt, answer); //최소로 버튼을 누른 횟수 갱신
        }
    }

    return answer;

}

int main() {
    //100번에서 채널 n으로 이동하기 위해서는 버튼을 최소 몇 번 눌러야 하는지.
    //이동하려는 채널 n, 고장난 버튼의 개수 m
    int n, m, a;
    cin >> n >> m;
    for(int i=0; i<m; i++){
        cin >> a;
        broken[a] = true; //고장난 버튼
    }

    if(n==100)
        cout << "0";
    else
        cout << solve(n);

}
