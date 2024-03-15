#include <bits/stdc++.h>
using namespace std;
#include "../../ds/fenwickTree.hpp"
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/DSL_2_B"

int main() {
    ios_base::sync_with_stdio(0);
    int n, q;
    cin>>n>>q;
    FenwickTree<long long> ft(n);

    while(q--) {
        int typ;
        cin>>typ;
        if(typ==0) {
            int id, x;
            cin>>id>>x;
            ft.add(id, x);
        } else {
            int a, b;
            cin>>a>>b;
            cout<<ft.sum(a, b)<<'\n';
        }
    }
    return 0;
}