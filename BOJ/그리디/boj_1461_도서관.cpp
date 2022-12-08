// Created by strit on 2022-02-19. gold5 1461 도서관 - 그리디
#include <iostream>
#include <vector>
#include <algorithm>

using namespace::std;

int main() {
    //책을 모두 제자리에 둘 때 최소걸음수. 한번에 최대 M권을 들 수 있음.
    int n, m; //책의 개수, 최대로 들고 갈 수 있는 책의 개수
    cin >> n >> m;
    int loc[10001];
    int tmp, minus_cnt = 0;
    for(int i=0; i<n; i++){
        cin >> tmp;
        loc[i] = tmp;
        if(tmp < 0)
            minus_cnt++;
    }


    sort(loc, loc+n);

    //-39 -37 -29 -28 -6 2 11, 극단에 있는 값 중에 가장 큰 값은 왕복 x, 한번만 이동함
    //양수, 음수 따로 왕복값 계산

    int answer=0;
    for(int i=n-1; i>=minus_cnt; i-=m){
        answer += (loc[i]*2); //양수 왕복값
    }

    for(int i=0; i<minus_cnt; i+=m){
        answer += abs(loc[i]*2); //음수 왕복값
    }

    answer -= max(abs(loc[0]), abs(loc[n-1]));

    cout << answer;

}



