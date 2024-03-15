#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/CGL_2_C"
#include <bits/stdc++.h>
using namespace std;
#include "../../geometry/2dSegmentAndLine.hpp"
#define ERROR 0.00000001

int main() {
    ios_base::sync_with_stdio(0);
    int q;
    cin>>q;
    while(q--) {
        Point p0, p1, p2, p3;
        cin>>p0>>p1>>p2>>p3;
        Line l1 = Line(p0, p1);
        Line l2 = Line(p2, p3);

        Point p = cross_point_ll(l1, l2);

        cout<<p<<'\n';
    }
    return 0;
}