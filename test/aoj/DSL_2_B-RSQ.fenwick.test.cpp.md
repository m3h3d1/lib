---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: ds/fenwickTree.hpp
    title: Fenwick Tree
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/problems/DSL_2_B
    links:
    - https://onlinejudge.u-aizu.ac.jp/problems/DSL_2_B
  bundledCode: "#line 1 \"test/aoj/DSL_2_B-RSQ.fenwick.test.cpp\"\n#include <bits/stdc++.h>\n\
    using namespace std;\n#line 2 \"ds/fenwickTree.hpp\"\n\ntemplate <class T> struct\
    \ FenwickTree { // 1 indexed\n    int n;\n    vector<T> data;\n    FenwickTree()\
    \ : n(0) {}\n    FenwickTree(int n) : n(n), data(n+1, 0) {}\n\n    // a[id] +=\
    \ x\n    void add(int id, T x) {\n        for (int i = id; i <= n; i += i & -i)\
    \ {\n            data[i] += x;\n        }\n    }\n    void range_add(int l, int\
    \ r, T val) {\n        add(l, val);\n        add(r + 1, -val);\n    }\n\n    //\
    \ [1, r]\n    T sum(int r) {\n        T s(0);\n        for (int i = r; i > 0;\
    \ i -= i & -i) {\n            s += data[i];\n        }\n        return s;\n  \
    \  }\n    // [l, r]\n    T sum(int l, int r) {\n        return sum(r) - sum(l-1);\n\
    \    }\n};\n#line 4 \"test/aoj/DSL_2_B-RSQ.fenwick.test.cpp\"\n#define PROBLEM\
    \ \"https://onlinejudge.u-aizu.ac.jp/problems/DSL_2_B\"\n\nint main() {\n    ios_base::sync_with_stdio(0);\n\
    \    int n, q;\n    cin>>n>>q;\n    FenwickTree<long long> ft(n);\n\n    while(q--)\
    \ {\n        int typ;\n        cin>>typ;\n        if(typ==0) {\n            int\
    \ id, x;\n            cin>>id>>x;\n            ft.add(id, x);\n        } else\
    \ {\n            int a, b;\n            cin>>a>>b;\n            cout<<ft.sum(a,\
    \ b)<<'\\n';\n        }\n    }\n    return 0;\n}\n"
  code: "#include <bits/stdc++.h>\nusing namespace std;\n#include \"../../ds/fenwickTree.hpp\"\
    \n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/DSL_2_B\"\n\nint\
    \ main() {\n    ios_base::sync_with_stdio(0);\n    int n, q;\n    cin>>n>>q;\n\
    \    FenwickTree<long long> ft(n);\n\n    while(q--) {\n        int typ;\n   \
    \     cin>>typ;\n        if(typ==0) {\n            int id, x;\n            cin>>id>>x;\n\
    \            ft.add(id, x);\n        } else {\n            int a, b;\n       \
    \     cin>>a>>b;\n            cout<<ft.sum(a, b)<<'\\n';\n        }\n    }\n \
    \   return 0;\n}"
  dependsOn:
  - ds/fenwickTree.hpp
  isVerificationFile: true
  path: test/aoj/DSL_2_B-RSQ.fenwick.test.cpp
  requiredBy: []
  timestamp: '2023-02-20 02:23:17+06:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/DSL_2_B-RSQ.fenwick.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/DSL_2_B-RSQ.fenwick.test.cpp
- /verify/test/aoj/DSL_2_B-RSQ.fenwick.test.cpp.html
title: test/aoj/DSL_2_B-RSQ.fenwick.test.cpp
---
