---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL_2_B-RSQ.fenwick.test.cpp
    title: test/aoj/DSL_2_B-RSQ.fenwick.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"ds/fenwickTree.hpp\"\n\ntemplate <class T> struct FenwickTree\
    \ {\n    int n;\n    vector<T> data;\n    FenwickTree() : n(0) {}\n    FenwickTree(int\
    \ n) : n(n), data(n, 0) {}\n\n    // a[i] += x\n    void add(int i, T x) {\n \
    \       for (int p = i + 1; p <= n; p += p & -p) data[p - 1] += x;\n    }\n  \
    \  // [0, r)\n    T sum(int r) {\n        T s(0);\n        for (int p = r; p >\
    \ 0; p -= p & -p) s += data[p - 1];\n        return s;\n    }\n    // [l, r)\n\
    \    T sum(int l, int r) {\n        return sum(r) - sum(l);\n    }\n};\n"
  code: "#pragma once\n\ntemplate <class T> struct FenwickTree {\n    int n;\n   \
    \ vector<T> data;\n    FenwickTree() : n(0) {}\n    FenwickTree(int n) : n(n),\
    \ data(n, 0) {}\n\n    // a[i] += x\n    void add(int i, T x) {\n        for (int\
    \ p = i + 1; p <= n; p += p & -p) data[p - 1] += x;\n    }\n    // [0, r)\n  \
    \  T sum(int r) {\n        T s(0);\n        for (int p = r; p > 0; p -= p & -p)\
    \ s += data[p - 1];\n        return s;\n    }\n    // [l, r)\n    T sum(int l,\
    \ int r) {\n        return sum(r) - sum(l);\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: ds/fenwickTree.hpp
  requiredBy: []
  timestamp: '2023-01-15 01:54:03+06:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/DSL_2_B-RSQ.fenwick.test.cpp
documentation_of: ds/fenwickTree.hpp
layout: document
redirect_from:
- /library/ds/fenwickTree.hpp
- /library/ds/fenwickTree.hpp.html
title: ds/fenwickTree.hpp
---
