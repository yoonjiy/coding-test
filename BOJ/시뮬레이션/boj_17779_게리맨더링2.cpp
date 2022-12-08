// Created by strit on 2022-11-10. gold3 17779 게리맨더링2 - 브루트포스, 구현
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <cmath>
#include <stack>
#define INF 987654321

using namespace std;

struct pos{
    int r, c;
};

int n;
int A[21][21];
int region[21][21];
pos point[4];
int ans = INF;

bool isOk(int r, int c, int d1, int d2){
    //선거구의 경계선을 그릴 수 있는지 체크 -> 각 꼭짓점의 범위
    if (r + d1 >= n || c - d1 < 0) return false;
    if (r + d2 >= n || c + d2 >= n) return false;
    if (r + d1 + d2 >= n || c - d1 + d2 >= n) return false;
    if (r + d2 + d1 >= n || c + d2 - d1 < 0) return false;

    return true;
}

void calculate()
{
    // 인구수 계산
    int people[6] = { 0, 0, 0, 0, 0, 0};
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            people[region[i][j]] += A[i][j];
        }
    }

    sort(people, people + 6);
    int diff = people[5] - people[1];
    ans = min(ans, diff);
}

void labeling(){

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            region[i][j] = 5;
        }
    }

    /*
     * 1번 선거구 채우기
     * 0행 ~ 2번 꼭짓점의 r-1행
     * 0열 ~ 1번 꼭짓점의 c열
     * 행의 값이 1번 꼭짓점의 r 값과 같거나 커지는 순간부터 표시해야 하는 열의 갯수가 한칸씩 줄어듦에 주의!
    */
    int sub_area = 0;
    for(int i=0; i<point[1].r; i++){
        if(i >= point[0].r) sub_area++;
        for(int j=0; j<=point[0].c - sub_area; j++){
            region[i][j] = 1;
        }
    }

    /*
     * 2번 선거구 채우기
     * 0행 ~ 3번 꼭짓점의 r행
     * 1번 꼭짓점의 c + 1 ~ n-1열
     * 행의 값이 1번 꼭짓점의 r 값보다 커지는 순간부터 표시해야 하는 열의 갯수가 한칸씩 줄어듦에 주의!
    */
    sub_area = 0;
    for(int i=0; i<=point[2].r; i++){
        if(i > point[0].r) sub_area++;
        for(int j=point[0].c + 1 + sub_area; j<n; j++){
            region[i][j] = 2;
        }
    }

    /*
     * 3번 선거구 채우기
     * n-1행 ~ 2번 꼭짓점의 r행
     * 0열 ~ 4번 꼭짓점의 c열
     * 행의 값이 4번 꼭짓점의 r 값보다 작아지는 순간부터 표시해야 하는 열의 갯수가 한칸씩 줄어듦에 주의!
    */
    sub_area = 0;
    for(int i=n-1; i>=point[1].r; i--){
        if(i < point[3].r) sub_area++;
        for(int j=0; j<point[3].c - sub_area; j++){
            region[i][j] = 3;
        }
    }

    /*
     * 4번 선거구 채우기
     * n-1행 ~ 3번 꼭짓점의 r행
     * 4번 꼭짓점의 c열 ~ n-1열
     * 행의 값이 4번 꼭짓점의 r 값과 같거나 작아지는 순간부터 표시해야 하는 열의 갯수가 한칸씩 줄어듦에 주의!
    */
    sub_area = 0;
    for(int i=n-1; i>point[2].r; i--){
        if(i <= point[3].r) sub_area++;
        for(int j=point[3].c + sub_area; j<n; j++){
            region[i][j] = 4;
        }
    }
    calculate();
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> A[i][j];
        }
    }

    //r, c, d1, d2 정하기
    for(int r=0; r<n; r++){
        for(int c=1; c<n; c++){
            for(int d1=1; d1<=c; d1++){
                for(int d2=1; d2<n-c; d2++){
                    if(isOk(r, c, d1, d2)){
                        point[0].r = r; point[0].c = c;
                        point[1].r = r + d1; point[1].c = c - d1;
                        point[2].r = r + d2; point[2].c = c + d2;
                        point[3].r = r + d1 + d2; point[3].c = c - d1 + d2;
                        labeling();
                    }
                }
            }

        }
    }

    cout << ans;

}

