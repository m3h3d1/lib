#include <bits/stdc++.h>
using namespace std;
#define PROBLEM "https://judge.yosupo.jp/problem/factorize"
#include "../../math/fastFactorize.hpp"

int main() {
    ios::sync_with_stdio(0);
    int q; cin>>q;
    while(q--) {
        ull a; cin>>a;
        vector<ull> f;
        factor(a, f);
        sort(f.begin(), f.end());
        cout<<f.size()<<' ';
        for(auto x: f) 
            cout<<x<<' ';
        cout<<'\n';
    }
    return 0;
}