---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/NTL_1_E-Extended_Euclid_Algorithm.test.cpp
    title: test/aoj/NTL_1_E-Extended_Euclid_Algorithm.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"math/extgcd.hpp\"\ntemplate<class T> \nT extgcd(T a, T b,\
    \ T &x, T &y) {\n\tT d = a;\n\tif(b != 0) {\n\t\td = extgcd(b, a%b, y, x);\n\t\
    \ty -= (a/b) * x;\n\t} else {\n\t\tx = 1;\n\t\ty = 0;\n\t}\n\treturn d;\n}\n"
  code: "template<class T> \nT extgcd(T a, T b, T &x, T &y) {\n\tT d = a;\n\tif(b\
    \ != 0) {\n\t\td = extgcd(b, a%b, y, x);\n\t\ty -= (a/b) * x;\n\t} else {\n\t\t\
    x = 1;\n\t\ty = 0;\n\t}\n\treturn d;\n}"
  dependsOn: []
  isVerificationFile: false
  path: math/extgcd.hpp
  requiredBy: []
  timestamp: '2023-01-07 03:52:29+06:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/NTL_1_E-Extended_Euclid_Algorithm.test.cpp
documentation_of: math/extgcd.hpp
layout: document
title: Extgcd (extended Euclidean algorithm)
---

# extgcd

```
T extgcd(T a, T b, T &x, T &y)
```

for $\gcd(a, b)$ returns $(x, y)$. Contains integer solutions that satisfy $ax + by = \gcd(a, b)$. If multiple integer solutions are possible, the one with the smallest $\|x\| + \|y\|$ is stored.


## Constraint

- $1 \leq a, b$

## Complexity

- $O(\log {\min(a, b)})$