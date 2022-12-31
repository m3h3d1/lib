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
  bundledCode: "#line 1 \"ds/union_find.hpp\"\nstruct DSU {\n\tvector<int> e;\n\t\
    DSU(int n) { e = vector<int>(n, -1); }\n\n\t// get representive component (uses\
    \ path compression)\n\tint get(int x) { return e[x] < 0 ? x : e[x] = get(e[x]);\
    \ }\n\n\tbool same_set(int a, int b) { return get(a) == get(b); }\n\n\tint size(int\
    \ x) { return -e[get(x)]; }\n\n\tbool unite(int x, int y) {  // union by size\n\
    \t\tx = get(x), y = get(y);\n\t\tif (x == y) return false;\n\t\tif (e[x] > e[y])\
    \ swap(x, y);\n\t\te[x] += e[y]; e[y] = x; return true;\n\t}\n};\n"
  code: "struct DSU {\n\tvector<int> e;\n\tDSU(int n) { e = vector<int>(n, -1); }\n\
    \n\t// get representive component (uses path compression)\n\tint get(int x) {\
    \ return e[x] < 0 ? x : e[x] = get(e[x]); }\n\n\tbool same_set(int a, int b) {\
    \ return get(a) == get(b); }\n\n\tint size(int x) { return -e[get(x)]; }\n\n\t\
    bool unite(int x, int y) {  // union by size\n\t\tx = get(x), y = get(y);\n\t\t\
    if (x == y) return false;\n\t\tif (e[x] > e[y]) swap(x, y);\n\t\te[x] += e[y];\
    \ e[y] = x; return true;\n\t}\n};"
  dependsOn: []
  isVerificationFile: false
  path: ds/union_find.hpp
  requiredBy: []
  timestamp: '2022-12-31 10:34:10+06:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: ds/union_find.hpp
layout: document
redirect_from:
- /library/ds/union_find.hpp
- /library/ds/union_find.hpp.html
title: ds/union_find.hpp
---
