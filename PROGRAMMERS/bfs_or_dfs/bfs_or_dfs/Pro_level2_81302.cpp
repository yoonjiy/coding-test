#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

int dr[12] = {0, 0, 1, -1, 0, 0, 2, -2, 1, 1, -1, -1};
int dc[12] = {1, -1, 0, 0, 2, -2, 0, 0, -1, 1, 1, -1};

bool outOfRange(int r, int c){
    if(r<0 || c<0 || r>=5 || c>=5) return true;
    else return false;
}

bool bfs(vector<string> p){
    queue<pair<int, int>> q;
    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++){
            if(p[i][j]=='P'){
                q.push({i, j});
            }
        }
    }
    
    while(!q.empty()){
        int r = q.front().first;
        int c = q.front().second;
        q.pop();
        
        //맨해튼 거리 1 검사
        for(int i=0; i<4; i++){
            int nr = r + dr[i];
            int nc = c + dc[i];
            
            if(outOfRange(nr, nc)) continue;
            
            if(p[nr][nc]=='P') return false;
            
        }
        
                
        for(int i=4; i<8; i++){
            int nr = r + dr[i];
            int nc = c + dc[i];
            
            if(outOfRange(nr, nc)) continue;
            
            if(p[nr][nc]=='P') {
                if(p[(r+nr)/2][(c+nc)/2]!='X') return false;
            }
            
        }
        
                
        for(int i=8; i<12; i++){
            int nr = r + dr[i];
            int nc = c + dc[i];
            
            if(outOfRange(nr, nc)) continue;
            
            if(p[nr][nc]=='P') {
                if(p[r][nc]!='X' || p[nr][c]!='X') return false;
            }
            
        }
    }
    
    return true;
    
    
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    
    for(auto p:places){
        bool flag = bfs(p);
        if(flag){
            answer.push_back(1);
        }
        else answer.push_back(0);
    }
    return answer;
}

