#include <bits/stdc++.h>
using namespace std;
#include "../../graph/lca.hpp"
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/GRL_5_C"

int main() {
    ios_base::sync_with_stdio(0);
    int n;
    cin>>n;
    vector<vector<int>> G(n);
    for(int i=0; i<n; ++i) {
        int k;
        cin>>k;
        for(int j=0; j<k; ++j) {
            int c;
            cin>>c;
            G[i].push_back(c);
            G[c].push_back(i);
        }
    }

    LCA lca(G, 0);

    int q;
    cin>>q;
    while(q--) {
        int a, b;
        cin>>a>>b;
        cout<<lca.query(a, b)<<'\n';
    }
    return 0;
}