#include <bits/stdc++.h>
using namespace std;
#include "../../segtree/lazysegtree.hpp"
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/DSL_2_H"
const int INF = 1e9+7;

using S = int;
using F = int;

S op(S a, S b) { return min(a, b); }
S e() { return INF; }
S mapping(F f, S x) { return f + x; }
F composition(F fnew, F gold) { return gold + fnew; }
F id() { return 0; }

int main() {
    ios_base::sync_with_stdio(0);
    int n, q;
    cin>>n>>q;
    vector<S> v(n);
    LazySegmentTree<S, op, e, F, mapping, composition, id> seg(v);
    while(q--) {
        int typ, a, b;
        cin>>typ>>a>>b;
        if(typ==0) {
            int x;
            cin>>x;
            seg.apply(a, b+1, x);
        } else {
            cout<<seg.prod(a, b+1)<<'\n';
        }
    }
    return 0;
}