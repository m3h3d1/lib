#include <bits/stdc++.h>
using namespace std;
#include "../../mod/mint.hpp"
#include "../../segtree/lazysegtree.hpp"
#define PROBLEM "https://judge.yosupo.jp/problem/range_affine_range_sum"

using T = modular<998244353>;
using S = pair<T, int>;
using F = pair<T, T>;
S op(S a,S b) { return make_pair(a.first + b.first, a.second + b.second); }
S e() { return make_pair(0, 0); }
S mapping(F f,S x) { 
    return make_pair(f.first * x.first + f.second * x.second, x.second); 
}
F composition(F f,F g) { 
    return make_pair(g.first * f.first, f.second + f.first * g.second); 
}
F id() { return make_pair(1, 0); }

int main() {
    ios_base::sync_with_stdio(0);
    int n, q;
    cin>>n>>q;
    vector<S> v(n);
    for(auto &a: v) {
        cin>>a.first;
        a.second = 1;
    }
    LazySegmentTree<S, op, e, F, mapping, composition, id> seg(v);
    while(q--) {
        int typ, l, r;
        cin>>typ>>l>>r;
        if(typ==0) {
            F x;
            cin>>x.first>>x.second;
            seg.apply(l, r, x);
        } else {
            cout<<seg.prod(l, r).first<<'\n';
        }
    }
    return 0;
}