#include <string>
#include <vector>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    
    //number에서 k 개의 수를 제거했을 때 만들 수 있는 수 중 가장 큰 숫자를 문자열 형태로 return
    
    int maxidx = -1;
    for(int i=0; i<number.length()-k; i++){
        int max = -1;
        for(int j=maxidx+1; j<=i+k; j++){
            if(number[j] > max){
                max = number[j];
                maxidx = j;
            }
        }
        answer += max;
    }
    
    return answer;
}