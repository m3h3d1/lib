#include <bits/stdc++.h>
using namespace std;
#include "../../string/rollingHash2d.hpp"
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/ALDS1_14_C"

int main() {
    ios_base::sync_with_stdio(0);
    int h, w;
    cin>>h>>w;
    vector<string> s(h);
    for(int i=0;i<h;++i) {
        cin>>s[i];
    }
    int r, c;
    cin>>r>>c;
    vector<string> t(r);
    for(int i=0;i<r;++i) {
        cin>>t[i];
    }
    RollingHash2D rhs(s), rht(t);

    for(int i=0;i<h;++i) {
        for(int j=0;j<w;++j) {
            if(i+r<=h && j+c<=w) {
                if(match(rhs, i, i+r, j, j+c, rht, 0, r, 0, c)) {
                    cout<<i<<" "<<j<<'\n';
                }
            }
        }
    }
    return 0;
}