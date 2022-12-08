// Created by strit on 2022-06-19. gold1 1194 달이 차오른다, 가자 - 비트마스킹, BFS
#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <cstring>

using namespace::std;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1};

struct node{
    int x, y;
    int count;
    int key;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, m;
    char maze[50][50];
    bool visited[50][50][64] = {false, }; //2^6, 6개의 열쇠 유뮤 표시
    queue<node> q;

    cin >> n >> m;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> maze[i][j];
            if(maze[i][j]=='0'){
                node start;
                start.x = i;
                start.y = j;
                start.count = 0;
                start.key = 0;
                q.push(start);
            }
        }
    }

    while(!q.empty()){
        node v = q.front();
        q.pop();
        int x = v.x;
        int y = v.y;
        int key = v.key;
        int count = v.count;

        if(maze[x][y]=='1'){
            cout << count;
            return 0;
        }

        for(int i=0; i<4; i++){
            int newx = x + dx[i];
            int newy = y + dy[i];

            if (newx < 0 || newx >= n || newy < 0 || newy >= m) continue;
            if(maze[newx][newy]=='#') continue; //#: 벽

            //a~f 열쇠일 때 - 열쇠가 있는 상태에서 방문한 게 아닌 경우 상태 업데이트 후 저장
            if('a' <= maze[newx][newy] && maze[newx][newy] <= 'f'){
                int newkey = key | (1 << (maze[newx][newy]-'a'));

                if(visited[newx][newy][newkey]) continue; //열쇠를 가지고 이미 방문한 경우

                node next;
                next.x = newx;
                next.y = newy;
                next.key = newkey;
                next.count = count + 1;
                q.push(next);

                visited[newx][newy][newkey] = true;
            }
                //A~F 문일 때 - 가지고 있는 열쇠가 비교해서 문을 열 수 있는지 확인
            else if('A' <= maze[newx][newy] && maze[newx][newy] <= 'F'){
                int open = key & (1 << (maze[newx][newy]-'A'));

                if(!open || visited[newx][newy][key]) continue;

                node next;
                next.x = newx;
                next.y = newy;
                next.key = key;
                next.count = count + 1;
                q.push(next);

                visited[newx][newy][key] = true;
            }
                //.인 경우 - 방문하지 않았다면
            else if(!visited[newx][newy][key]){
                node next;
                next.x = newx;
                next.y = newy;
                next.key = key;
                next.count = count + 1;
                q.push(next);

                visited[newx][newy][key] = true;
            }
        }
    }
    cout << "-1"; //미로를 탈출할 수 없는 경우
}

