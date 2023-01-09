---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: string/rollingHash2d.hpp
    title: string/rollingHash2d.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/problems/ALDS1_14_C
    links:
    - https://onlinejudge.u-aizu.ac.jp/problems/ALDS1_14_C
  bundledCode: "#line 1 \"test/aoj/ALDS1_14_C-Pattern_Search.hash2d.test.cpp\"\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\n#line 2 \"string/rollingHash2d.hpp\"\n\
    \nstruct RollingHash2D {\n    static constexpr int M = 2;\n    static constexpr\
    \ long long MODS[M] = {999999937, 1000000007};\n    static constexpr long long\
    \ BASE_H = 9973;\n    static constexpr long long BASE_W = 10007;\n    vector<vector<long\
    \ long>> hash[M];\n    vector<long long> powH[M], powW[M];\n    int h,w;\n   \
    \ RollingHash2D() {}\n    RollingHash2D(const vector<string>& str) { init(str);\
    \ }\n    void init(const vector<string>& str) {\n        h = str.size(), w = str[0].size();\n\
    \        for(int k = 0; k < M; k++) {\n            powH[k].resize(h + 1, 1);\n\
    \            powW[k].resize(w + 1, 1);\n            hash[k].resize(h + 1, vector<long\
    \ long>(w + 1, 0));\n            for(int i = 0; i < h; i++) {\n              \
    \  powH[k][i + 1] = powH[k][i] * BASE_H % MODS[k];\n                for(int j\
    \ = 0; j < w; j++) {\n                    hash[k][i + 1][j + 1] = (hash[k][i +\
    \ 1][j] * BASE_W % MODS[k] + str[i][j]) % MODS[k];\n                }\n      \
    \      }\n            for(int j = 0; j < w; j++) {\n                powW[k][j\
    \ + 1] = powW[k][j] * BASE_W % MODS[k];\n                for(int i = 0; i < h;\
    \ i++) {\n                    hash[k][i + 1][j + 1] = (hash[k][i][j + 1] * BASE_H\
    \ % MODS[k] + hash[k][i + 1][j + 1]) % MODS[k];\n                }\n         \
    \   }\n        }\n    }\n\n    // get hash [l1,r1) * [l2,r2)\n    long long get(int\
    \ l1, int r1, int l2, int r2, int k) {\n        long long res = 0;\n        res\
    \ += hash[k][r1][r2];\n        res -= hash[k][l1][r2] * powH[k][r1 - l1] % MODS[k];\n\
    \        if(res < 0) res += MODS[k];\n        res -= hash[k][r1][l2] * powW[k][r2\
    \ - l2] % MODS[k];\n        if(res < 0) res += MODS[k];\n        res += hash[k][l1][l2]\
    \ * powH[k][r1 - l1] % MODS[k] * powW[k][r2 - l2] % MODS[k];\n        if(res >=\
    \ MODS[k]) res -= MODS[k];\n        return res;\n    }\n};\n\nbool match(RollingHash2D&\
    \ RH, int L1, int R1, int L2, int R2, RollingHash2D& rh, int l1, int r1, int l2,\
    \ int r2) {\n    bool res = true;\n    for (int k = 0; k < RollingHash2D::M; k++)\
    \ {\n        res &= RH.get(L1, R1, L2, R2, k) == rh.get(l1, r1, l2, r2, k);\n\
    \    }\n    return res;\n}\n#line 4 \"test/aoj/ALDS1_14_C-Pattern_Search.hash2d.test.cpp\"\
    \n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/ALDS1_14_C\"\n\n\
    int main() {\n    ios_base::sync_with_stdio(0);\n    int h, w;\n    cin>>h>>w;\n\
    \    vector<string> s(h);\n    for(int i=0;i<h;++i) {\n        cin>>s[i];\n  \
    \  }\n    int r, c;\n    cin>>r>>c;\n    vector<string> t(r);\n    for(int i=0;i<r;++i)\
    \ {\n        cin>>t[i];\n    }\n    RollingHash2D rhs(s), rht(t);\n\n    for(int\
    \ i=0;i<h;++i) {\n        for(int j=0;j<w;++j) {\n            if(i+r<=h && j+c<=w)\
    \ {\n                if(match(rhs, i, i+r, j, j+c, rht, 0, r, 0, c)) {\n     \
    \               cout<<i<<\" \"<<j<<'\\n';\n                }\n            }\n\
    \        }\n    }\n    return 0;\n}\n"
  code: "#include <bits/stdc++.h>\nusing namespace std;\n#include \"../../string/rollingHash2d.hpp\"\
    \n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/ALDS1_14_C\"\n\n\
    int main() {\n    ios_base::sync_with_stdio(0);\n    int h, w;\n    cin>>h>>w;\n\
    \    vector<string> s(h);\n    for(int i=0;i<h;++i) {\n        cin>>s[i];\n  \
    \  }\n    int r, c;\n    cin>>r>>c;\n    vector<string> t(r);\n    for(int i=0;i<r;++i)\
    \ {\n        cin>>t[i];\n    }\n    RollingHash2D rhs(s), rht(t);\n\n    for(int\
    \ i=0;i<h;++i) {\n        for(int j=0;j<w;++j) {\n            if(i+r<=h && j+c<=w)\
    \ {\n                if(match(rhs, i, i+r, j, j+c, rht, 0, r, 0, c)) {\n     \
    \               cout<<i<<\" \"<<j<<'\\n';\n                }\n            }\n\
    \        }\n    }\n    return 0;\n}"
  dependsOn:
  - string/rollingHash2d.hpp
  isVerificationFile: true
  path: test/aoj/ALDS1_14_C-Pattern_Search.hash2d.test.cpp
  requiredBy: []
  timestamp: '2023-01-10 05:00:26+06:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/ALDS1_14_C-Pattern_Search.hash2d.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/ALDS1_14_C-Pattern_Search.hash2d.test.cpp
- /verify/test/aoj/ALDS1_14_C-Pattern_Search.hash2d.test.cpp.html
title: test/aoj/ALDS1_14_C-Pattern_Search.hash2d.test.cpp
---
