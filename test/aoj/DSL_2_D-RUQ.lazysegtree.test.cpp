#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_B"
#include <bits/stdc++.h>
using namespace std;
#include "../../segtree/lazysegtree.hpp"

#define ff first
#define ss second
#define pb push_back
typedef long long ll;
typedef pair<int,int> pii;
#define all(v) (v).begin(),(v).end()
#define db(x) cerr<<__LINE__<<": "<<#x<<" = "<<(x)<<'\n'
const char en = '\n';
const int inf = INT32_MAX;
const int N = 1e6+9;

int op(int a, int b) { return a < b; }
int e() { return inf; }
int mapping(int f, int x) { return (f == inf ? x : f); }
int composition(int f, int g) { return (f == inf ? g : f); }
int id() { return inf; }

int main() {
    ios_base::sync_with_stdio(0);
    int n, q;
    cin>>n>>q;
    LazySegmentTree<int, op, e, int, mapping, composition, id> seg(n);
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