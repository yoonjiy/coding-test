// Created by strit on 2022-06-20. gold1 11505 구간 곱 구하기 - 세그먼트 트리
#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <cstring>

using namespace::std;

vector<long long> tree;
long long arr[1000001];

long long init(int index, int start, int end){
    if(start==end){
        tree[index] = arr[start];
    }
    else{
        int mid = (start+end)/2;
        tree[index] = (init(2*index, start, mid) * init(2*index+1, mid+1, end)) % 1000000007;
    }
    return tree[index];
}

long long mul(int index, int start, int end, int left, int right){
    if (start > right || end < left)
        return 1;
    else if(left<=start && end<=right){
        return tree[index];
    }
    else{
        int mid = (start+end)/2;
        return (mul(2*index, start, mid, left, right) * mul(2*index+1, mid+1, end, left, right)) % 1000000007;
    }
}

void update(int changed_index, long long nvalue, int index, int start, int end){
    if (changed_index < start || changed_index > end)
        return;

    if(start==end){
        tree[index] = nvalue;
        return;
    };

    int mid = (start+end) / 2;
    update(changed_index, nvalue, index*2, start, mid);
    update(changed_index, nvalue, index*2+1, mid+1, end);
    tree[index] = (tree[index*2] * tree[index*2 + 1])%1000000007;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N, M, K;
    cin >> N >> M >> K;
    int h = ceil(log2(N));

    tree = vector<long long>(1<<(h+1));

    for(int i=1; i<=N; i++){
        cin >> arr[i];
    }

    init(1, 1, N);

    for(int i=0; i<M+K; i++){
        long long a, b, c;
        cin >> a >> b >> c;
        if(a==1){
            update(b, c, 1 , 1, N);
        }
        else{
            cout << mul(1, 1, N, b, c) << "\n";
        }
    }

}

