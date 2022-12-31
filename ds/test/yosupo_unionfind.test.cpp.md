---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes: {}
  bundledCode: "Traceback (most recent call last):\n  File \"/home/runner/.local/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/home/runner/.local/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/home/runner/.local/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/home/runner/.local/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ../union-find.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/unionfind\"\n\n#include\
    \ \"../../template/template.hpp\"\n#include \"../union-find.hpp\"\n\nint main()\
    \ {\n    ios_base::sync_with_stdio(0);\n    int n, q, typ, u, v;\n    cin>>n>>q;\n\
    \    DSU dsu(n);\n    while(q--) {\n    \tcin>>typ>>u>>v;\n    \tif(typ==0) {\n\
    \    \t\tdsu.unite(u, v);\n    \t} else {\n    \t\tcout<<dsu.same_set(u, v)<<'\\\
    n';\n    \t}\n    }\n    return 0;\n}"
  dependsOn: []
  isVerificationFile: true
  path: ds/test/yosupo_unionfind.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: ds/test/yosupo_unionfind.test.cpp
layout: document
redirect_from:
- /verify/ds/test/yosupo_unionfind.test.cpp
- /verify/ds/test/yosupo_unionfind.test.cpp.html
title: ds/test/yosupo_unionfind.test.cpp
---
