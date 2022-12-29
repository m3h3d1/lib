---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: segtree/acl_segtree.hpp
    title: segtree/acl_segtree.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://atcoder.jp/contests/practice2/tasks/practice2_j
    links:
    - https://atcoder.jp/contests/practice2/tasks/practice2_j
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.10.9/x64/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.10.9/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.10.9/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.10.9/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 355, in update\n    raise BundleErrorAt(path, i + 1, \"found codes out\
    \ of include guard\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ segtree/acl_segtree.hpp: line 37: found codes out of include guard\n"
  code: "#include <bits/stdc++.h>\nusing namespace std;\n\n#include \"../acl_segtree.hpp\"\
    \n\n#define PROBLEM \"https://atcoder.jp/contests/practice2/tasks/practice2_j\"\
    \n\n#define ff first\n#define ss second\n#define pb push_back\ntypedef long long\
    \ ll;\ntypedef pair<int,int> pii;\n#define all(v) (v).begin(),(v).end()\n#define\
    \ db(x) cerr<<__LINE__<<\": \"<<#x<<\" = \"<<(x)<<'\\n'\nconst char en = '\\n';\n\
    const int inf = 1e9+7;\nconst int N = 1e6+9;\n\nint op(int a, int b) {\n\treturn\
    \ max(a, b);\n}\n\nint e() {\n\treturn -1;\n}\n\nint target;\nint f(int v) {\n\
    \treturn v < target;\n}\n\nint main() {\n    ios_base::sync_with_stdio(0);\n \
    \   int n, q;\n    cin>>n>>q;\n    vector<int> A(n);\n    for(int i=0; i<n; ++i)\
    \ {\n    \tcin>>A[i];\n    }\n    atcoder::segtree<int, op, e> seg(A);\n\n   \
    \ while(q--) {\n    \tint typ;\n    \tcin>>typ;\n    \tif(typ == 1) {\n    \t\t\
    int id, val;\n    \t\tcin>>id>>val;\n    \t\tid--;\n    \t\tseg.set(id, val);\n\
    \    \t} else if(typ == 2) {\n    \t\tint l, r;\n    \t\tcin>>l>>r;\n    \t\t\
    l--;\n    \t\tcout<<seg.prod(l, r)<<en;\n    \t} else if(typ == 3) {\n    \t\t\
    int p;\n    \t\tcin>>p>>target;\n    \t\tp--;\n    \t\tcout<<seg.max_right(p,\
    \ f)+1<<en;\n    \t}\n    }\n    return 0;\n}"
  dependsOn:
  - segtree/acl_segtree.hpp
  isVerificationFile: true
  path: segtree/test/atcoder_Segment-Tree.test.cpp
  requiredBy: []
  timestamp: '2022-12-29 19:00:35+06:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: segtree/test/atcoder_Segment-Tree.test.cpp
layout: document
redirect_from:
- /verify/segtree/test/atcoder_Segment-Tree.test.cpp
- /verify/segtree/test/atcoder_Segment-Tree.test.cpp.html
title: segtree/test/atcoder_Segment-Tree.test.cpp
---
