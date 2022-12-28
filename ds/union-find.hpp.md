---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/ds/Unionfind.test.cpp
    title: test/yosupo/ds/Unionfind.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - https://usaco.guide/gold/dsu?lang=cpp#implementation
  bundledCode: "#line 2 \"ds/union-find.hpp\"\n\n/**\n * Description: Disjoint Set\
    \ Union with path compression\n \t* and union by size. Add edges and test connectivity.\
    \ \n \t* Use for Kruskal's or Boruvka's minimum spanning tree.\n * Time: O(\\\
    alpha(N))\n * Source: CSAcademy, KACTL\n * Verification: *\n */\n\nstruct DSU\
    \ {\n\tvector<int> e;\n\tDSU(int n) { e = vector<int>(n, -1); }\n\n\t// get representive\
    \ component (uses path compression)\n\tint get(int x) { return e[x] < 0 ? x :\
    \ e[x] = get(e[x]); }\n\n\tbool same_set(int a, int b) { return get(a) == get(b);\
    \ }\n\n\tint size(int x) { return -e[get(x)]; }\n\n\tbool unite(int x, int y)\
    \ {  // union by size\n\t\tx = get(x), y = get(y);\n\t\tif (x == y) return false;\n\
    \t\tif (e[x] > e[y]) swap(x, y);\n\t\te[x] += e[y]; e[y] = x; return true;\n\t\
    }\n};\n\n/**tcT> T kruskal(int N, vector<pair<T,pi>> ed) {\n\tsort(all(ed));\n\
    \tT ans = 0; DSU D; D.init(N); // edges that unite are in MST\n\teach(a,ed) if\
    \ (D.unite(a.s.f,a.s.s)) ans += a.f; \n\treturn ans;\n}*/\n\n// https://usaco.guide/gold/dsu?lang=cpp#implementation\n"
  code: "#pragma once\n\n/**\n * Description: Disjoint Set Union with path compression\n\
    \ \t* and union by size. Add edges and test connectivity. \n \t* Use for Kruskal's\
    \ or Boruvka's minimum spanning tree.\n * Time: O(\\alpha(N))\n * Source: CSAcademy,\
    \ KACTL\n * Verification: *\n */\n\nstruct DSU {\n\tvector<int> e;\n\tDSU(int\
    \ n) { e = vector<int>(n, -1); }\n\n\t// get representive component (uses path\
    \ compression)\n\tint get(int x) { return e[x] < 0 ? x : e[x] = get(e[x]); }\n\
    \n\tbool same_set(int a, int b) { return get(a) == get(b); }\n\n\tint size(int\
    \ x) { return -e[get(x)]; }\n\n\tbool unite(int x, int y) {  // union by size\n\
    \t\tx = get(x), y = get(y);\n\t\tif (x == y) return false;\n\t\tif (e[x] > e[y])\
    \ swap(x, y);\n\t\te[x] += e[y]; e[y] = x; return true;\n\t}\n};\n\n/**tcT> T\
    \ kruskal(int N, vector<pair<T,pi>> ed) {\n\tsort(all(ed));\n\tT ans = 0; DSU\
    \ D; D.init(N); // edges that unite are in MST\n\teach(a,ed) if (D.unite(a.s.f,a.s.s))\
    \ ans += a.f; \n\treturn ans;\n}*/\n\n// https://usaco.guide/gold/dsu?lang=cpp#implementation"
  dependsOn: []
  isVerificationFile: false
  path: ds/union-find.hpp
  requiredBy: []
  timestamp: '2022-12-28 14:55:33+06:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/ds/Unionfind.test.cpp
documentation_of: ds/union-find.hpp
layout: document
redirect_from:
- /library/ds/union-find.hpp
- /library/ds/union-find.hpp.html
title: ds/union-find.hpp
---
