---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: ds/union-find.hpp
    title: ds/union-find.hpp
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
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.11.1/x64/lib/python3.11/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.1/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.11.1/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.1/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.11.1/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: bits/stdc++.h:\
    \ line -1: no such header\n"
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
  timestamp: '2022-12-28 14:32:26+06:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/ds/Unionfind.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/ds/Unionfind.test.cpp
- /verify/test/yosupo/ds/Unionfind.test.cpp.html
title: test/yosupo/ds/Unionfind.test.cpp
---
