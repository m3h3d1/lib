---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"ds/fenwickTree_0indexed.hpp\"\ntemplate <class T> struct\
    \ FenwickTree {\n    int n;\n    vector<T> data;\n    FenwickTree() : n(0) {}\n\
    \    FenwickTree(int n) : n(n), data(n, 0) {}\n\n    // a[i] += x\n    void add(int\
    \ i, T x) {\n        for (int p = i + 1; p <= n; p += p & -p) data[p - 1] += x;\n\
    \    }\n    // [0, r)\n    T sum(int r) {\n        T s(0);\n        for (int p\
    \ = r; p > 0; p -= p & -p) s += data[p - 1];\n        return s;\n    }\n    //\
    \ [l, r)\n    T sum(int l, int r) {\n        return sum(r) - sum(l);\n    }\n\
    };\n"
  code: "template <class T> struct FenwickTree {\n    int n;\n    vector<T> data;\n\
    \    FenwickTree() : n(0) {}\n    FenwickTree(int n) : n(n), data(n, 0) {}\n\n\
    \    // a[i] += x\n    void add(int i, T x) {\n        for (int p = i + 1; p <=\
    \ n; p += p & -p) data[p - 1] += x;\n    }\n    // [0, r)\n    T sum(int r) {\n\
    \        T s(0);\n        for (int p = r; p > 0; p -= p & -p) s += data[p - 1];\n\
    \        return s;\n    }\n    // [l, r)\n    T sum(int l, int r) {\n        return\
    \ sum(r) - sum(l);\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: ds/fenwickTree_0indexed.hpp
  requiredBy: []
  timestamp: '2023-02-20 02:23:17+06:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: ds/fenwickTree_0indexed.hpp
layout: document
redirect_from:
- /library/ds/fenwickTree_0indexed.hpp
- /library/ds/fenwickTree_0indexed.hpp.html
title: ds/fenwickTree_0indexed.hpp
---
