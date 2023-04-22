#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

vector<string> list;
bool visited[10000];
int n;

vector<string> split(string s, char del){
    vector<string> ans;
    string temp;
    stringstream ss(s);
    
    while(getline(ss, temp, del)){
        ans.push_back(temp);
    }
    
    return ans;
}

void dfs(int depth, string now, string route, vector<vector<string>> t){
    if(depth==n){
        list.push_back(route);
        return;
    }
    
    for(int i=0; i<n; i++){
        if(visited[i]) continue; //이미 사용한 티켓
        
        if(now==t[i][0]){
            visited[i] = true;
            dfs(depth+1, t[i][1], route+' '+t[i][1], t);
            visited[i] = false;
        }
    }
}


vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer;
    
    n = tickets.size();
    
    dfs(0, "ICN", "ICN", tickets);

    
    //사전순 정렬
    sort(list.begin(), list.end());
    answer = split(list[0], ' ');

    return answer;
}