// Created by strit on 2022-02-04. silver1 1342 행운의 문자열
#include <iostream>
#include <algorithm>

using namespace::std;

int main() {
    //인접해 있는 문자가 모두 다른 행운의 문자열이 몇 개 나오는 지
    string s;
    cin >> s;

    sort(s.begin(), s.end());

    int answer=0;
    do{
        bool check = true;
        for(int i=0; i<s.length()-1; i++){
            if(s[i]==s[i+1]){
                check = false;
                break;
            }
        }

        if(check){
            answer++;
        }

    }while(next_permutation(s.begin(),s.end()));

    cout << answer;
}




