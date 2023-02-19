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
    \ { // 1 indexed\n    int n;\n    vector<T> data;\n    FenwickTree() : n(0) {}\n\
    \    FenwickTree(int n) : n(n), data(n+1, 0) {}\n\n    // a[id] += x\n    void\
    \ add(int id, T x) {\n        for (int i = id; i <= n; i += i & -i) {\n      \
    \      data[i] += x;\n        }\n    }\n    void range_add(int l, int r, T val)\
    \ {\n        add(l, val);\n        add(r + 1, -val);\n    }\n\n    // [1, r]\n\
    \    T sum(int r) {\n        T s(0);\n        for (int i = r; i > 0; i -= i &\
    \ -i) {\n            s += data[i];\n        }\n        return s;\n    }\n    //\
    \ [l, r]\n    T sum(int l, int r) {\n        return sum(r) - sum(l-1);\n    }\n\
    };\n"
  code: "#pragma once\n\ntemplate <class T> struct FenwickTree { // 1 indexed\n  \
    \  int n;\n    vector<T> data;\n    FenwickTree() : n(0) {}\n    FenwickTree(int\
    \ n) : n(n), data(n+1, 0) {}\n\n    // a[id] += x\n    void add(int id, T x) {\n\
    \        for (int i = id; i <= n; i += i & -i) {\n            data[i] += x;\n\
    \        }\n    }\n    void range_add(int l, int r, T val) {\n        add(l, val);\n\
    \        add(r + 1, -val);\n    }\n\n    // [1, r]\n    T sum(int r) {\n     \
    \   T s(0);\n        for (int i = r; i > 0; i -= i & -i) {\n            s += data[i];\n\
    \        }\n        return s;\n    }\n    // [l, r]\n    T sum(int l, int r) {\n\
    \        return sum(r) - sum(l-1);\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: ds/fenwickTree.hpp
  requiredBy: []
  timestamp: '2023-02-20 02:23:17+06:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/DSL_2_B-RSQ.fenwick.test.cpp
documentation_of: ds/fenwickTree.hpp
layout: document
title: Fenwick Tree
---

#### overview



## Resoources

- https://cp-algorithms.com/data_structures/fenwick.html#2-range-update-and-point-query
- https://www.youtube.com/watch?v=RgITNht_f4Q&list=PLDV1Zeh2NRsB6SWUrDFW2RmDotAfPbeHu&index=38
