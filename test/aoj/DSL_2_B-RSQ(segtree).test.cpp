#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_B"
#include <bits/stdc++.h>
using namespace std;
#include "../../segtree/segtree.hpp"

#define ff first
#define ss second
#define pb push_back
typedef long long ll;
typedef pair<int,int> pii;
#define all(v) (v).begin(),(v).end()
#define db(x) cerr<<__LINE__<<": "<<#x<<" = "<<(x)<<'\n'
const char en = '\n';
const int inf = 1e9+7;
const int N = 1e6+9;

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
            cout<<seg.prod(x, y+1)<<en;
        }
    }
    return 0;
}