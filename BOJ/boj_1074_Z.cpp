// Created by strit on 2022-01-28. boj silver1 1074 Z - 재귀
#include <iostream>
#include <vector>
#include <algorithm>

using namespace::std;

int N, r, c, cnt=0;

void search(int width, int x, int y){
    if(x==c && y==r){
        cout << cnt;
        return;
    }
    //r행 c열이 존재한다면
    if( x+width>c && x<=c && y+width>r && y<=r){
        //왼위, 오위, 왼아래, 오아래 순으로 탐색
        search(width/2, x, y);
        search(width/2, x+width/2, y);
        search(width/2, x, y+width/2);
        search(width/2, x+width/2, y+width/2);
    }
    else{
        cnt += width*width;
    }
}

int main() {
    //r행 c열에 몇번째로 방문했는지 출력
    cin >> N >> r >> c;
    int width=1;
    for(int i=0; i<N; i++){
        width *= 2;
    }

    search(width, 0, 0);

}


