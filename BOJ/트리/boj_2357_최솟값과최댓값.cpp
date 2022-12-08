// Created by strit on 2022-05-19. gold1 2357 최솟값과 최댓값 - 세그먼트 트리
#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>

using namespace::std;

int n, m;
int arr[100001];
vector<int> min_tree, max_tree;

void init(int index, int start, int end){
    if(start==end){ //리프 노드
        min_tree[index] = max_tree[index] = arr[start];
        return;
    }
    else{
        int mid = (start+end)/2;
        init(2*index, start, mid);
        init(2*index+1, mid+1, end);
        min_tree[index] = min(min_tree[2*index], min_tree[2*index+1]); //구간의 최솟값 저장
        max_tree[index] = max(max_tree[2*index], max_tree[2*index+1]); //구간의 최댓값 저장
        return;
    }
}

pair<int, int> findMaxAndMin(int index, int start, int end, int left, int right){
    if(left > end || right < start){ //범위 밖
        return {INT32_MAX, 0};
    }
    else if(left <= start && end <= right){
        return {min_tree[index], max_tree[index]};
    }
    else {
        pair<int, int> l, r;
        int m = (start+end)/2;
        l = findMaxAndMin(2*index, start, m, left, right);
        r = findMaxAndMin(2*index+1, m+1, end, left, right);
        return {min(l.first, r.first), max(l.second, r.second)};
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    int h;
    h = (int)ceil(log2(n)); //세그먼트 트리의 높이 log(n)

    min_tree = vector<int>(1<<(h+1)); //세그먼트 트리의 크기 2^(h+1)
    max_tree = vector<int>(1<<(h+1));

    for(int i=1; i<=n; i++){
        cin >> arr[i]; //리프 노드
    }

    init(1, 1, n); //자식 노드를 2*index, 2*index + 1로 표현하기 위해 1부터 시작

    int left,right;
    pair<int, int> answer;

    for(int i=1; i<=m; i++){
        cin >> left >> right;
        answer = findMaxAndMin(1, 1, n, left, right);
        cout << answer.first << " " << answer.second << "\n";
    }
}
