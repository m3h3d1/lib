#include <bits/stdc++.h>
using namespace std;
#include "../acl_segtree.hpp"

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

int op(int a, int b) {
	return max(a, b);
}

int e() {
	return -1;
}

int target;
int f(int v) {
	return v < target;
}

int main() {
    ios_base::sync_with_stdio(0);
    int n, q;
    cin>>n>>q;
    vector<int> A(n);
    for(int i=0; i<n; ++i) {
    	cin>>A[i];
    }
    atcoder::segtree<int, op, e> seg(A);

    while(q--) {
    	int typ;
    	cin>>typ;
    	if(typ == 1) {
    		int id, val;
    		cin>>id>>val;
    		id--;
    		seg.set(id, val);
    	} else if(typ == 2) {
    		int l, r;
    		cin>>l>>r;
    		l--;
    		cout<<seg.prod(l, r)<<en;
    	} else if(typ == 3) {
    		int p;
    		cin>>p>>target;
    		p--;
    		cout<<seg.max_right(p, f)+1<<en;
    	}
    }
    return 0;
}