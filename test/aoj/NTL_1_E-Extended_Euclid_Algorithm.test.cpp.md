---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/extgcd.hpp
    title: math/extgcd.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/problems/NTL_1_E
    links:
    - https://onlinejudge.u-aizu.ac.jp/problems/NTL_1_E
  bundledCode: "#line 1 \"test/aoj/NTL_1_E-Extended_Euclid_Algorithm.test.cpp\"\n\
    #include <bits/stdc++.h>\nusing namespace std;\n#line 1 \"math/extgcd.hpp\"\n\
    template<class T> \nT extgcd(T a, T b, T &x, T &y) {\n\tT d = a;\n\tif(b != 0)\
    \ {\n\t\td = extgcd(b, a%b, y, x);\n\t\ty -= (a/b) * x;\n\t} else {\n\t\tx = 1;\n\
    \t\ty = 0;\n\t}\n\treturn d;\n}\n#line 4 \"test/aoj/NTL_1_E-Extended_Euclid_Algorithm.test.cpp\"\
    \n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/NTL_1_E\"\n\nint\
    \ main() {\n    ios_base::sync_with_stdio(0);\n    int a, b, x, y;\n    cin>>a>>b;\n\
    \    extgcd(a, b, x, y);\n    cout<<x<<\" \"<<y<<'\\n';\n    return 0;\n}\n"
  code: "#include <bits/stdc++.h>\nusing namespace std;\n#include \"../../math/extgcd.hpp\"\
    \n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/NTL_1_E\"\n\nint\
    \ main() {\n    ios_base::sync_with_stdio(0);\n    int a, b, x, y;\n    cin>>a>>b;\n\
    \    extgcd(a, b, x, y);\n    cout<<x<<\" \"<<y<<'\\n';\n    return 0;\n}"
  dependsOn:
  - math/extgcd.hpp
  isVerificationFile: true
  path: test/aoj/NTL_1_E-Extended_Euclid_Algorithm.test.cpp
  requiredBy: []
  timestamp: '2023-01-07 03:52:29+06:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/NTL_1_E-Extended_Euclid_Algorithm.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/NTL_1_E-Extended_Euclid_Algorithm.test.cpp
- /verify/test/aoj/NTL_1_E-Extended_Euclid_Algorithm.test.cpp.html
title: test/aoj/NTL_1_E-Extended_Euclid_Algorithm.test.cpp
---
