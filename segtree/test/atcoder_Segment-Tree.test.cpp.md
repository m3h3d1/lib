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
  bundledCode: "#line 1 \"segtree/test/atcoder_Segment-Tree.test.cpp\"\n#include <bits/stdc++.h>\n\
    using namespace std;\n#line 2 \"segtree/acl_segtree.hpp\"\n\n#ifndef ATCODER_INTERNAL_BITOP_HPP\n\
    #define ATCODER_INTERNAL_BITOP_HPP 1\n\n#ifdef _MSC_VER\n#include <intrin.h>\n\
    #endif\n\nnamespace atcoder {\n\nnamespace internal {\n\n// @param n `0 <= n`\n\
    // @return minimum non-negative `x` s.t. `n <= 2**x`\nint ceil_pow2(int n) {\n\
    \    int x = 0;\n    while ((1U << x) < (unsigned int)(n)) x++;\n    return x;\n\
    }\n\n// @param n `1 <= n`\n// @return minimum non-negative `x` s.t. `(n & (1 <<\
    \ x)) != 0`\nint bsf(unsigned int n) {\n#ifdef _MSC_VER\n    unsigned long index;\n\
    \    _BitScanForward(&index, n);\n    return index;\n#else\n    return __builtin_ctz(n);\n\
    #endif\n}\n\n} // namespace internal\n\n} // namespace atcoder\n\n#endif // ATCODER_INTERNAL_BITOP_HPP\n\
    \n#ifndef ATCODER_SEGTREE_HPP\n#define ATCODER_SEGTREE_HPP 1\n\n#include <algorithm>\n\
    #include <cassert>\n#include <vector>\n\n// #include \"atcoder/internal_bit\"\n\
    \nnamespace atcoder {\n\n// The following should be defined:\n// The type S (monoid)\n\
    // The binary operation S op(S a, S b)\n// The identity element S e()\ntemplate\
    \ <class S, S (*op)(S, S), S (*e)()> struct segtree {\npublic:\n    segtree()\
    \ : segtree(0) {}\n    explicit segtree(int n) : segtree(std::vector<S>(n, e()))\
    \ {}\n    explicit segtree(const std::vector<S> &v) : _n(int(v.size())) {\n  \
    \      log = internal::ceil_pow2(_n);\n        size = 1 << log;\n        d = std::vector<S>(2\
    \ * size, e());\n        for (int i = 0; i < _n; i++) d[size + i] = v[i];\n  \
    \      for (int i = size - 1; i >= 1; i--) { update(i); }\n    }\n\n    void set(int\
    \ p, S x) { // assigns x to a[p]\n        assert(0 <= p && p < _n);\n        p\
    \ += size;\n        d[p] = x;\n        for (int i = 1; i <= log; i++) update(p\
    \ >> i);\n    }\n\n    S get(int p) const { // returns a[p]\n        assert(0\
    \ <= p && p < _n);\n        return d[p + size];\n    }\n\n    // returns op(a[l],\
    \ ..., a[r - 1]), assuming the properties of the monoid. \n    // It returns e()\
    \ if l = r\n    S prod(int l, int r) const {\n        assert(0 <= l && l <= r\
    \ && r <= _n);\n        S sml = e(), smr = e();\n        l += size;\n        r\
    \ += size;\n\n        while (l < r) {\n            if (l & 1) sml = op(sml, d[l++]);\n\
    \            if (r & 1) smr = op(d[--r], smr);\n            l >>= 1;\n       \
    \     r >>= 1;\n        }\n        return op(sml, smr);\n    }\n\n    // returns\
    \ op(a[0], ..., a[n - 1]), assuming the properties of the monoid.\n    // It returns\
    \ e() if n = 0\n    S all_prod() const { return d[1]; }\n\n    // applies binary\
    \ search on the segment tree. The function bool f(S x) should be defined\n   \
    \ template <bool (*f)(S)> int max_right(int l) const {\n        return max_right(l,\
    \ [](S x) { return f(x); });\n    }\n    // The function object that takes S as\
    \ the argument and returns bool should be defined\n    template <class F> int\
    \ max_right(int l, F f) const {\n        assert(0 <= l && l <= _n);\n        assert(f(e()));\n\
    \        if (l == _n) return _n;\n        l += size;\n        S sm = e();\n  \
    \      do {\n            while (l % 2 == 0) l >>= 1;\n            if (!f(op(sm,\
    \ d[l]))) {\n                while (l < size) {\n                    l = (2 *\
    \ l);\n                    if (f(op(sm, d[l]))) {\n                        sm\
    \ = op(sm, d[l]);\n                        l++;\n                    }\n     \
    \           }\n                return l - size;\n            }\n            sm\
    \ = op(sm, d[l]);\n            l++;\n        } while ((l & -l) != l);\n      \
    \  return _n;\n    }\n\n    template <bool (*f)(S)> int min_left(int r) const\
    \ {\n        return min_left(r, [](S x) { return f(x); });\n    }\n    template\
    \ <class F> int min_left(int r, F f) const {\n        assert(0 <= r && r <= _n);\n\
    \        assert(f(e()));\n        if (r == 0) return 0;\n        r += size;\n\
    \        S sm = e();\n        do {\n            r--;\n            while (r > 1\
    \ && (r % 2)) r >>= 1;\n            if (!f(op(d[r], sm))) {\n                while\
    \ (r < size) {\n                    r = (2 * r + 1);\n                    if (f(op(d[r],\
    \ sm))) {\n                        sm = op(d[r], sm);\n                      \
    \  r--;\n                    }\n                }\n                return r +\
    \ 1 - size;\n            }\n            sm = op(d[r], sm);\n        } while ((r\
    \ & -r) != r);\n        return 0;\n    }\n\nprivate:\n    int _n, size, log;\n\
    \    std::vector<S> d;\n\n    void update(int k) { d[k] = op(d[2 * k], d[2 * k\
    \ + 1]); }\n};\n\n} // namespace atcoder\n\n#endif // ATCODER_SEGTREE_HPP\n\n\
    // Reference: https://atcoder.github.io/ac-library/document_ja/segtree.html\n\
    /* usage:\nstruct S {\n    long long su;\n    int nb;\n};\nS e() { return {0,\
    \ 0}; }\nS op(S l, S r) { return {l.su + r.su, l.nb + r.nb}; }\nvector<S> seginit(100000,\
    \ e());\natcoder::segtree<S, op, e> segtree(seginit);\n*/\n#line 4 \"segtree/test/atcoder_Segment-Tree.test.cpp\"\
    \n#define PROBLEM \"https://atcoder.jp/contests/practice2/tasks/practice2_j\"\n\
    \n#define ff first\n#define ss second\n#define pb push_back\ntypedef long long\
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
    \ f)+1<<en;\n    \t}\n    }\n    return 0;\n}\n"
  code: "#include <bits/stdc++.h>\nusing namespace std;\n#include \"../acl_segtree.hpp\"\
    \n#define PROBLEM \"https://atcoder.jp/contests/practice2/tasks/practice2_j\"\n\
    \n#define ff first\n#define ss second\n#define pb push_back\ntypedef long long\
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
  timestamp: '2022-12-29 19:24:57+06:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: segtree/test/atcoder_Segment-Tree.test.cpp
layout: document
redirect_from:
- /verify/segtree/test/atcoder_Segment-Tree.test.cpp
- /verify/segtree/test/atcoder_Segment-Tree.test.cpp.html
title: segtree/test/atcoder_Segment-Tree.test.cpp
---
