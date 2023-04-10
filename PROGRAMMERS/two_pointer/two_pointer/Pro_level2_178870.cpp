package two_pointer;

#include <iostream>
#include <string>
#include <vector>
#include <climits>

using namespace std;

vector<int> solution(vector<int> sequence, int k) {
    vector<int> answer;
    //부분 수열의 시작 인덱스와 마지막 인덱스를 배열에 담아 return
    int low = 0, high = 0;
    int minlen = INT_MAX;
    int sidx = 0, eidx = 0;
    int sum = sequence[low];
    while(low<=high){
        if(sum < k){
            high++;
            if(high==sequence.size()) break;
            sum += sequence[high];
        }
        else if(sum==k){
            if(minlen > (high-low)){
                minlen = high-low;
                sidx = low;
                eidx = high;
            }
            high++;
            if(high==sequence.size()) break;
            sum += sequence[high];
        }
        else{
            sum -= sequence[low];
            low++;
        }
    }
    
    answer.push_back(sidx);
    answer.push_back(eidx);
    return answer;
}