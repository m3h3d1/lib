#include <bits/stdc++.h>
using namespace std;
#include "../../segtree/segtree.hpp"
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/DSL_2_B"

int op(int a, int b) { return a + b; }
int e() { return 0; }

int main() {
    ios_base::sync_with_stdio(0);
    int n, q;
    cin>>n>>q;
    SegmentTree<int, op, e> seg(n);
    while(q--) {
        int typ, x, y;
        cin>>typ>>x>>y;
        if(typ==0) {
            seg.set(x, seg.get(x) + y);
        } else {
            cout<<seg.prod(x, y+1)<<'\n';
        }
    }
    return 0;
}