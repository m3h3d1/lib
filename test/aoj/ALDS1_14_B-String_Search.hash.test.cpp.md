---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: string/rollingHash.hpp
    title: string/rollingHash.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/problems/ALDS1_14_B
    links:
    - https://onlinejudge.u-aizu.ac.jp/problems/ALDS1_14_B
  bundledCode: "#line 1 \"test/aoj/ALDS1_14_B-String_Search.hash.test.cpp\"\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\n#line 2 \"string/rollingHash.hpp\"\n\n\
    struct RollingHash {\n    static constexpr int M = 2;\n    static constexpr long\
    \ long MODS[M] = {999999937, 1000000007};\n    static constexpr long long BASE\
    \ = 9973;\n    vector<long long> powb[M], hash[M];\n    int n;\n    RollingHash()\
    \ {}\n    RollingHash(const string& str) { init(str); }\n    void init(const string&\
    \ str) {\n        n = str.size();\n        for (int k = 0; k < M; k++) {\n   \
    \         powb[k].resize(n + 1, 1);\n            hash[k].resize(n + 1, 0);\n \
    \           for (int i = 0; i < n; i++) {\n                hash[k][i + 1] = (hash[k][i]\
    \ * BASE + str[i]) % MODS[k];\n                powb[k][i + 1] = powb[k][i] * BASE\
    \ % MODS[k];\n            }\n        }\n    }\n    // get hash str[l,r)\n    long\
    \ long get(int l, int r, int k) {\n        long long res = hash[k][r] - hash[k][l]\
    \ * powb[k][r - l] % MODS[k];\n        if (res < 0) res += MODS[k];\n        return\
    \ res;\n    }\n};\n\nbool match(RollingHash& rh1, int l1, int r1, RollingHash&\
    \ rh2, int l2, int r2) {\n    bool res = true;\n    for (int k = 0; k < RollingHash::M;\
    \ k++) {\n        res &= rh1.get(l1, r1, k) == rh2.get(l2, r2, k);\n    }\n  \
    \  return res;\n}\n#line 4 \"test/aoj/ALDS1_14_B-String_Search.hash.test.cpp\"\
    \n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/ALDS1_14_B\"\n\n\
    int main() {\n    ios_base::sync_with_stdio(0);\n    string s, t;\n    cin>>s>>t;\
    \  \n    int n = s.size(), m = t.size();\n    RollingHash hs(s), ht(t);\n    for(int\
    \ i=0;i<n-m+1;++i) {\n        if(match(hs, i, i+m, ht, 0, m)) {\n            cout<<i<<'\\\
    n';\n        }\n    }\n    return 0;\n}\n"
  code: "#include <bits/stdc++.h>\nusing namespace std;\n#include \"../../string/rollingHash.hpp\"\
    \n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/ALDS1_14_B\"\n\n\
    int main() {\n    ios_base::sync_with_stdio(0);\n    string s, t;\n    cin>>s>>t;\
    \  \n    int n = s.size(), m = t.size();\n    RollingHash hs(s), ht(t);\n    for(int\
    \ i=0;i<n-m+1;++i) {\n        if(match(hs, i, i+m, ht, 0, m)) {\n            cout<<i<<'\\\
    n';\n        }\n    }\n    return 0;\n}"
  dependsOn:
  - string/rollingHash.hpp
  isVerificationFile: true
  path: test/aoj/ALDS1_14_B-String_Search.hash.test.cpp
  requiredBy: []
  timestamp: '2023-01-10 04:57:30+06:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/ALDS1_14_B-String_Search.hash.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/ALDS1_14_B-String_Search.hash.test.cpp
- /verify/test/aoj/ALDS1_14_B-String_Search.hash.test.cpp.html
title: test/aoj/ALDS1_14_B-String_Search.hash.test.cpp
---
