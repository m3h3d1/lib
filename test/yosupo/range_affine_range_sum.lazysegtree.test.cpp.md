---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: mint.hpp
    title: mint.hpp
  - icon: ':question:'
    path: segtree/lazysegtree.hpp
    title: segtree/lazysegtree.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/range_affine_range_sum
    links:
    - https://judge.yosupo.jp/problem/range_affine_range_sum
  bundledCode: "#line 1 \"test/yosupo/range_affine_range_sum.lazysegtree.test.cpp\"\
    \n#include <bits/stdc++.h>\nusing namespace std;\n#line 1 \"mint.hpp\"\npragma\
    \ once\n\ntemplate <class T, class Op = multiplies<T>>\nT power(T a, long long\
    \ n, Op op = Op(), T e = {1}) { // argument a in mint\n  assert(n >= 0);\n  while\
    \ (n) {\n    if (n & 1) e = op(e, a);\n    if (n >>= 1) a = op(a, a);\n  }\n \
    \ return e;\n}\ntemplate <unsigned M> struct modular {\n#pragma GCC diagnostic\
    \ push\n#pragma GCC diagnostic ignored \"-Wconversion\"\n  static constexpr unsigned\
    \ mod = M;\n  using m = modular;\n  unsigned v;\n  modular(long long x = 0) :\
    \ v((x %= mod) < 0 ? x + mod : x) {}\n  m operator-() const { return m() -= *this;\
    \ }\n  m& operator+=(m b) { if ((int)(v += b.v - mod) < 0) v += mod; return *this;\
    \ }\n  m& operator-=(m b) { if ((int)(v -= b.v) < 0) v += mod; return *this; }\n\
    \  m& operator*=(m b) { v = (uint64_t)v * b.v % mod; return *this; }\n  m& operator/=(m\
    \ b) { return *this *= power(b, mod - 2); }\n  friend m operator+(m a, m b) {\
    \ return a += b; }\n  friend m operator-(m a, m b) { return a -= b; }\n  friend\
    \ m operator*(m a, m b) { return a *= b; }\n  friend m operator/(m a, m b) { return\
    \ a /= b; }\n  friend bool operator==(m a, m b) { return a.v == b.v; }\n  friend\
    \ bool operator!=(m a, m b) { return a.v != b.v; }\n  bool operator<(const modular\
    \ &x) const {\n    return v < x.v;\n  } // To use std::map<modular, T>\n  friend\
    \ std::istream &operator>>(std::istream &is, modular &x) {\n    long long t;\n\
    \    return is >> t, x = modular(t), is;\n  }\n  friend std::ostream &operator<<(std::ostream\
    \ &os, const modular &x) {\n    return os << x.v;\n  }\n#pragma GCC diagnostic\
    \ pop\n};\n// using mint = modular<998244353>;\n// using mint = modular<1000000007>;\n\
    #line 2 \"segtree/lazysegtree.hpp\"\n\ntemplate <class S,\n          S (*op)(S,\
    \ S),\n          S (*e)(),\n          class F,\n          S (*mapping)(F, S),\n\
    \          F (*composition)(F, F),\n          F (*id)()>\nstruct LazySegmentTree\
    \ {\n  private:\n    int _n, size, log;\n    vector<S> dat;\n    vector<F> lz;\n\
    \    void update(int k) { dat[k] = op(dat[2 * k], dat[2 * k + 1]); }\n    void\
    \ all_apply(int k, F f) {\n        dat[k] = mapping(f, dat[k]);\n        if (k\
    \ < size) lz[k] = composition(f, lz[k]);\n    }\n    void push(int k) {\n    \
    \    all_apply(2 * k, lz[k]);\n        all_apply(2 * k + 1, lz[k]);\n        lz[k]\
    \ = id();\n    }\n    int lower_bits(int x, int k) { return x & ((1 << k) - 1);\
    \ }\n\n  public:\n    LazySegmentTree() : LazySegmentTree(0) {}\n    LazySegmentTree(int\
    \ n) : LazySegmentTree(vector<S>(n, e())) {}\n    LazySegmentTree(const vector<S>&\
    \ v) : _n(int(v.size())) {\n        log = 0;\n        while ((1 << log) < _n)\
    \ log++;\n        size = 1 << log;\n        dat = vector<S>(2 * size, e());\n\
    \        lz = vector<F>(size, id());\n        for (int i = 0; i < _n; i++) dat[size\
    \ + i] = v[i];\n        for (int i = size - 1; i >= 1; i--) update(i);\n    }\n\
    \    // a[p] = x\n    void set(int p, S x) {\n        p += size;\n        for\
    \ (int i = log; i >= 1; i--) push(p >> i);\n        dat[p] = x;\n        for (int\
    \ i = 1; i <= log; i++) update(p >> i);\n    }\n    // return a[p]\n    S get(int\
    \ p) {\n        p += size;\n        for (int i = log; i >= 1; i--) push(p >> i);\n\
    \        return dat[p];\n    }\n    // return op(a[l], ..., a[r-1])\n    S prod(int\
    \ l, int r) {\n        if (l == r) return e();\n        l += size;\n        r\
    \ += size;\n        for (int i = log; i >= 1; i--) {\n            if (lower_bits(l,\
    \ i) > 0) push(l >> i);\n            if (lower_bits(r, i) > 0) push((r - 1) >>\
    \ i);\n        }\n        S sml = e(), smr = e();\n        while (l < r) {\n \
    \           if (l & 1) sml = op(sml, dat[l++]);\n            if (r & 1) smr =\
    \ op(dat[--r], smr);\n            l >>= 1;\n            r >>= 1;\n        }\n\
    \        return op(sml, smr);\n    }\n    S all_prod() { return dat[1]; }\n  \
    \  // a[p] = f(a[p])\n    void apply(int p, F f) {\n        p += size;\n     \
    \   for (int i = log; i >= 1; i--) push(p >> i);\n        dat[p] = mapping(f,\
    \ dat[p]);\n        for (int i = 1; i <= log; i++) update(p >> i);\n    }\n  \
    \  // a[i] = f(a[i]) for i = l...r-1\n    void apply(int l, int r, F f) {\n  \
    \      if (l == r) return;\n        l += size;\n        r += size;\n        for\
    \ (int i = log; i >= 1; i--) {\n            if (lower_bits(l, i) > 0) push(l >>\
    \ i);\n            if (lower_bits(r, i) > 0) push((r - 1) >> i);\n        }\n\
    \        int l2 = l, r2 = r;\n        while (l < r) {\n            if (l & 1)\
    \ all_apply(l++, f);\n            if (r & 1) all_apply(--r, f);\n            l\
    \ >>= 1;\n            r >>= 1;\n        }\n        l = l2;\n        r = r2;\n\
    \        for (int i = 1; i <= log; i++) {\n            if (lower_bits(l, i) >\
    \ 0) update(l >> i);\n            if (lower_bits(r, i) > 0) update((r - 1) >>\
    \ i);\n        }\n    }\n\n    // Binary search on SegmentTree (if needed)\n \
    \   // return r, f(op(a[l], ..., a[r-1])) == true\n    template <bool (*g)(S)>\n\
    \    int max_right(int l) {\n        return max_right(l, [](S x) { return g(x);\
    \ });\n    }\n    template <class G>\n    int max_right(int l, G g) {\n      \
    \  assert(g(e()));\n        if (l == _n) return _n;\n        l += size;\n    \
    \    for (int i = log; i >= 1; i--) push(l >> i);\n        S sm = e();\n     \
    \   do {\n            while (l % 2 == 0) l >>= 1;\n            if (!g(op(sm, dat[l])))\
    \ {\n                while (l < size) {\n                    push(l);\n      \
    \              l = (2 * l);\n                    if (g(op(sm, dat[l]))) {\n  \
    \                      sm = op(sm, dat[l]);\n                        l++;\n  \
    \                  }\n                }\n                return l - size;\n  \
    \          }\n            sm = op(sm, dat[l]);\n            l++;\n        } while\
    \ ((l & -l) != l);\n        return _n;\n    }\n    // return l, f(op(a[l], ...,\
    \ a[r-1])) == true\n    template <bool (*g)(S)>\n    int min_left(int r) {\n \
    \       return min_left(r, [](S x) { return g(x); });\n    }\n    template <class\
    \ G>\n    int min_left(int r, G g) {\n        assert(g(e()));\n        if (r ==\
    \ 0) return 0;\n        r += size;\n        for (int i = log; i >= 1; i--) push((r\
    \ - 1) >> i);\n        S sm = e();\n        do {\n            r--;\n         \
    \   while (r > 1 && (r % 2)) r >>= 1;\n            if (!g(op(dat[r], sm))) {\n\
    \                while (r < size) {\n                    push(r);\n          \
    \          r = (2 * r + 1);\n                    if (g(op(dat[r], sm))) {\n  \
    \                      sm = op(dat[r], sm);\n                        r--;\n  \
    \                  }\n                }\n                return r + 1 - size;\n\
    \            }\n            sm = op(dat[r], sm);\n        } while ((r & -r) !=\
    \ r);\n        return 0;\n    }\n};\n// @docs segtree/lazysegtree.md\n#line 5\
    \ \"test/yosupo/range_affine_range_sum.lazysegtree.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/range_affine_range_sum\"\n\nusing T = modular<998244353>;\n\
    using S = pair<T, int>;\nusing F = pair<T, T>;\nS op(S a,S b) { return make_pair(a.first\
    \ + b.first, a.second + b.second); }\nS e() { return make_pair(0, 0); }\nS mapping(F\
    \ f,S x) { \n    return make_pair(f.first * x.first + f.second * x.second, x.second);\
    \ \n}\nF composition(F f,F g) { \n    return make_pair(g.first * f.first, f.second\
    \ + f.first * g.second); \n}\nF id() { return make_pair(1, 0); }\n\nint main()\
    \ {\n    ios_base::sync_with_stdio(0);\n    int n, q;\n    cin>>n>>q;\n    vector<S>\
    \ v(n);\n    for(auto &a: v) {\n        cin>>a.first;\n        a.second = 1;\n\
    \    }\n    LazySegmentTree<S, op, e, F, mapping, composition, id> seg(v);\n \
    \   while(q--) {\n        int typ, l, r;\n        cin>>typ>>l>>r;\n        if(typ==0)\
    \ {\n            F x;\n            cin>>x.first>>x.second;\n            seg.apply(l,\
    \ r, x);\n        } else {\n            cout<<seg.prod(l, r).first<<'\\n';\n \
    \       }\n    }\n    return 0;\n}\n"
  code: "#include <bits/stdc++.h>\nusing namespace std;\n#include \"../../mint.hpp\"\
    \n#include \"../../segtree/lazysegtree.hpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/range_affine_range_sum\"\
    \n\nusing T = modular<998244353>;\nusing S = pair<T, int>;\nusing F = pair<T,\
    \ T>;\nS op(S a,S b) { return make_pair(a.first + b.first, a.second + b.second);\
    \ }\nS e() { return make_pair(0, 0); }\nS mapping(F f,S x) { \n    return make_pair(f.first\
    \ * x.first + f.second * x.second, x.second); \n}\nF composition(F f,F g) { \n\
    \    return make_pair(g.first * f.first, f.second + f.first * g.second); \n}\n\
    F id() { return make_pair(1, 0); }\n\nint main() {\n    ios_base::sync_with_stdio(0);\n\
    \    int n, q;\n    cin>>n>>q;\n    vector<S> v(n);\n    for(auto &a: v) {\n \
    \       cin>>a.first;\n        a.second = 1;\n    }\n    LazySegmentTree<S, op,\
    \ e, F, mapping, composition, id> seg(v);\n    while(q--) {\n        int typ,\
    \ l, r;\n        cin>>typ>>l>>r;\n        if(typ==0) {\n            F x;\n   \
    \         cin>>x.first>>x.second;\n            seg.apply(l, r, x);\n        }\
    \ else {\n            cout<<seg.prod(l, r).first<<'\\n';\n        }\n    }\n \
    \   return 0;\n}"
  dependsOn:
  - mint.hpp
  - segtree/lazysegtree.hpp
  isVerificationFile: true
  path: test/yosupo/range_affine_range_sum.lazysegtree.test.cpp
  requiredBy: []
  timestamp: '2022-12-31 09:46:33+06:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yosupo/range_affine_range_sum.lazysegtree.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/range_affine_range_sum.lazysegtree.test.cpp
- /verify/test/yosupo/range_affine_range_sum.lazysegtree.test.cpp.html
title: test/yosupo/range_affine_range_sum.lazysegtree.test.cpp
---
