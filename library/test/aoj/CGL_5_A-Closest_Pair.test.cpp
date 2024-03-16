#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/CGL_5_A"
#include <bits/stdc++.h>
using namespace std;
#include "../../geometry/2dPointSet.hpp"
#define ERROR 0.000001

int main() {
    ios_base::sync_with_stdio(0);
    int n;
    cin>>n;
    Polygon ps(n);
    for(int i=0;i<n;++i) {
        cin>>ps[i];
    }
    cout<<fixed<<setprecision(20)<<closest_pair(ps)<<'\n';
    return 0;
}