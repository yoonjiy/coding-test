#include <string>
#include <vector>

using namespace std;
int ans;

void dfs(vector<int> numbers, int now, int target, int idx){
    if(idx==numbers.size()){
        if(target==now) ans++;
        return;
    }

    dfs(numbers, now+numbers[idx], target, idx+1);   
    
    dfs(numbers, now-numbers[idx], target, idx+1);

}

int solution(vector<int> numbers, int target) {
    int answer = 0;
    //주어질 때 숫자를 적절히 더하고 빼서 타겟 넘버를 만드는 방법의 수를 return
    dfs(numbers, 0, target, 0);
    
    answer = ans;
    return answer;
}