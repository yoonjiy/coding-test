// Created by strit on 2023-01-10.
//태훈이는 숫자 x와 y를 좋아하기 때문에, 선물하는 카드에 적힌 수를 x와 y로 이루어진 수로 만들고 싶다.
//선물하는 것이 가능한 카드의 수 중에서 가장 큰 수를 구하는 프로그램을 작성하라.

//4
//16 1 3
//2 6 9
//5 0 8
//422223324 2 4

//#1 13
//#2 -1
//#3 -1
//#4 422222444

#include<iostream>

using namespace std;
int main(int argc, char** argv)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int test_case;
    int T;
    /*
       아래의 freopen 함수는 input.txt 를 read only 형식으로 연 후,
       앞으로 표준 입력(키보드) 대신 input.txt 파일로부터 읽어오겠다는 의미의 코드입니다.
       //여러분이 작성한 코드를 테스트 할 때, 편의를 위해서 input.txt에 입력을 저장한 후,
       freopen 함수를 이용하면 이후 cin 을 수행할 때 표준 입력 대신 파일로부터 입력을 받아올 수 있습니다.
       따라서 테스트를 수행할 때에는 아래 주석을 지우고 이 함수를 사용하셔도 좋습니다.
       freopen 함수를 사용하기 위해서는 #include <cstdio>, 혹은 #include <stdio.h> 가 필요합니다.
       단, 채점을 위해 코드를 제출하실 때에는 반드시 freopen 함수를 지우거나 주석 처리 하셔야 합니다.
    */
    //freopen("input.txt", "r", stdin);
    cin>>T;
    /*
       여러 개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
    */
    for(test_case = 1; test_case <= T; ++test_case)
    {

        /////////////////////////////////////////////////////////////////////////////////////////////
        int n, x, y;
        cin >> n >> x >> y;

        if(x > y){
            int temp = x;
            x = y;
            y = temp;
        }

        string num = to_string(n);
        int len = num.length();
        int idx = -1;
        string answer = "";

        for(int i=0; i<len; i++){
            if(len==1) {
                answer += "-1";
                break;
            }
            int nn = num[i]-'0';
            if(nn==x || nn==y){
                if(nn==y && idx == -1){
                    idx = i;
                }
                answer += num[i];
            }
            else if(nn>x && nn<y){
                answer += to_string(x);
                for(int j=i+1; j<len; j++){
                    answer += to_string(y);
                }
                break;
            }
            else if(nn>x && nn>y){
                for(int j=i; j<len; j++){
                    answer += to_string(y);
                }
                break;
            }
            else if(nn<x && nn<y){
                answer.erase(idx, i);
                answer.insert(idx, to_string(x));
                for(int j=idx+1; j<len; j++){
                    answer += to_string(y);
                }
                break;
            }
        }

        /////////////////////////////////////////////////////////////////////////////////////////////

        cout << "#" << test_case << " " << answer << "\n";

    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}