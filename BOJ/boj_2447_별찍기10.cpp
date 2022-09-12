// Created by strit on 2022-09-12. gold5 2447 별찍기 10 - 재귀
#include <iostream>
#include <algorithm>
#include <string>
#include <queue>

using namespace std;

void star(int i, int j, int n){

    if (n == 1){
        cout << "*";
    }
    else if ((i / (n/3)) % 3 == 1 && (j / (n/3)) % 3 == 1){
        cout << " ";
    }
    else{
        star(i, j, n/3);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            star(i, j, n);
        }
        cout << "\n";
    }

}

