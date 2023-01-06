#include <bits/stdc++.h>
using namespace std;
// #include "../../math/extgcd.hpp"

template<class T> 
T extgcd(T a, T b, T &x, T &y) {
  T d = a;
  if(b != 0) {
    d = extgcd(b, a%b, y, x);
    y -= (a/b) * x;
  } else {
    x = 1;
    y = 0;
  }
  return d;
}

int main() {
    ios_base::sync_with_stdio(0);
    int a, b, x, y;
    cin>>a>>b;
    extgcd(a, b, x, y);
    cout<<x<<" "<<y<<'\n';
    return 0;
}