#include <bits/stdc++.h>
using namespace std;
#include "../../segtree/lazysegtree.hpp"
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/DSL_2_I"

struct S {
    long long val;
    int size;
};
using F = long long;
const F ID = 1e9+7;

S op(S a, S b) {
    return {a.val + b.val, a.size + b.size};
}
S e() { return {0, 0}; }
S mapping(F f, S x) {
    if(f != ID) x.val = f*x.size;
    return x;
}
F composition(F f, F g) {
    return (f == ID ? g : f);
}
F id() { return ID; }

int main() {
    ios_base::sync_with_stdio(0);
    int n, q;
    cin>>n>>q;
    vector<S> v(n, {0, 1});
    LazySegmentTree<S, op, e, F, mapping, composition, id> seg(v);
    while(q--) {
        int typ, a, b;
        cin>>typ>>a>>b;
        if(typ==0) {
            int x;
            cin>>x;
            seg.apply(a, b+1, x);
        } else {
            cout<<seg.prod(a, b+1).val<<'\n';
        }
    }
    return 0;
}