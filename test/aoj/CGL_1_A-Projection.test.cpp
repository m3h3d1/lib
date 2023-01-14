#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/CGL_1_A"
#include <bits/stdc++.h>
using namespace std;
#include "../../geometry/2dPointAndVector.hpp"

int main() {
    ios_base::sync_with_stdio(0);
    Point p1, p2;
    cin>>p1>>p2;
    Line l = Line(p1, p2);

    int q;
    cin>>q;
    while(q--) {
        Point p;
        cin>>p;
        cout<<projection(l, p)<<'\n';
    }
    return 0;
}