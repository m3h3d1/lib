#include <bits/stdc++.h>
using namespace std;
#include "../../string/rollingHash.hpp"
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/ALDS1_14_B"

int main() {
    ios_base::sync_with_stdio(0);
    string s, t;
    cin>>s>>t;  
    int n = s.size(), m = t.size();
    RollingHash hs(s), ht(t);
    for(int i=0;i<n-m+1;++i) {
        if(match(hs, i, i+m, ht, 0, m)) {
            cout<<i<<'\n';
        }
    }
    return 0;
}