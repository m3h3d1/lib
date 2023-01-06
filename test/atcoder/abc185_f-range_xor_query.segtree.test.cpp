#define IGNORE

#include <bits/stdc++.h>
using namespace std;
#include "../../segtree/segtree.hpp"
#define PROBLEM "https://atcoder.jp/contests/abc185/tasks/abc185_f"

int op(int a, int b) { return a ^ b; }
int e() { return 0; }

int main() {
    ios_base::sync_with_stdio(0);
    int n, q;
    cin>>n>>q;
    vector<int> v(n);
    for(int &x: v) {
    	cin>>x;
    }
    SegmentTree<int, op, e> seg(v);
    while(q--) {
    	int typ, x, y;
    	cin>>typ>>x>>y;
    	x--;
    	if(typ==1) {
    		seg.set(x, seg.get(x)^y);
    	} else {
    		cout<<seg.prod(x, y)<<'\n';
    	}
    }
    return 0;
}