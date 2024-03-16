#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/CGL_2_D"
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
        Segment s1 = Segment(p0, p1);
        Segment s2 = Segment(p2, p3);

        Real d = distance_ss(s1, s2);

        cout<<fixed<<setprecision(12)<<d<<'\n';
    }
    return 0;
}