// Created by strit on 2022-09-11. silver1 1991 트리 순회 - 재귀
#include <iostream>
#include <algorithm>
#include <string>
#include <queue>

using namespace std;

struct node{
    char right, left;
};

int n;
vector<node> v(26);

void preorder(char root){
    if(root=='.') return;
    cout << root;
    preorder(v[root].left);
    preorder(v[root].right);
}

void inorder(char root){
    if(root=='.') return;
    inorder(v[root].left);
    cout << root;
    inorder(v[root].right);
}

void postorder(char root){
    if(root=='.') return;
    postorder(v[root].left);
    postorder(v[root].right);
    cout << root;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    char l, c, r;
    for(int i=0; i<n; i++){
        cin >> c >> l >> r;
        v[c].left = l;
        v[c].right = r;
    }

    preorder('A');
    cout << "\n";
    inorder('A');
    cout << "\n";
    postorder('A');
}

