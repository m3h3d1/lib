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
    _deprecated_at_docs: docs/ds/union-find.md
    document_title: Union Find
    links: []
  bundledCode: "#line 1 \"ds/union-find.hpp\"\nstruct DSU {\n\tvector<int> e;\n\t\
    DSU(int n) { e = vector<int>(n, -1); }\n\n\t// get representive component (uses\
    \ path compression)\n\tint get(int x) { return e[x] < 0 ? x : e[x] = get(e[x]);\
    \ }\n\n\tbool same_set(int a, int b) { return get(a) == get(b); }\n\n\tint size(int\
    \ x) { return -e[get(x)]; }\n\n\tbool unite(int x, int y) {  // union by size\n\
    \t\tx = get(x), y = get(y);\n\t\tif (x == y) return false;\n\t\tif (e[x] > e[y])\
    \ swap(x, y);\n\t\te[x] += e[y]; e[y] = x; return true;\n\t}\n};\n\n/**\n * @brief\
    \ Union Find\n * @docs docs/ds/union-find.md\n */\n"
  code: "struct DSU {\n\tvector<int> e;\n\tDSU(int n) { e = vector<int>(n, -1); }\n\
    \n\t// get representive component (uses path compression)\n\tint get(int x) {\
    \ return e[x] < 0 ? x : e[x] = get(e[x]); }\n\n\tbool same_set(int a, int b) {\
    \ return get(a) == get(b); }\n\n\tint size(int x) { return -e[get(x)]; }\n\n\t\
    bool unite(int x, int y) {  // union by size\n\t\tx = get(x), y = get(y);\n\t\t\
    if (x == y) return false;\n\t\tif (e[x] > e[y]) swap(x, y);\n\t\te[x] += e[y];\
    \ e[y] = x; return true;\n\t}\n};\n\n/**\n * @brief Union Find\n * @docs docs/ds/union-find.md\n\
    \ */"
  dependsOn: []
  isVerificationFile: false
  path: ds/union-find.hpp
  requiredBy: []
  timestamp: '2022-12-29 04:24:58+06:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - ds/test/yosupo_unionfind.test.cpp
documentation_of: ds/union-find.hpp
layout: document
redirect_from:
- /library/ds/union-find.hpp
- /library/ds/union-find.hpp.html
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

https://usaco.guide/gold/dsu

#### Usage
