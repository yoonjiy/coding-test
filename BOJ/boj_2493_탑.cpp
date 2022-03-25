// Created by strit on 2022-03-25. gold5 2493 탑 - stack
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <stack>

using namespace::std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    stack<pair<int, int>> top;
    cin >> n;

    int height;
    for(int i=1; i<=n; i++){
        cin >> height;
        while(!top.empty()){
            if(top.top().second > height){
                cout << top.top().first << " ";
                break;
            }
            top.pop();
        }

        if(top.empty())
            cout << "0 ";

        top.push({i, height});

    }

}
