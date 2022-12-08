// Created by strit on 2022-01-21. boj silver1 1052 물병
#include <iostream>

using namespace::std;
//같은 양의 물이 들어 있는 물병에 대해서 한 개의 물병에 다른 한쪽의 물을 모두 붓는다.
//n개의 물병, k개의 한번에 옮길 수 있는 물병의 개수.
//k개를 넘지 않는 비어 있지 않은 물병을 만든다. 1l 짜리 물병을 살 수 있다.
//첫째 줄에 상점에서 사야하는 물병의 최솟값을 출력한다. 만약 정답이 없을 경우에는 -1을 출력한다.
void renewN(int* n, int* k){
    int maxNum = 1;
    while(maxNum<*n){
        maxNum *= 2;
    }
    maxNum /= 2;
    *n -= maxNum;
    *k -= 1;
}

bool check(int n){ //2의 거듭제곱 판별
    return (n & (n - 1)) == 0;
}

int main() {
    int n, k, bottle = 0;
    cin >> n >> k;

    //1. n보다 작은 최대 2의 제곱으로 만든다.
    //2. k가 1이 될 때까지 1씩 감소시키면서.
    //3. k가 1이되면 그때의 n을 2의 거듭제곱을 만들기 위해 사야하는 물병 개수를 구한다.
    while(k>1){
        renewN(&n, &k);
    }

    while(!check(n)){
        bottle++;
        n += 1;
    }

    cout << bottle;

}


