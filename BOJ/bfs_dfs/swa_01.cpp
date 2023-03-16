// Created by strit on 2023-01-10.
//호설이는 연말을 맞아 휴가를 끌어 모아 여행을 가려고 한다.
//
//
//
//이 여행지에는 관광 도시들이 1행, 1열부터 R행 C열까지 있으며, 총 R x C 개의 도시로 이루어져 있다.
//
//호설이는 여행 첫날엔 1행 1열의 도시로 출발한다.
//
//각 도시에는 A부터 Z 중 하나의 알파벳으로 나타낼 수 있는 기념품이 있으며, 같은 알파벳은 같은 기념품이다.
//호설이는 파트원들에게 나눠주기 위해 도시에 도착할 때마다 기념품을 구매할 계획이다.
//그리고, 호설이는 현재 위치에서 기념품을 구매 후 4방향(동, 서, 남, 북) 중 한 방향으로 1칸 이동하여 다음 도시로 이동한다.
//호설이는 휴가까지 아끼며 일을 했지만 모아둔 돈이 많지 않다.
//따라서 기념품을 최대한 많이 구매하되, 종류가 겹치지 않도록 여행 경로를 계획하고 싶다.
//호설이가 1행 1열에서 여행을 시작했을 때, 같은 기념품을 두 개 이상 사지 않도록 여행을 떠나는 방법 중에 가장 많은 기념품을 구매할 수 있는 최대 개수를 구하여라.


//3
//2 4
//CAAB
//ADCB
//3 6
//HFDFFB
//AJHGDH
//DGAGEH
//5 5
//IEFCJ
//FHFKC
//FFALF
//HFGCF
//HMCHH


//#1 3
//#2 6
//#3 10

#include<iostream>
#include <algorithm>
#include <map>
#include <cstring>

using namespace std;

int dr[4] = {0, 0, 1, -1};
int dc[4] = {1, -1, 0, 0};

char city[21][21];
bool visited[21][21];
int ans = -1;

void dfs(int r, int c, int h, int w, int answer, map<char,int> m){
    for(int i=0; i<4; i++){
        int nr = r + dr[i];
        int nc = c + dc[i];

        if(nr<0 || nc<0 || nr>=h || nc>=w || visited[nr][nc]) continue;

        if(m[city[nr][nc]]>=1) continue;

        visited[nr][nc] = true;
        m[city[nr][nc]]++;

        dfs(nr, nc, h, w, answer+1, m);

        visited[nr][nc] = false;
        m[city[nr][nc]]--;
    }

    ans = max(answer, ans);
}

int main(int argc, char** argv)
{
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
        int r, c;
        cin >> r >> c;

        memset(city, 0, sizeof(city));
        memset(visited, 0, sizeof(visited));

        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                cin >> city[i][j];
            }
        }

        map<char, int> m;
        m[city[0][0]] = 1;
        dfs(0, 0, r, c, 1, m);
        cout << "#" << test_case << " " << ans << "\n";
        /////////////////////////////////////////////////////////////////////////////////////////////


    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
