// Created by strit on 2022-01-23. boj silver1 1174 줄어드는 수 - 재귀, 정렬
#include <iostream>
#include <vector>
#include <algorithm>

using namespace::std;

void decrease(long long a, int depth, vector<long long>& v){
    if(depth>10)
        return;

    v.push_back(a);

    int x = a%10;
    for(int i=x-1; i>=0; i--){
        decrease(a*10+i, depth+1, v);
    }

}

int main() {
    //N번째로 작은 줄어드는 수를 출력하는 프로그램을 작성하시오.
    //0~9까지는 모두 줄어드는 수.
    int n;
    cin >> n;
    vector<long long> v;

    for(int i=0; i<=9; i++){
        decrease(i, 0, v);
    }

    sort(v.begin(), v.end());

    if(n > v.size()){
        cout << "-1";
    }
    else{
        cout << v[n-1];
    }

}


