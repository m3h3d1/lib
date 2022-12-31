---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/yosupo/range_affine_range_sum.lazysegtree.test.cpp
    title: test/yosupo/range_affine_range_sum.lazysegtree.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"mint.hpp\"\npragma once\n\ntemplate <class T, class Op =\
    \ multiplies<T>>\nT power(T a, long long n, Op op = Op(), T e = {1}) { // argument\
    \ a in mint\n  assert(n >= 0);\n  while (n) {\n    if (n & 1) e = op(e, a);\n\
    \    if (n >>= 1) a = op(a, a);\n  }\n  return e;\n}\ntemplate <unsigned M> struct\
    \ modular {\n#pragma GCC diagnostic push\n#pragma GCC diagnostic ignored \"-Wconversion\"\
    \n  static constexpr unsigned mod = M;\n  using m = modular;\n  unsigned v;\n\
    \  modular(long long x = 0) : v((x %= mod) < 0 ? x + mod : x) {}\n  m operator-()\
    \ const { return m() -= *this; }\n  m& operator+=(m b) { if ((int)(v += b.v -\
    \ mod) < 0) v += mod; return *this; }\n  m& operator-=(m b) { if ((int)(v -= b.v)\
    \ < 0) v += mod; return *this; }\n  m& operator*=(m b) { v = (uint64_t)v * b.v\
    \ % mod; return *this; }\n  m& operator/=(m b) { return *this *= power(b, mod\
    \ - 2); }\n  friend m operator+(m a, m b) { return a += b; }\n  friend m operator-(m\
    \ a, m b) { return a -= b; }\n  friend m operator*(m a, m b) { return a *= b;\
    \ }\n  friend m operator/(m a, m b) { return a /= b; }\n  friend bool operator==(m\
    \ a, m b) { return a.v == b.v; }\n  friend bool operator!=(m a, m b) { return\
    \ a.v != b.v; }\n  bool operator<(const modular &x) const {\n    return v < x.v;\n\
    \  } // To use std::map<modular, T>\n  friend std::istream &operator>>(std::istream\
    \ &is, modular &x) {\n    long long t;\n    return is >> t, x = modular(t), is;\n\
    \  }\n  friend std::ostream &operator<<(std::ostream &os, const modular &x) {\n\
    \    return os << x.v;\n  }\n#pragma GCC diagnostic pop\n};\n// using mint = modular<998244353>;\n\
    // using mint = modular<1000000007>;\n"
  code: "pragma once\n\ntemplate <class T, class Op = multiplies<T>>\nT power(T a,\
    \ long long n, Op op = Op(), T e = {1}) { // argument a in mint\n  assert(n >=\
    \ 0);\n  while (n) {\n    if (n & 1) e = op(e, a);\n    if (n >>= 1) a = op(a,\
    \ a);\n  }\n  return e;\n}\ntemplate <unsigned M> struct modular {\n#pragma GCC\
    \ diagnostic push\n#pragma GCC diagnostic ignored \"-Wconversion\"\n  static constexpr\
    \ unsigned mod = M;\n  using m = modular;\n  unsigned v;\n  modular(long long\
    \ x = 0) : v((x %= mod) < 0 ? x + mod : x) {}\n  m operator-() const { return\
    \ m() -= *this; }\n  m& operator+=(m b) { if ((int)(v += b.v - mod) < 0) v +=\
    \ mod; return *this; }\n  m& operator-=(m b) { if ((int)(v -= b.v) < 0) v += mod;\
    \ return *this; }\n  m& operator*=(m b) { v = (uint64_t)v * b.v % mod; return\
    \ *this; }\n  m& operator/=(m b) { return *this *= power(b, mod - 2); }\n  friend\
    \ m operator+(m a, m b) { return a += b; }\n  friend m operator-(m a, m b) { return\
    \ a -= b; }\n  friend m operator*(m a, m b) { return a *= b; }\n  friend m operator/(m\
    \ a, m b) { return a /= b; }\n  friend bool operator==(m a, m b) { return a.v\
    \ == b.v; }\n  friend bool operator!=(m a, m b) { return a.v != b.v; }\n  bool\
    \ operator<(const modular &x) const {\n    return v < x.v;\n  } // To use std::map<modular,\
    \ T>\n  friend std::istream &operator>>(std::istream &is, modular &x) {\n    long\
    \ long t;\n    return is >> t, x = modular(t), is;\n  }\n  friend std::ostream\
    \ &operator<<(std::ostream &os, const modular &x) {\n    return os << x.v;\n \
    \ }\n#pragma GCC diagnostic pop\n};\n// using mint = modular<998244353>;\n// using\
    \ mint = modular<1000000007>;"
  dependsOn: []
  isVerificationFile: false
  path: mint.hpp
  requiredBy: []
  timestamp: '2022-12-31 09:46:33+06:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yosupo/range_affine_range_sum.lazysegtree.test.cpp
documentation_of: mint.hpp
layout: document
redirect_from:
- /library/mint.hpp
- /library/mint.hpp.html
title: mint.hpp
---
