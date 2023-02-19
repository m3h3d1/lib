---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: ds/union_find.hpp
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
  bundledCode: "#line 1 \"template/template.hpp\"\n#include<bits/stdc++.h>\nusing\
    \ namespace std;\n\n#define ff first\n#define ss second\n#define pb push_back\n\
    typedef long long ll;\ntypedef pair<int,int> pii;\n#define all(v) (v).begin(),(v).end()\n\
    #define db(x) cerr<<__LINE__<<\": \"<<#x<<\" = \"<<(x)<<'\\n'\nconst char en =\
    \ '\\n';\nconst int inf = 1e9+7;\nconst int N = 1e6+9;\n#line 1 \"ds/union_find.hpp\"\
    \nstruct DSU {\n    vector<int> par;\n    int cc; // connected components\n  \
    \  DSU(int n): par(n, -1), cc(n) { }\n\n    // get representive component (uses\
    \ path compression)\n    int get(int x) { return par[x] < 0 ? x : par[x] = get(par[x]);\
    \ }\n\n    bool same_set(int a, int b) { return get(a) == get(b); }\n\n    int\
    \ size(int x) { return -par[get(x)]; }\n\n    int groups() { return cc; } // number\
    \ of groups\n\n    int leader(int v) const {\n        while (par[v] > -1) v =\
    \ par[v];\n        return v;\n    }\n\n    void unite(int x, int y) {  // union\
    \ by size\n        x = get(x), y = get(y);\n        if (x == y) return;\n    \
    \    cc--;\n        if (par[x] > par[y]) swap(x, y);\n        par[x] += par[y];\
    \ par[y] = x;\n    }\n};\n#line 3 \"ds/test/yosupo_unionfind.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/unionfind\"\n\nint main() {\n    ios_base::sync_with_stdio(0);\n\
    \    int n, q, typ, u, v;\n    cin>>n>>q;\n    DSU dsu(n);\n    while(q--) {\n\
    \    \tcin>>typ>>u>>v;\n    \tif(typ==0) {\n    \t\tdsu.unite(u, v);\n    \t}\
    \ else {\n    \t\tcout<<dsu.same_set(u, v)<<'\\n';\n    \t}\n    }\n    return\
    \ 0;\n}\n"
  code: "#include \"../../template/template.hpp\"\n#include \"../union_find.hpp\"\n\
    #define PROBLEM \"https://judge.yosupo.jp/problem/unionfind\"\n\nint main() {\n\
    \    ios_base::sync_with_stdio(0);\n    int n, q, typ, u, v;\n    cin>>n>>q;\n\
    \    DSU dsu(n);\n    while(q--) {\n    \tcin>>typ>>u>>v;\n    \tif(typ==0) {\n\
    \    \t\tdsu.unite(u, v);\n    \t} else {\n    \t\tcout<<dsu.same_set(u, v)<<'\\\
    n';\n    \t}\n    }\n    return 0;\n}"
  dependsOn:
  - template/template.hpp
  - ds/union_find.hpp
  isVerificationFile: true
  path: ds/test/yosupo_unionfind.test.cpp
  requiredBy: []
  timestamp: '2023-02-20 02:34:23+06:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: ds/test/yosupo_unionfind.test.cpp
layout: document
redirect_from:
- /verify/ds/test/yosupo_unionfind.test.cpp
- /verify/ds/test/yosupo_unionfind.test.cpp.html
title: ds/test/yosupo_unionfind.test.cpp
---
