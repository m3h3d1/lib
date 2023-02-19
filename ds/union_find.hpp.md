---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: ds/test/yosupo_unionfind.test.cpp
    title: ds/test/yosupo_unionfind.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"ds/union_find.hpp\"\nstruct DSU {\n    vector<int> par;\n\
    \    int cc; // connected components\n    DSU(int n): par(n, -1), cc(n) { }\n\n\
    \    // get representive component (uses path compression)\n    int get(int x)\
    \ { return par[x] < 0 ? x : par[x] = get(par[x]); }\n\n    bool same_set(int a,\
    \ int b) { return get(a) == get(b); }\n\n    int size(int x) { return -par[get(x)];\
    \ }\n\n    int groups() { return cc; } // number of groups\n\n    int leader(int\
    \ v) const {\n        assert(0 <= a && a < _n);\n        while (par[v] > -1) v\
    \ = par[v];\n        return v;\n    }\n\n    void unite(int x, int y) {  // union\
    \ by size\n        x = get(x), y = get(y);\n        if (x == y) return;\n    \
    \    cc--;\n        if (par[x] > par[y]) swap(x, y);\n        par[x] += par[y];\
    \ par[y] = x;\n    }\n};\n"
  code: "struct DSU {\n    vector<int> par;\n    int cc; // connected components\n\
    \    DSU(int n): par(n, -1), cc(n) { }\n\n    // get representive component (uses\
    \ path compression)\n    int get(int x) { return par[x] < 0 ? x : par[x] = get(par[x]);\
    \ }\n\n    bool same_set(int a, int b) { return get(a) == get(b); }\n\n    int\
    \ size(int x) { return -par[get(x)]; }\n\n    int groups() { return cc; } // number\
    \ of groups\n\n    int leader(int v) const {\n        assert(0 <= a && a < _n);\n\
    \        while (par[v] > -1) v = par[v];\n        return v;\n    }\n\n    void\
    \ unite(int x, int y) {  // union by size\n        x = get(x), y = get(y);\n \
    \       if (x == y) return;\n        cc--;\n        if (par[x] > par[y]) swap(x,\
    \ y);\n        par[x] += par[y]; par[y] = x;\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: ds/union_find.hpp
  requiredBy: []
  timestamp: '2023-02-20 02:23:17+06:00'
  verificationStatus: LIBRARY_ALL_WA
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