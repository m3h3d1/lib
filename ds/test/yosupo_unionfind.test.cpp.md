---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: ds/union-find.hpp
    title: Union Find
  - icon: ':question:'
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
  bundledCode: "#line 1 \"ds/test/yosupo_unionfind.test.cpp\"\n#define PROBLEM \"\
    https://judge.yosupo.jp/problem/unionfind\"\n\n#line 1 \"template/template.hpp\"\
    \n#include<bits/stdc++.h>\nusing namespace std;\n\n#define ff first\n#define ss\
    \ second\n#define pb push_back\ntypedef long long ll;\ntypedef pair<int,int> pii;\n\
    #define all(v) (v).begin(),(v).end()\n#define db(x) cerr<<__LINE__<<\": \"<<#x<<\"\
    \ = \"<<(x)<<'\\n'\nconst char en = '\\n';\nconst int inf = 1e9+7;\nconst int\
    \ N = 1e6+9;\n#line 1 \"ds/union-find.hpp\"\nstruct DSU {\n\tvector<int> e;\n\t\
    DSU(int n) { e = vector<int>(n, -1); }\n\n\t// get representive component (uses\
    \ path compression)\n\tint get(int x) { return e[x] < 0 ? x : e[x] = get(e[x]);\
    \ }\n\n\tbool same_set(int a, int b) { return get(a) == get(b); }\n\n\tint size(int\
    \ x) { return -e[get(x)]; }\n\n\tbool unite(int x, int y) {  // union by size\n\
    \t\tx = get(x), y = get(y);\n\t\tif (x == y) return false;\n\t\tif (e[x] > e[y])\
    \ swap(x, y);\n\t\te[x] += e[y]; e[y] = x; return true;\n\t}\n};\n\n/**\n * @brief\
    \ Union Find\n * @docs docs/ds/union-find.md\n */\n#line 5 \"ds/test/yosupo_unionfind.test.cpp\"\
    \n\nint main() {\n    ios_base::sync_with_stdio(0);\n    int n, q, typ, u, v;\n\
    \    cin>>n>>q;\n    DSU dsu(n);\n    while(q--) {\n    \tcin>>typ>>u>>v;\n  \
    \  \tif(typ==0) {\n    \t\tdsu.unite(u, v);\n    \t} else {\n    \t\tcout<<dsu.same_set(u,\
    \ v)<<'\\n';\n    \t}\n    }\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/unionfind\"\n\n#include\
    \ \"../../template/template.hpp\"\n#include \"../union-find.hpp\"\n\nint main()\
    \ {\n    ios_base::sync_with_stdio(0);\n    int n, q, typ, u, v;\n    cin>>n>>q;\n\
    \    DSU dsu(n);\n    while(q--) {\n    \tcin>>typ>>u>>v;\n    \tif(typ==0) {\n\
    \    \t\tdsu.unite(u, v);\n    \t} else {\n    \t\tcout<<dsu.same_set(u, v)<<'\\\
    n';\n    \t}\n    }\n    return 0;\n}"
  dependsOn:
  - template/template.hpp
  - ds/union-find.hpp
  isVerificationFile: true
  path: ds/test/yosupo_unionfind.test.cpp
  requiredBy: []
  timestamp: '2022-12-29 04:24:58+06:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: ds/test/yosupo_unionfind.test.cpp
layout: document
redirect_from:
- /verify/ds/test/yosupo_unionfind.test.cpp
- /verify/ds/test/yosupo_unionfind.test.cpp.html
title: ds/test/yosupo_unionfind.test.cpp
---
