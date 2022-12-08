// Created by strit on 2022-02-17. gold5 1759 암호 만들기 - dfs
#include <iostream>
#include <vector>
#include <algorithm>

using namespace::std;

int l, c; //암호 길이, 알파벳 개수
vector<char> v;

//a c i s t w
void dfs(string s, int idx, int depth){
    if(depth == l){
        int z = 0, m = 0; //자음, 모음
        for(int i=0; i<s.length(); i++){
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' ){
                z++;
            }
            else
                m++;
        }
        if(z>=1 && m>=2){
            cout << s << endl;
        }
        return;
    }

    for(int i=idx+1; i<c; i++){
        dfs(s+v[i], i, depth+1);
    }

}

int main() {
    //가능성있는 암호를 모두 출력, 최소 한개의 자음, 두개의 모음, 증가 하는 순서로 배열
    cin >> l >> c;
    for(int i=0; i<c; i++){
        char a;
        cin >> a;
        v.push_back(a);
    }

    sort(v.begin(), v.end());

    string s = "";
    for(int i=0; i<=c-l; i++){
        dfs(s + v[i], i, 1);
    }
}


