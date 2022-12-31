---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: segtree/lazysegtree.hpp
    title: Lazy Segtree
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/problems/DSL_2_I
    links:
    - https://onlinejudge.u-aizu.ac.jp/problems/DSL_2_I
  bundledCode: "#line 1 \"test/aoj/DSL_2_I-RSQ and RUQ.lazysegtree.test.cpp\"\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\n#line 2 \"segtree/lazysegtree.hpp\"\n\
    \ntemplate <class S,\n          S (*op)(S, S),\n          S (*e)(),\n        \
    \  class F,\n          S (*mapping)(F, S),\n          F (*composition)(F, F),\n\
    \          F (*id)()>\nstruct LazySegmentTree {\n  private:\n    int _n, size,\
    \ log;\n    vector<S> dat;\n    vector<F> lz;\n    void update(int k) { dat[k]\
    \ = op(dat[2 * k], dat[2 * k + 1]); }\n    void all_apply(int k, F f) {\n    \
    \    dat[k] = mapping(f, dat[k]);\n        if (k < size) lz[k] = composition(f,\
    \ lz[k]);\n    }\n    void push(int k) {\n        all_apply(2 * k, lz[k]);\n \
    \       all_apply(2 * k + 1, lz[k]);\n        lz[k] = id();\n    }\n    int lower_bits(int\
    \ x, int k) { return x & ((1 << k) - 1); }\n\n  public:\n    LazySegmentTree()\
    \ : LazySegmentTree(0) {}\n    LazySegmentTree(int n) : LazySegmentTree(vector<S>(n,\
    \ e())) {}\n    LazySegmentTree(const vector<S>& v) : _n(int(v.size())) {\n  \
    \      log = 0;\n        while ((1 << log) < _n) log++;\n        size = 1 << log;\n\
    \        dat = vector<S>(2 * size, e());\n        lz = vector<F>(size, id());\n\
    \        for (int i = 0; i < _n; i++) dat[size + i] = v[i];\n        for (int\
    \ i = size - 1; i >= 1; i--) update(i);\n    }\n    // a[p] = x\n    void set(int\
    \ p, S x) {\n        p += size;\n        for (int i = log; i >= 1; i--) push(p\
    \ >> i);\n        dat[p] = x;\n        for (int i = 1; i <= log; i++) update(p\
    \ >> i);\n    }\n    // return a[p]\n    S get(int p) {\n        p += size;\n\
    \        for (int i = log; i >= 1; i--) push(p >> i);\n        return dat[p];\n\
    \    }\n    // return op(a[l], ..., a[r-1])\n    S prod(int l, int r) {\n    \
    \    if (l == r) return e();\n        l += size;\n        r += size;\n       \
    \ for (int i = log; i >= 1; i--) {\n            if (lower_bits(l, i) > 0) push(l\
    \ >> i);\n            if (lower_bits(r, i) > 0) push((r - 1) >> i);\n        }\n\
    \        S sml = e(), smr = e();\n        while (l < r) {\n            if (l &\
    \ 1) sml = op(sml, dat[l++]);\n            if (r & 1) smr = op(dat[--r], smr);\n\
    \            l >>= 1;\n            r >>= 1;\n        }\n        return op(sml,\
    \ smr);\n    }\n    S all_prod() { return dat[1]; }\n    // a[p] = f(a[p])\n \
    \   void apply(int p, F f) {\n        p += size;\n        for (int i = log; i\
    \ >= 1; i--) push(p >> i);\n        dat[p] = mapping(f, dat[p]);\n        for\
    \ (int i = 1; i <= log; i++) update(p >> i);\n    }\n    // a[i] = f(a[i]) for\
    \ i = l...r-1\n    void apply(int l, int r, F f) {\n        if (l == r) return;\n\
    \        l += size;\n        r += size;\n        for (int i = log; i >= 1; i--)\
    \ {\n            if (lower_bits(l, i) > 0) push(l >> i);\n            if (lower_bits(r,\
    \ i) > 0) push((r - 1) >> i);\n        }\n        int l2 = l, r2 = r;\n      \
    \  while (l < r) {\n            if (l & 1) all_apply(l++, f);\n            if\
    \ (r & 1) all_apply(--r, f);\n            l >>= 1;\n            r >>= 1;\n   \
    \     }\n        l = l2;\n        r = r2;\n        for (int i = 1; i <= log; i++)\
    \ {\n            if (lower_bits(l, i) > 0) update(l >> i);\n            if (lower_bits(r,\
    \ i) > 0) update((r - 1) >> i);\n        }\n    }\n\n    // Binary search on SegmentTree\
    \ (if needed)\n    // return r, f(op(a[l], ..., a[r-1])) == true\n    template\
    \ <bool (*g)(S)>\n    int max_right(int l) {\n        return max_right(l, [](S\
    \ x) { return g(x); });\n    }\n    template <class G>\n    int max_right(int\
    \ l, G g) {\n        assert(g(e()));\n        if (l == _n) return _n;\n      \
    \  l += size;\n        for (int i = log; i >= 1; i--) push(l >> i);\n        S\
    \ sm = e();\n        do {\n            while (l % 2 == 0) l >>= 1;\n         \
    \   if (!g(op(sm, dat[l]))) {\n                while (l < size) {\n          \
    \          push(l);\n                    l = (2 * l);\n                    if\
    \ (g(op(sm, dat[l]))) {\n                        sm = op(sm, dat[l]);\n      \
    \                  l++;\n                    }\n                }\n          \
    \      return l - size;\n            }\n            sm = op(sm, dat[l]);\n   \
    \         l++;\n        } while ((l & -l) != l);\n        return _n;\n    }\n\
    \    // return l, f(op(a[l], ..., a[r-1])) == true\n    template <bool (*g)(S)>\n\
    \    int min_left(int r) {\n        return min_left(r, [](S x) { return g(x);\
    \ });\n    }\n    template <class G>\n    int min_left(int r, G g) {\n       \
    \ assert(g(e()));\n        if (r == 0) return 0;\n        r += size;\n       \
    \ for (int i = log; i >= 1; i--) push((r - 1) >> i);\n        S sm = e();\n  \
    \      do {\n            r--;\n            while (r > 1 && (r % 2)) r >>= 1;\n\
    \            if (!g(op(dat[r], sm))) {\n                while (r < size) {\n \
    \                   push(r);\n                    r = (2 * r + 1);\n         \
    \           if (g(op(dat[r], sm))) {\n                        sm = op(dat[r],\
    \ sm);\n                        r--;\n                    }\n                }\n\
    \                return r + 1 - size;\n            }\n            sm = op(dat[r],\
    \ sm);\n        } while ((r & -r) != r);\n        return 0;\n    }\n}; // LazySegmentTree\n\
    #line 4 \"test/aoj/DSL_2_I-RSQ and RUQ.lazysegtree.test.cpp\"\n#define PROBLEM\
    \ \"https://onlinejudge.u-aizu.ac.jp/problems/DSL_2_I\"\n\nstruct S {\n    long\
    \ long val;\n    int size;\n};\nusing F = long long;\nconst F ID = 1e9+7;\n\n\
    S op(S a, S b) {\n    return {a.val + b.val, a.size + b.size};\n}\nS e() { return\
    \ {0, 0}; }\nS mapping(F f, S x) {\n    if(f != ID) x.val = f*x.size;\n    return\
    \ x;\n}\nF composition(F f, F g) {\n    return (f == ID ? g : f);\n}\nF id() {\
    \ return ID; }\n\nint main() {\n    ios_base::sync_with_stdio(0);\n    int n,\
    \ q;\n    cin>>n>>q;\n    vector<S> v(n, {0, 1});\n    LazySegmentTree<S, op,\
    \ e, F, mapping, composition, id> seg(v);\n    while(q--) {\n        int typ,\
    \ a, b;\n        cin>>typ>>a>>b;\n        if(typ==0) {\n            int x;\n \
    \           cin>>x;\n            seg.apply(a, b+1, x);\n        } else {\n   \
    \         cout<<seg.prod(a, b+1).val<<'\\n';\n        }\n    }\n    return 0;\n\
    }\n"
  code: "#include <bits/stdc++.h>\nusing namespace std;\n#include \"../../segtree/lazysegtree.hpp\"\
    \n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/DSL_2_I\"\n\nstruct\
    \ S {\n    long long val;\n    int size;\n};\nusing F = long long;\nconst F ID\
    \ = 1e9+7;\n\nS op(S a, S b) {\n    return {a.val + b.val, a.size + b.size};\n\
    }\nS e() { return {0, 0}; }\nS mapping(F f, S x) {\n    if(f != ID) x.val = f*x.size;\n\
    \    return x;\n}\nF composition(F f, F g) {\n    return (f == ID ? g : f);\n\
    }\nF id() { return ID; }\n\nint main() {\n    ios_base::sync_with_stdio(0);\n\
    \    int n, q;\n    cin>>n>>q;\n    vector<S> v(n, {0, 1});\n    LazySegmentTree<S,\
    \ op, e, F, mapping, composition, id> seg(v);\n    while(q--) {\n        int typ,\
    \ a, b;\n        cin>>typ>>a>>b;\n        if(typ==0) {\n            int x;\n \
    \           cin>>x;\n            seg.apply(a, b+1, x);\n        } else {\n   \
    \         cout<<seg.prod(a, b+1).val<<'\\n';\n        }\n    }\n    return 0;\n\
    }"
  dependsOn:
  - segtree/lazysegtree.hpp
  isVerificationFile: true
  path: test/aoj/DSL_2_I-RSQ and RUQ.lazysegtree.test.cpp
  requiredBy: []
  timestamp: '2022-12-31 22:49:07+06:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/DSL_2_I-RSQ and RUQ.lazysegtree.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/DSL_2_I-RSQ and RUQ.lazysegtree.test.cpp
- /verify/test/aoj/DSL_2_I-RSQ and RUQ.lazysegtree.test.cpp.html
title: test/aoj/DSL_2_I-RSQ and RUQ.lazysegtree.test.cpp
---
