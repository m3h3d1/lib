#define PROBLEM "https://judge.yosupo.jp/problem/unionfind"

#include "../../../template/template.hpp"
#include "../../../ds/union-find.hpp"

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
    		cout<<dsu.same_set(u, v)<<en;
    	}
    }
    return 0;
}