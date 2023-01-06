#include <bits/stdc++.h>
using namespace std;
#include "../../math/extgcd.hpp"
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/NTL_1_E"

int main() {
    ios_base::sync_with_stdio(0);
    int a, b, x, y;
    cin>>a>>b;
    extgcd(a, b, x, y);
    cout<<x<<" "<<y<<'\n';
    return 0;
}