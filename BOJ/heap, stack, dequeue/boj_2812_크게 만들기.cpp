// Created by strit on 2022-11-03. gold3 2812 크게 만들기 - deque
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <cmath>
#include <stack>
#define INF 987654321

using namespace std;

int n, k;
string s;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;
    cin >> s;

    deque<char> dq;

    for(int i=0; i<s.length(); i++){
        while(!dq.empty() && k && s[i] > dq.back()){
            dq.pop_back();
            k--;
        }
        dq.push_back(s[i]);
    }

    for (int i = 0; i < dq.size()-k ; i++)
        cout << dq[i];

}

