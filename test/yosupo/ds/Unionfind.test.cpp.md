---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: ds/union-find.hpp
    title: Union Find
  - icon: ':heavy_check_mark:'
    path: template/template.hpp
    title: template/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/unionfind
    links:
    - https://judge.yosupo.jp/problem/unionfind
  bundledCode: "#line 1 \"test/yosupo/ds/Unionfind.test.cpp\"\n#define PROBLEM \"\
    https://judge.yosupo.jp/problem/unionfind\"\n\n#line 2 \"template/template.hpp\"\
    \n\n#include<bits/stdc++.h>\nusing namespace std;\n\n#define ff first\n#define\
    \ ss second\n#define pb push_back\ntypedef long long ll;\ntypedef pair<int,int>\
    \ pii;\n#define all(v) (v).begin(),(v).end()\n#define db(x) cerr<<__LINE__<<\"\
    : \"<<#x<<\" = \"<<(x)<<'\\n'\nconst char en = '\\n';\nconst int inf = 1e9+7;\n\
    const int N = 1e6+9;\n#line 2 \"ds/union-find.hpp\"\n\n/**\n * Description: Disjoint\
    \ Set Union with path compression\n \t* and union by size. Add edges and test\
    \ connectivity. \n \t* Use for Kruskal's or Boruvka's minimum spanning tree.\n\
    \ * Time: O(\\alpha(N))\n * Source: CSAcademy, KACTL\n * Verification: *\n */\n\
    \nstruct DSU {\n\tvector<int> e;\n\tDSU(int n) { e = vector<int>(n, -1); }\n\n\
    \t// get representive component (uses path compression)\n\tint get(int x) { return\
    \ e[x] < 0 ? x : e[x] = get(e[x]); }\n\n\tbool same_set(int a, int b) { return\
    \ get(a) == get(b); }\n\n\tint size(int x) { return -e[get(x)]; }\n\n\tbool unite(int\
    \ x, int y) {  // union by size\n\t\tx = get(x), y = get(y);\n\t\tif (x == y)\
    \ return false;\n\t\tif (e[x] > e[y]) swap(x, y);\n\t\te[x] += e[y]; e[y] = x;\
    \ return true;\n\t}\n};\n\n/**\n * @brief Union Find\n * @docs docs/ds/union-find.md\n\
    \ */\n#line 5 \"test/yosupo/ds/Unionfind.test.cpp\"\n\nint main() {\n    ios_base::sync_with_stdio(0);\n\
    \    int n, q, typ, u, v;\n    cin>>n>>q;\n    DSU dsu(n);\n    while(q--) {\n\
    \    \tcin>>typ>>u>>v;\n    \tif(typ==0) {\n    \t\tdsu.unite(u, v);\n    \t}\
    \ else {\n    \t\tcout<<dsu.same_set(u, v)<<en;\n    \t}\n    }\n    return 0;\n\
    }\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/unionfind\"\n\n#include\
    \ \"../../../template/template.hpp\"\n#include \"../../../ds/union-find.hpp\"\n\
    \nint main() {\n    ios_base::sync_with_stdio(0);\n    int n, q, typ, u, v;\n\
    \    cin>>n>>q;\n    DSU dsu(n);\n    while(q--) {\n    \tcin>>typ>>u>>v;\n  \
    \  \tif(typ==0) {\n    \t\tdsu.unite(u, v);\n    \t} else {\n    \t\tcout<<dsu.same_set(u,\
    \ v)<<en;\n    \t}\n    }\n    return 0;\n}"
  dependsOn:
  - template/template.hpp
  - ds/union-find.hpp
  isVerificationFile: true
  path: test/yosupo/ds/Unionfind.test.cpp
  requiredBy: []
  timestamp: '2022-12-28 15:35:09+06:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/ds/Unionfind.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/ds/Unionfind.test.cpp
- /verify/test/yosupo/ds/Unionfind.test.cpp.html
title: test/yosupo/ds/Unionfind.test.cpp
---
