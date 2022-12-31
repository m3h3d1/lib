#include <bits/stdc++.h>
using namespace std;
#include "../../segtree/lazysegtree.hpp"
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/DSL_2_E"

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
F composition(F f, F g) {
    return f + g;
}
F id() { return 0; }

int main() {
    ios_base::sync_with_stdio(0);
    int n, q;
    cin>>n>>q;
    vector<S> v(n, {0, 1});
    LazySegmentTree<S, op, e, F, mapping, composition, id> seg(v);
    while(q--) {
        int typ;
        cin>>typ;
        if(typ==0) {
        	int a, b, x;
        	cin>>a>>b>>x;
            a--;
            seg.apply(a, b, x);
        } else {
        	int p;
            cin>>p;
            p--;
            cout<<seg.get(p).val<<'\n';
        }
    }
    return 0;
}