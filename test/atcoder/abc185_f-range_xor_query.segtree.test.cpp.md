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
    , line 400, in update\n    raise BundleErrorAt(path, i + 1, \"unable to process\
    \ #include in #if / #ifdef / #ifndef other than include guards\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ test/atcoder/abc185_f-range_xor_query.segtree.test.cpp: line 6: unable to process\
    \ #include in #if / #ifdef / #ifndef other than include guards\n"
  code: "#ifdef __clang__\n#define IGNORE\n#else\n#include <bits/stdc++.h>\nusing\
    \ namespace std;\n#include \"../../segtree/segtree.hpp\"\n#define PROBLEM \"https://atcoder.jp/contests/abc185/tasks/abc185_f\"\
    \n\nint op(int a, int b) { return a ^ b; }\nint e() { return 0; }\n\nint main()\
    \ {\n    ios_base::sync_with_stdio(0);\n    int n, q;\n    cin>>n>>q;\n    vector<int>\
    \ v(n);\n    for(int &x: v) {\n    \tcin>>x;\n    }\n    SegmentTree<int, op,\
    \ e> seg(v);\n    while(q--) {\n    \tint typ, x, y;\n    \tcin>>typ>>x>>y;\n\
    \    \tx--;\n    \tif(typ==1) {\n    \t\tseg.set(x, seg.get(x)^y);\n    \t} else\
    \ {\n    \t\tcout<<seg.prod(x, y)<<'\\n';\n    \t}\n    }\n    return 0;\n}"
  dependsOn: []
  isVerificationFile: true
  path: test/atcoder/abc185_f-range_xor_query.segtree.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/atcoder/abc185_f-range_xor_query.segtree.test.cpp
layout: document
redirect_from:
- /verify/test/atcoder/abc185_f-range_xor_query.segtree.test.cpp
- /verify/test/atcoder/abc185_f-range_xor_query.segtree.test.cpp.html
title: test/atcoder/abc185_f-range_xor_query.segtree.test.cpp
---
