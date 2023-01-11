---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/lca.hpp
    title: graph/lca.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/problems/GRL_5_C
    links:
    - https://onlinejudge.u-aizu.ac.jp/problems/GRL_5_C
  bundledCode: "#line 1 \"test/aoj/GRL_5_C-LCA_Lowest_Common_Ancestor.lca.test.cpp\"\
    \n#include <bits/stdc++.h>\nusing namespace std;\n#line 2 \"graph/lca.hpp\"\n\n\
    struct LCA {\n    vector<vector<int>> parent;\n    vector<int> depth;\n    LCA()\
    \ {}\n    LCA(const vector<vector<int>>& G, int r = 0) { init(G, r); }\n\n   \
    \ void init(const vector<vector<int>>& G, int r = 0) {\n        int V = (int)G.size();\n\
    \        int h = 1;\n        while ((1 << h) < V) ++h;\n        parent.assign(h,\
    \ vector<int>(V, -1));\n        depth.assign(V, -1);\n        dfs(G, r, -1, 0);\n\
    \        for (int i = 0; i + 1 < (int)parent.size(); ++i) {\n            for (int\
    \ v = 0; v < V; ++v) {\n                if (parent[i][v] != -1) {\n          \
    \          parent[i + 1][v] = parent[i][parent[i][v]];\n                }\n  \
    \          }\n        }\n    }\n\n    void dfs(const vector<vector<int>>& G, int\
    \ v, int p, int d) {\n        parent[0][v] = p;\n        depth[v] = d;\n     \
    \   for (auto e : G[v])\n            if (e != p) dfs(G, e, v, d + 1);\n    }\n\
    \n    int query(int u, int v) {\n        if (depth[u] > depth[v]) swap(u, v);\n\
    \        for (int i = 0; i < (int)parent.size(); ++i) {\n            if ((depth[v]\
    \ - depth[u]) & (1 << i)) v = parent[i][v];\n        }\n        if (u == v) return\
    \ u;\n        for (int i = (int)parent.size() - 1; i >= 0; --i) {\n          \
    \  if (parent[i][u] != parent[i][v]) {\n                u = parent[i][u];\n  \
    \              v = parent[i][v];\n            }\n        }\n        return parent[0][u];\n\
    \    }\n\n    int dist(int u, int v) {\n        return depth[u] + depth[v] - 2\
    \ * depth[query(u, v)];\n    }\n\n    bool is_on_path(int u, int v, int x) {\n\
    \        return dist(u, x) + dist(x, v) == dist(u, v);\n    }\n};\n#line 4 \"\
    test/aoj/GRL_5_C-LCA_Lowest_Common_Ancestor.lca.test.cpp\"\n#define PROBLEM \"\
    https://onlinejudge.u-aizu.ac.jp/problems/GRL_5_C\"\n\nint main() {\n    ios_base::sync_with_stdio(0);\n\
    \    int n;\n    cin>>n;\n    vector<vector<int>> G(n);\n    for(int i=0; i<n;\
    \ ++i) {\n        int k;\n        cin>>k;\n        for(int j=0; j<k; ++j) {\n\
    \            int c;\n            cin>>c;\n            G[i].push_back(c);\n   \
    \         G[c].push_back(i);\n        }\n    }\n\n    LCA lca(G, 0);\n\n    int\
    \ q;\n    cin>>q;\n    while(q--) {\n        int a, b;\n        cin>>a>>b;\n \
    \       cout<<lca.query(a, b)<<'\\n';\n    }\n    return 0;\n}\n"
  code: "#include <bits/stdc++.h>\nusing namespace std;\n#include \"../../graph/lca.hpp\"\
    \n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/GRL_5_C\"\n\nint\
    \ main() {\n    ios_base::sync_with_stdio(0);\n    int n;\n    cin>>n;\n    vector<vector<int>>\
    \ G(n);\n    for(int i=0; i<n; ++i) {\n        int k;\n        cin>>k;\n     \
    \   for(int j=0; j<k; ++j) {\n            int c;\n            cin>>c;\n      \
    \      G[i].push_back(c);\n            G[c].push_back(i);\n        }\n    }\n\n\
    \    LCA lca(G, 0);\n\n    int q;\n    cin>>q;\n    while(q--) {\n        int\
    \ a, b;\n        cin>>a>>b;\n        cout<<lca.query(a, b)<<'\\n';\n    }\n  \
    \  return 0;\n}"
  dependsOn:
  - graph/lca.hpp
  isVerificationFile: true
  path: test/aoj/GRL_5_C-LCA_Lowest_Common_Ancestor.lca.test.cpp
  requiredBy: []
  timestamp: '2023-01-12 03:55:17+06:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/GRL_5_C-LCA_Lowest_Common_Ancestor.lca.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/GRL_5_C-LCA_Lowest_Common_Ancestor.lca.test.cpp
- /verify/test/aoj/GRL_5_C-LCA_Lowest_Common_Ancestor.lca.test.cpp.html
title: test/aoj/GRL_5_C-LCA_Lowest_Common_Ancestor.lca.test.cpp
---
