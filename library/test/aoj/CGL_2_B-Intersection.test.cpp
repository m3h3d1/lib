#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/CGL_2_B"
#include <bits/stdc++.h>
using namespace std;
#include "../../geometry/2dSegmentAndLine.hpp"

int main() {
    ios_base::sync_with_stdio(0);
    int q;
    cin>>q;
    while(q--) {
        Point p0, p1, p2, p3;
        cin>>p0>>p1>>p2>>p3;
        Line l1 = Line(p0, p1);
        Line l2 = Line(p2, p3);

        if(is_intersect_ss(l1, l2)) {
            cout<<"1\n";
        } else {
            cout<<"0\n";
        }
    }
    return 0;
}