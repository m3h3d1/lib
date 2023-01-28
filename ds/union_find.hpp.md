---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: ds/test/yosupo_unionfind.test.cpp
    title: ds/test/yosupo_unionfind.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"ds/union_find.hpp\"\nstruct DSU {\n    vector<int> e;\n\
    \    int cc; // connected components\n    DSU(int n): e(n, -1), cc(n) { }\n\n\
    \    // get representive component (uses path compression)\n    int get(int x)\
    \ { return e[x] < 0 ? x : e[x] = get(e[x]); }\n\n    bool same_set(int a, int\
    \ b) { return get(a) == get(b); }\n\n    int size(int x) { return -e[get(x)];\
    \ }\n\n    int groups() { return cc; } // number of groups\n\n    bool unite(int\
    \ x, int y) {  // union by size\n        x = get(x), y = get(y);\n        if (x\
    \ == y) return false;\n        cc--;\n        if (e[x] > e[y]) swap(x, y);\n \
    \       e[x] += e[y]; e[y] = x; return true;\n    }\n};\n"
  code: "struct DSU {\n    vector<int> e;\n    int cc; // connected components\n \
    \   DSU(int n): e(n, -1), cc(n) { }\n\n    // get representive component (uses\
    \ path compression)\n    int get(int x) { return e[x] < 0 ? x : e[x] = get(e[x]);\
    \ }\n\n    bool same_set(int a, int b) { return get(a) == get(b); }\n\n    int\
    \ size(int x) { return -e[get(x)]; }\n\n    int groups() { return cc; } // number\
    \ of groups\n\n    bool unite(int x, int y) {  // union by size\n        x = get(x),\
    \ y = get(y);\n        if (x == y) return false;\n        cc--;\n        if (e[x]\
    \ > e[y]) swap(x, y);\n        e[x] += e[y]; e[y] = x; return true;\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: ds/union_find.hpp
  requiredBy: []
  timestamp: '2023-01-28 23:01:04+06:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - ds/test/yosupo_unionfind.test.cpp
documentation_of: ds/union_find.hpp
layout: document
title: Union Find
---

## Union-Find Tree(Disjoint Set Union)

#### overview

- Joins two subsets into a single subset.
- Check if vertices $x, y$ belongs to the same set.

Description: Disjoint Set Union with path compression
	and union by size. Add edges and test connectivity. 
	Use for Kruskal's or Boruvka's minimum spanning tree.
Time: $\mathrm{O}(\alpha(N))$

## Link

- https://usaco.guide/gold/dsu