#define PROBLEM "https://judge.yosupo.jp/problem/predecessor_problem"
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

int op(int a, int b) { return a | b; }
int e() { return 0; }
int f(int a) {
    return !a;
}

int main() {
    ios_base::sync_with_stdio(0);
    int n, q;
    string s;
    cin>>n>>q>>s;
    vector<int> v(n);
    for(int i=0;i<n;++i) 
        if(s[i]=='1') v[i] = 1;
    SegmentTree<int, op, e> seg(v);
    while(q--) {
        int typ, k;
        cin>>typ>>k;
        if(typ==0) {
            if(!seg.get(k))
                seg.set(k, 1);
        } else if(typ==1) {
            if(seg.get(k))
                seg.set(k, 0);
        } else if(typ==2) {
            if(seg.get(k))
                cout<<"1\n";
            else cout<<"0\n";
        } else if(typ==3) {
            int res = seg.max_right(k, f);
            if(res==n) res = -1;
            cout<<res<<en;
        } else if(typ==4) {
            int res = seg.min_left(k+1, f);
            --res;
            cout<<res<<en;
        }
    }
    return 0;
}