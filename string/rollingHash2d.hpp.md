---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/aoj/ALDS1_14_C-Pattern_Search.hash2d.test.cpp
    title: test/aoj/ALDS1_14_C-Pattern_Search.hash2d.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"string/rollingHash2d.hpp\"\n\nstruct RollingHash2D {\n \
    \   static constexpr int M = 2;\n    static constexpr long long MODS[M] = {999999937,\
    \ 1000000007};\n    static constexpr long long BASE_H = 9973;\n    static constexpr\
    \ long long BASE_W = 10007;\n    vector<vector<long long>> hash[M];\n    vector<long\
    \ long> powH[M], powW[M];\n    int h,w;\n    RollingHash2D() {}\n    RollingHash2D(const\
    \ vector<string>& str) { init(str); }\n    void init(const vector<string>& str)\
    \ {\n        h = str.size(), w = str[0].size();\n        for(int k = 0; k < M;\
    \ k++) {\n            powH[k].resize(h + 1, 1);\n            powW[k].resize(w\
    \ + 1, 1);\n            hash[k].resize(h + 1, vector<long long>(w + 1, 0));\n\
    \            for(int i = 0; i < h; i++) {\n                powH[k][i + 1] = powH[k][i]\
    \ * BASE_H % MODS[k];\n                for(int j = 0; j < w; j++) {\n        \
    \            hash[k][i + 1][j + 1] = (hash[k][i + 1][j] * BASE_W % MODS[k] + str[i][j])\
    \ % MODS[k];\n                }\n            }\n            for(int j = 0; j <\
    \ w; j++) {\n                powW[k][j + 1] = powW[k][j] * BASE_W % MODS[k];\n\
    \                for(int i = 0; i < h; i++) {\n                    hash[k][i +\
    \ 1][j + 1] = (hash[k][i][j + 1] * BASE_H % MODS[k] + hash[k][i + 1][j + 1]) %\
    \ MODS[k];\n                }\n            }\n        }\n    }\n\n    // get hash\
    \ [l1,r1) * [l2,r2)\n    long long get(int l1, int r1, int l2, int r2, int k)\
    \ {\n        long long res = 0;\n        res += hash[k][r1][r2];\n        res\
    \ -= hash[k][l1][r2] * powH[k][r1 - l1] % MODS[k];\n        if(res < 0) res +=\
    \ MODS[k];\n        res -= hash[k][r1][l2] * powW[k][r2 - l2] % MODS[k];\n   \
    \     if(res < 0) res += MODS[k];\n        res += hash[k][l1][l2] * powH[k][r1\
    \ - l1] % MODS[k] * powW[k][r2 - l2] % MODS[k];\n        if(res >= MODS[k]) res\
    \ -= MODS[k];\n        return res;\n    }\n};\n\nbool match(RollingHash2D& RH,\
    \ int L1, int R1, int L2, int R2, RollingHash2D& rh, int l1, int r1, int l2, int\
    \ r2) {\n    bool res = true;\n    for (int k = 0; k < RollingHash2D::M; k++)\
    \ {\n        res &= RH.get(L1, R1, L2, R2, k) == rh.get(l1, r1, l2, r2, k);\n\
    \    }\n    return res;\n}\n"
  code: "#pragma once\n\nstruct RollingHash2D {\n    static constexpr int M = 2;\n\
    \    static constexpr long long MODS[M] = {999999937, 1000000007};\n    static\
    \ constexpr long long BASE_H = 9973;\n    static constexpr long long BASE_W =\
    \ 10007;\n    vector<vector<long long>> hash[M];\n    vector<long long> powH[M],\
    \ powW[M];\n    int h,w;\n    RollingHash2D() {}\n    RollingHash2D(const vector<string>&\
    \ str) { init(str); }\n    void init(const vector<string>& str) {\n        h =\
    \ str.size(), w = str[0].size();\n        for(int k = 0; k < M; k++) {\n     \
    \       powH[k].resize(h + 1, 1);\n            powW[k].resize(w + 1, 1);\n   \
    \         hash[k].resize(h + 1, vector<long long>(w + 1, 0));\n            for(int\
    \ i = 0; i < h; i++) {\n                powH[k][i + 1] = powH[k][i] * BASE_H %\
    \ MODS[k];\n                for(int j = 0; j < w; j++) {\n                   \
    \ hash[k][i + 1][j + 1] = (hash[k][i + 1][j] * BASE_W % MODS[k] + str[i][j]) %\
    \ MODS[k];\n                }\n            }\n            for(int j = 0; j < w;\
    \ j++) {\n                powW[k][j + 1] = powW[k][j] * BASE_W % MODS[k];\n  \
    \              for(int i = 0; i < h; i++) {\n                    hash[k][i + 1][j\
    \ + 1] = (hash[k][i][j + 1] * BASE_H % MODS[k] + hash[k][i + 1][j + 1]) % MODS[k];\n\
    \                }\n            }\n        }\n    }\n\n    // get hash [l1,r1)\
    \ * [l2,r2)\n    long long get(int l1, int r1, int l2, int r2, int k) {\n    \
    \    long long res = 0;\n        res += hash[k][r1][r2];\n        res -= hash[k][l1][r2]\
    \ * powH[k][r1 - l1] % MODS[k];\n        if(res < 0) res += MODS[k];\n       \
    \ res -= hash[k][r1][l2] * powW[k][r2 - l2] % MODS[k];\n        if(res < 0) res\
    \ += MODS[k];\n        res += hash[k][l1][l2] * powH[k][r1 - l1] % MODS[k] * powW[k][r2\
    \ - l2] % MODS[k];\n        if(res >= MODS[k]) res -= MODS[k];\n        return\
    \ res;\n    }\n};\n\nbool match(RollingHash2D& RH, int L1, int R1, int L2, int\
    \ R2, RollingHash2D& rh, int l1, int r1, int l2, int r2) {\n    bool res = true;\n\
    \    for (int k = 0; k < RollingHash2D::M; k++) {\n        res &= RH.get(L1, R1,\
    \ L2, R2, k) == rh.get(l1, r1, l2, r2, k);\n    }\n    return res;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: string/rollingHash2d.hpp
  requiredBy: []
  timestamp: '2023-01-10 04:57:30+06:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/aoj/ALDS1_14_C-Pattern_Search.hash2d.test.cpp
documentation_of: string/rollingHash2d.hpp
layout: document
redirect_from:
- /library/string/rollingHash2d.hpp
- /library/string/rollingHash2d.hpp.html
title: string/rollingHash2d.hpp
---
