#include <bits/stdc++.h>
using namespace std;
#include "../../segtree/lazysegtree.hpp"
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/DSL_2_G"
const int INF = 1e9+7;

struct S {
    long long val;
    int size;
};
using F = long long;

S op(S a, S b) { 
    return {a.val + b.val, a.size + b.size}; 
}
S e() { return {0, 0}; }
S mapping(F f, S x) {
    return {x.val + f*x.size, x.size};
}
F composition(F f, F g) { return f+g; }
F id() { return 0; }

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
            seg.apply(a-1, b, x);
        } else {
            cout<<seg.prod(a-1, b).val<<'\n';
        }
    }
    return 0;
}