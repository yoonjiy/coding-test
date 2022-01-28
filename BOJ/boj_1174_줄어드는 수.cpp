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

