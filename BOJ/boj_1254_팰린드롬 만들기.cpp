// Created by strit on 2022-01-28. silver1 1254 팰린드롬 만들기
#include <iostream>
#include <string>

using namespace::std;

string s;

bool isPalindrome(int start, int end, string s){
    while(start<=end){
        if(s[start]==s[end]){
            start += 1;
            end -= 1;
        }
        else{
            return false;
        }
    }
    return true;
}

int main() {
    //만들 수 있는 가장 짧은 팰린드롬의 길이를 출력
    cin >> s;
    //aabc aa + cbaa
    //a abcba + a
    //특정 인덱스부터 문자열의 맨 마지막까지 팰린드롬이 되는 문자열의 시작 위치를 찾음.
    int end = s.length()-1;
    for(int i=0; i<=end; i++){
        if (isPalindrome(i, end, s)){
            cout << s.length()+i;
            return 0;
        }
    }

}




