// Created by strit on 2022-06-29. silver1 1105 팔
#include <iostream>
#include <algorithm>
#include <map>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    string l, r;
    int cnt = 0;

    cin >> l >> r;
    if(l.length() != r.length())
        cout << "0";
    else{
        for(int i=0; i<l.length(); i++){
            if(l[i]==r[i] && l[i]=='8')
                cnt++;
            else if(l[i]!=r[i])
                break;
        }

        cout << cnt;
    }
}


