// Created by strit on 2022-09-27. gold3 1005 ACM Craft - 위상정렬
#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
#include <math.h>
#define INF 987654321

using namespace std;

int t;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    //위상 정렬
    cin >> t;

    while(t--){
        int n, k, w;
        int in[1001] = {0, };
        vector<int> node[1001];
        int time[1001] = {0, };
        int ans[1001] = {0, };

        cin >> n >> k;
        for(int i=1; i<=n; i++){
            //건물 건설에 걸리는 시간
            cin >> time[i];
        }
        for(int i=1; i<=k; i++){
            //건축 순서
            int f, s;
            cin >> f >> s;
            node[f].push_back(s);
            in[s]++;
        }

        cin >> w; //특정 건물 번호

        queue<int> q;
        for(int i=1; i<=n; i++){
            if(in[i]==0){
                q.push(i);
                ans[i] = time[i];
            }
        }

        while(!q.empty()){
            int v = q.front();
            q.pop();

            for(int i=0; i<node[v].size(); i++){
                int curr = node[v][i];
                ans[curr] = max(ans[v]+time[curr], ans[curr]);
                in[curr]--;
                if(in[curr]==0)
                    q.push(curr);
            }
        }

        cout << ans[w] << "\n";

    }

}

