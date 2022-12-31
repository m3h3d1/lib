#include "../../template/template.hpp"
#include "../union_find.hpp"
#define PROBLEM "https://judge.yosupo.jp/problem/unionfind"

int main() {
    ios_base::sync_with_stdio(0);
    int n, q, typ, u, v;
    cin>>n>>q;
    DSU dsu(n);
    while(q--) {
    	cin>>typ>>u>>v;
    	if(typ==0) {
    		dsu.unite(u, v);
    	} else {
    		cout<<dsu.same_set(u, v)<<'\n';
    	}
    }
    return 0;
}