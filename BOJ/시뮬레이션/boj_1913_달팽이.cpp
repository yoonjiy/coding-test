#include <iostream>
#include <vector>

using namespace std;

int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};

int main(){
    int n;
    cin >> n;
    int find;
    cin >> find;

    int v[n][n];
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            v[i][j] = -1;
        }
    }
    int r = n/2;
    int c = n/2;
    int ar, ac;
    if(find==1){
        ar = r;
        ac = c;
    }

    //북 동 남 서 이동
    int idx = 1;
    int dir = 0;
    v[r][c] = idx++;
    int moveCnt = 1;

    while(true){
        for(int i=0; i<2; i++){
            for(int j=0; j<moveCnt; j++){
                r += dr[dir];
                c += dc[dir];

                if(idx==find){
                    ar = r;
                    ac = c;
                }

                v[r][c] = idx++;

            }

            //방향 전환
            dir = (dir+1)%4;
        }

        moveCnt++;

        if(moveCnt==n){
            for(int i=0; i<moveCnt-1; i++){
                r += dr[dir];
                c += dc[dir];
                if(idx==find){
                    ar = r;
                    ac = c;
                }
                v[r][c] = idx++;
            }
            break;
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout << v[i][j] << " ";
        }
        cout << "\n";
    }

    cout << ar+1 << " " << ac+1;

}