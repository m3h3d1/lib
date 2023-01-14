#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/CGL_1_C"
#include <bits/stdc++.h>
using namespace std;
#include "../../geometry/2dPointAndVector.hpp"

int main() {
    ios_base::sync_with_stdio(0);
    Point p1, p2;
    cin>>p1>>p2;

    int q;
    cin>>q;
    while(q--) {
        Point p;
        cin>>p;
        int x = ccw(p1, p2, p);
        if(x == 1) cout<<"COUNTER_CLOCKWISE\n";
        else if(x == -1) cout<<"CLOCKWISE\n";
        else if(x == 2) cout<<"ONLINE_BACK\n";
        else if(x == -2) cout<<"ONLINE_FRONT\n";
        else if(x == 0) cout<<"ON_SEGMENT\n";
    }
    return 0;
}