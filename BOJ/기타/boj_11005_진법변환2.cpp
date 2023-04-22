#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main(){
    int n;
    cin >> n;
    int b;
    cin >> b;
    //10진법 수 n을 b 진법으로 변환하기

    //b보다 몫이 작아질때까지 계속 나누면서 나머지를 stack에 저장하기
    stack<int> s;

    int p = n, r = 0; //몫, 나머지
    while(p >= b){
        r = p%b;
        p = p/b;
        s.push(r);
    }
    s.push(p);

    string answer;
    while(!s.empty()){
        int a = s.top();
        s.pop();
        if(a>=10){
            char c = 'A'+a-10;
            answer += c;
        }
        else answer += to_string(a);
    }

    cout << answer;
}
