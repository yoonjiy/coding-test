// Created by strit on 2022-09-07. gold5 5430 AC - deque
#include <iostream>
#include <algorithm>
#include <string>
#include <queue>

using namespace std;

int t;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> t;

    string fun, arr;
    for(int i=0; i<t; i++){
        cin >> fun; //RD 함수
        int len;
        cin >> len; //숫자 개수
        cin >> arr; //배열

        deque<int> deq;

        string s = "";
        for(int j=0; j<arr.length(); j++){
            if(isdigit(arr[j])){
                s += arr[j];
            }
            else{
                if (!s.empty()){
                    deq.push_back(stoi(s));
                    s.clear();
                }
            }
        }

        bool error = false, reverse = false;
        for (auto f : fun){
            if(f=='R'){
                if(reverse)
                    reverse = false;
                else reverse = true;
            }
            else{
                if(deq.empty()){
                    cout << "error\n";
                    error = true;
                    break;
                }
                if(reverse)
                    deq.pop_back();
                else
                    deq.pop_front();
            }
        }

        if(!error) {
            cout << "[";
            if (!deq.empty() && reverse){
                while(!deq.empty()){
                    cout << deq.back();
                    deq.pop_back();
                    if(!deq.empty())
                        cout << ",";
                }
            }
            if( !deq.empty() && !reverse){
                while(!deq.empty()){
                    cout << deq.front();
                    deq.pop_front();
                    if(!deq.empty())
                        cout << ",";
                }
            }
            cout << "]\n";
        }
    }
}

