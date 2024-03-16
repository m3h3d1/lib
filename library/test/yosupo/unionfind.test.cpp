#define PROBLEM "https://judge.yosupo.jp/problem/unionfind"
#include <bits/stdc++.h>
using namespace std;
#include "../../ds/dsu.hpp"

int main() {
    ios::sync_with_stdio(0);
    int n, q, typ, u, v;
    cin>>n>>q;
    DSU dsu(n);
    while(q--) {
        cin>>typ>>u>>v;
        if(typ) {
            cout<<dsu.connected(u, v)<<endl;
        } else {
            dsu.unite(u, v);
        }
    }
    return 0;
}