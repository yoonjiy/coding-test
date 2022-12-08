// Created by strit on 2022-01-20. boj gold1 1019 책페이지
#include <iostream>
#include <string>

using namespace::std;

void calculate(int start, int answer[], int digit){
    while(start>0){
        int idx = start%10;
        answer[idx] += digit;
        start /= 10;
    }
}

int main() {
    int answer[10] = {0,};
    int page;
    cin >> page; //페이지 입력
    int start=1;
    int digit=1;
    while(start<=page){
        //1의 자리가 0이 될 때까지 start 증가
        while(start%10 != 0 && start<=page){
            calculate(start, answer, digit);
            start++;
        }

        if(start>page)
            break;

        //1의 자리가 9가 될 때까지 page 감소
        while(page%10 != 9 && start<=page){
            calculate(page, answer, digit);
            page--;
        }

        //0~9가 등장한 횟수 계산
        start = start/10;
        page = page/10;

        for(int i=0; i<10; i++){
            answer[i] += (page-start+1)*digit;
        }

        digit *= 10;

    }

    for (int i:answer){
        cout << i << " ";
    }

    return 0;
}



