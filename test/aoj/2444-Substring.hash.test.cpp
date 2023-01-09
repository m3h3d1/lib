#include <bits/stdc++.h>
using namespace std;
#include "../../string/rollingHash.hpp"
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/2444"
#define ll long long

int main() {
    ios_base::sync_with_stdio(0);
    string str, s;
    int n, q;
    cin>>n>>q; cin.ignore();
    getline(cin, str);

    RollingHash rh(str);
    set<pair<ll, ll>> st;
    int l=0, r=0;
    while(q--) {
        cin>>s;
        if(s=="L++") {
            l++;
        } else if(s=="L--") {
            l--;
        } else if(s=="R++") {
            r++;
        } else {
            r--;
        }
        assert(l>=0 && r>=0);
        st.insert({rh.get(l, r+1, 0), rh.get(l, r+1, 1)});
    }    
    cout<<st.size()<<'\n';
    return 0;
}