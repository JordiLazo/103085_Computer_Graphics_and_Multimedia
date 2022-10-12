#include<bits/stdc++.h>
#include<iostream>
#include<vector>

using namespace std;

int visited[1000];

int main(){
    int n = 5;
    vector<int> a[1000];
    while(n--){
        int p,q;
        cin>>p>>q;
        a[p].push_back(q);

    }
    for (auto &i : a)
        for (auto j : i)
            cout << "array index:" << &i - &a[0] << "  Entry " << j << endl;

}