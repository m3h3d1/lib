---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/fastFactorize.hpp
    title: math/fastFactorize.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/factorize
    links:
    - https://judge.yosupo.jp/problem/factorize
  bundledCode: "#line 1 \"test/yosupo/factorize.test.cpp\"\n#include <bits/stdc++.h>\n\
    using namespace std;\n#define PROBLEM \"https://judge.yosupo.jp/problem/factorize\"\
    \n#line 1 \"math/fastFactorize.hpp\"\ntypedef int64_t ll;\ntypedef uint64_t ull;\n\
    \null mul(ull a, ull b, ull M) {\n    ll r = a * b - M * ull(1.L / M * a * b);\n\
    \    return r + M * ((r < 0) - (r >= (ll) M));\n}\null mow(ull x, ull e, ull M)\
    \ {\n    ull r = 1;\n    for (; e; x = mul(x, x, M), e >>= 1)\n        if (e &\
    \ 1) r = mul(r, x, M);\n    return r;\n}\n\nbool isPrime(ull n) {\n    if (n <\
    \ 2 or n % 6 % 4 != 1) return (n | 1) == 3;\n    static const ull A[] = {2, 3,\
    \ 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41};\n    ull s = __builtin_ctzll(n -\
    \ 1), d = n >> s;\n    for (const ull& a: A) {\n        ull p = mow(a % n, d,\
    \ n), i = s;\n        while (p != 1 and p != n - 1 and a % n != 0 and i--)\n \
    \           p = mul(p, p, n);\n        if (p != n - 1 and i != s) return false;\n\
    \    }\n    return true;\n}\n\null pollard(ull n) {\n    static mt19937_64 mt((unsigned)chrono::system_clock::now().time_since_epoch().count());\n\
    \    static ull c = 1;\n    auto f = [&](ull x) { return mul(x, x, n) + c; };\n\
    \    ull x = 0, y = 0, t = 40, p = 2, q, i = 2;\n    while (t++ % 30 or gcd(p,\
    \ n) == 1) {\n        if (x == y) c = mt() % (n - 1) + 1, y = f(x = ++i);\n  \
    \      if (q = mul(p, (x > y ? x - y : y - x), n)) p = q;\n        x = f(x); y\
    \ = f(f(y));\n    }\n    return gcd(p, n);\n}\n\nvoid factor(ull n, vector<ull>&\
    \ f) {\n    if (n == 1) return;\n    if (isPrime(n)) {\n        f.push_back(n);\n\
    \        return;\n    }\n    ull x = pollard(n);\n    factor(x, f);\n    factor(n\
    \ / x, f);\n    return;\n}\n#line 5 \"test/yosupo/factorize.test.cpp\"\n\nint\
    \ main() {\n    ios::sync_with_stdio(0);\n    int q; cin>>q;\n    while(q--) {\n\
    \        ull a; cin>>a;\n        vector<ull> f;\n        factor(a, f);\n     \
    \   sort(f.begin(), f.end());\n        cout<<f.size()<<' ';\n        for(auto\
    \ x: f) \n            cout<<x<<' ';\n        cout<<'\\n';\n    }\n    return 0;\n\
    }\n"
  code: "#include <bits/stdc++.h>\nusing namespace std;\n#define PROBLEM \"https://judge.yosupo.jp/problem/factorize\"\
    \n#include \"../../math/fastFactorize.hpp\"\n\nint main() {\n    ios::sync_with_stdio(0);\n\
    \    int q; cin>>q;\n    while(q--) {\n        ull a; cin>>a;\n        vector<ull>\
    \ f;\n        factor(a, f);\n        sort(f.begin(), f.end());\n        cout<<f.size()<<'\
    \ ';\n        for(auto x: f) \n            cout<<x<<' ';\n        cout<<'\\n';\n\
    \    }\n    return 0;\n}"
  dependsOn:
  - math/fastFactorize.hpp
  isVerificationFile: true
  path: test/yosupo/factorize.test.cpp
  requiredBy: []
  timestamp: '2023-01-18 03:58:38+06:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/factorize.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/factorize.test.cpp
- /verify/test/yosupo/factorize.test.cpp.html
title: test/yosupo/factorize.test.cpp
---
