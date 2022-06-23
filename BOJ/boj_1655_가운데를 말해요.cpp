// Created by strit on 2022-06-23. gold2 1655 가운데를 말해요 - heap
#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <cstring>

using namespace::std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;

    priority_queue<int> max;
    priority_queue<int, vector<int>, greater<int>> min;

    for(int i=0; i<n; i++){
        int num;
        cin >> num;
        if( max.size() == min.size() )
            max.push(num);
        else min.push(num);

        if (!max.empty() && !min.empty() && max.top() > min.top() ) {
            int mt = max.top();
            int nt = min.top();
            max.pop();
            min.pop();
            min.push(mt);
            max.push(nt);
        }

        cout << max.top() << "\n";

    }
}

