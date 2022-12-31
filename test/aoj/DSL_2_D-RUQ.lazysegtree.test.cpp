#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_D"
#include <bits/stdc++.h>
using namespace std;
#include "../../segtree/lazysegtree.hpp"

const char en = '\n';
const int inf = INT32_MAX;

using S = int;
using F = int;
S op(S a,S b) { return a < b; }
S e() { return inf; }
S mapping(F f,S x) { return (f == inf ? x : f); }
F composition(F f,F g) { return (f == inf ? g : f); }
F id() { return inf; }

int main() {
    ios_base::sync_with_stdio(0);
    int n, q;
    cin>>n>>q;
    LazySegmentTree<S, op, e, F, mapping, composition, id> seg(n);
    while(q--) {
        int typ;
        cin>>typ;
        if(typ==0) {
        	int a, b, x;
        	cin>>a>>b>>x;
            seg.apply(a, b+1, x);
        } else {
        	int p;
        	cin>>p;
            cout<<seg.get(p)<<en;
        }
    }
    return 0;
}