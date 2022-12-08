// Created by strit on 2022-02-16. gold5 1188 음식 평론가 - 최소공약수
#include <iostream>
#include <vector>
#include <algorithm>

using namespace::std;

int gcd(int n, int m){
    if(n%m==0)
        return m;
    else{
        return gcd(m, n%m);
    }
}

int main() {

    int n, m; //소세지 개수, 평론가 수
    cin >> n >> m; // 3 4

    cout << m - gcd(n, m);
}


