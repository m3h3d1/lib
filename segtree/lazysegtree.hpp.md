---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL_2_D-RUQ.lazysegtree.test.cpp
    title: test/aoj/DSL_2_D-RUQ.lazysegtree.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL_2_E-RAQ.segtree.test.cpp
    title: test/aoj/DSL_2_E-RAQ.segtree.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL_2_F-RMQ_and_RUQ.lazysegtree.test.cpp
    title: test/aoj/DSL_2_F-RMQ_and_RUQ.lazysegtree.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL_2_G-RSQ_and_RAQ.lazysegtree.test.cpp
    title: test/aoj/DSL_2_G-RSQ_and_RAQ.lazysegtree.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL_2_H-RMQ_and_RAQ.lazysegtree.test.cpp
    title: test/aoj/DSL_2_H-RMQ_and_RAQ.lazysegtree.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL_2_I-RSQ and RUQ.lazysegtree.test.cpp
    title: test/aoj/DSL_2_I-RSQ and RUQ.lazysegtree.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/range_affine_range_sum.lazysegtree.test.cpp
    title: test/yosupo/range_affine_range_sum.lazysegtree.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"segtree/lazysegtree.hpp\"\n\ntemplate <class S,\n      \
    \    S (*op)(S, S),\n          S (*e)(),\n          class F,\n          S (*mapping)(F,\
    \ S),\n          F (*composition)(F, F),\n          F (*id)()>\nstruct LazySegmentTree\
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
    \ r);\n        return 0;\n    }\n}; // LazySegmentTree\n"
  code: "#pragma once\n\ntemplate <class S,\n          S (*op)(S, S),\n          S\
    \ (*e)(),\n          class F,\n          S (*mapping)(F, S),\n          F (*composition)(F,\
    \ F),\n          F (*id)()>\nstruct LazySegmentTree {\n  private:\n    int _n,\
    \ size, log;\n    vector<S> dat;\n    vector<F> lz;\n    void update(int k) {\
    \ dat[k] = op(dat[2 * k], dat[2 * k + 1]); }\n    void all_apply(int k, F f) {\n\
    \        dat[k] = mapping(f, dat[k]);\n        if (k < size) lz[k] = composition(f,\
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
    \ sm);\n        } while ((r & -r) != r);\n        return 0;\n    }\n}; // LazySegmentTree"
  dependsOn: []
  isVerificationFile: false
  path: segtree/lazysegtree.hpp
  requiredBy: []
  timestamp: '2022-12-31 22:49:07+06:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/DSL_2_I-RSQ and RUQ.lazysegtree.test.cpp
  - test/aoj/DSL_2_H-RMQ_and_RAQ.lazysegtree.test.cpp
  - test/aoj/DSL_2_G-RSQ_and_RAQ.lazysegtree.test.cpp
  - test/aoj/DSL_2_F-RMQ_and_RUQ.lazysegtree.test.cpp
  - test/aoj/DSL_2_E-RAQ.segtree.test.cpp
  - test/aoj/DSL_2_D-RUQ.lazysegtree.test.cpp
  - test/yosupo/range_affine_range_sum.lazysegtree.test.cpp
documentation_of: segtree/lazysegtree.hpp
layout: document
title: Lazy Segtree
---

## Constructor
1. lazy_segtree<S, op, e, F, mapping, composition, id> seg(int n); <br/>
2. lazy_segtree<S, op, e, F, mapping, composition, id> seg(vector<T> v); <br/>

The following should be defined.

- The type S of the monoid
- The binary operation S op(S a, S b)
- The function S e() that returns e
- The type F of the map
- The function S mapping(F f, S x) that returns $f(x)$
- The function F composition(F f, F g) that returns $\mathrm{\circ f∘g}$
- The function F id() that returns $id$

### S & F
S is data, the type of each element and range query result. <br/>
F is lazy, the type of values that represent operations(maps).

### S op(S a, S b)
Defines what kind of calculation is used to obtain the interval.

### S mapping(F f, S x)
A function $f$ that operates on the data value of each node $x$.

### F composition(F f, F g)
It is a function that adds a new operation to lazy that has already accumulated the operations so far. $g$ is the operation so far, $f$ is the operation to be added after, and returns "a set of operations (composition map) that performs the two operations in order".

### S e(), F id()
These are the functions that return the identity map for the interval retrieval operation and the interval manipulation operation respectively.<br/>
The identity element e of a binary operation is the one that satisfies all op. <br/>

As a frequently used unit element or identity map, if minimum: +∞, if maximum: −∞, if sum or addition: 0, if it is a product or multiplication: 1 should be used. <br/>

$mapping$ The identity map in an operating function is $id$. In the case of an interval addition operation, "a value that never changes the target value even if added". <br/>

## Example
### Sample
```cpp
struct S {};
S op(S a, S b) {
    return {};
}
S e() { return {}; };
using F = bool;
S mp(F f, S x) {
    return x;
}
F composition(F fnew, F gold) { return fnew ^ gold; }
F id() { return false; }

vector<S> v;
LazySegmentTree<S, op, e, F, mp, composition, id> seg(v);
```

### Range addition/ Range minimum query
[RMQ and RAQ](https://onlinejudge.u-aizu.ac.jp/problems/DSL_2_H)
```cpp
using S = long long;
using F = long long;

const S INF = 8e18;

S op(S a, S b){ return std::min(a, b); }
S e(){ return INF; }
S mapping(F f, S x){ return f+x; }
F composition(F f, F g){ return f+g; }
F id(){ return 0; }

int main(){
    int N;
    std::vector<S> v(N);
    LazySegmentTree<S, op, e, F, mapping, composition, id> seg(v);
}
```

### Range addition/ Range maximum query
```cpp
using S = long long;
using F = long long;

const S INF = 8e18;

S op(S a, S b){ return std::max(a, b); }
S e(){ return -INF; }
S mapping(F f, S x){ return f+x; }
F composition(F f, F g){ return f+g; }
F id(){ return 0; }

int main(){
    int N;
    std::vector<S> v(N);
    LazySegmentTree<S, op, e, F, mapping, composition, id> seg(v);
}
```

### Range Addition/ Range Sum query
Since the interval width is required, it has a value in a structure. Get the value with $seg.prod(l, r).val$
[RSQ and RAQ](https://onlinejudge.u-aizu.ac.jp/problems/DSL_2_G)
```cpp
struct S {
    long long val; // actual value
    int size; // interval width
};
using F = long long;

S op(S a, S b) { 
    return {a.val + b.val, a.size + b.size}; 
}
S e() { return {0, 0}; }
S mapping(F f, S x) {
    return {x.val + f*x.size, x.size};
}
F composition(F f, F g) { return f+g; }
F id() { return 0; }

int main(){
    int N;
    std::vector<S> v(N, {0, 1});
    LazySegmentTree<S, op, e, F, mapping, composition, id> seg(v);
}
```

### Range update/ Range minimum query
[RMQ and RUQ](https://onlinejudge.u-aizu.ac.jp/problems/DSL_2_F)
```cpp
using S = long long;
using F = long long;

const S INF = 8e18;
const F ID = 8e18;

S op(S a, S b){ return std::min(a, b); }
S e(){ return INF; }
S mapping(F f, S x){ return (f == ID ? x : f); }
F composition(F f, F g){ return (f == ID ? g : f); }
F id(){ return ID; }

int main(){
    int N;
    std::vector<S> v(N); // v(N, INF/ID)?
    LazySegmentTree<S, op, e, F, mapping, composition, id> seg(v);
}
```

### Range update/ Range maximum query
[RMQ and RUQ](https://onlinejudge.u-aizu.ac.jp/problems/DSL_2_F)
```cpp
using S = long long;
using F = long long;

const S INF = 8e18;
const F ID = 8e18;

S op(S a, S b){ return std::max(a, b); }
S e(){ return -INF; }
S mapping(F f, S x){ return (f == ID ? x : f); }
F composition(F f, F g){ return (f == ID ? g : f); }
F id(){ return ID; }

int main(){
    int N;
    std::vector<S> v(N);
    LazySegmentTree<S, op, e, F, mapping, composition, id> seg(v);
}
```

### Range update/ Range sum query
[RSQ and RUQ](https://onlinejudge.u-aizu.ac.jp/problems/DSL_2_I)
```cpp
struct S{
    long long value;
    int size;
};
using F = long long;

const F ID = 8e18;

S op(S a, S b){ return {a.value+b.value, a.size+b.size}; }
S e(){ return {0, 0}; }
S mapping(F f, S x){
    if(f != ID) x.value = f*x.size;
    return x;
}
F composition(F f, F g){ return (f == ID ? g : f); }
F id(){ return ID; }

int main(){
    int N;
    std::vector<S> v(N, {0, 1});
    LazySegmentTree<S, op, e, F, mapping, composition, id> seg(v);
}
```



## Link
- [ACL reference](https://atcoder.github.io/ac-library/production/document_en/lazysegtree.html)
- https://atcoder.jp/contests/practice2/editorial/100
- [Uses](https://betrue12.hateblo.jp/entry/2020/09/22/194541)
- [Cheat Sheet](https://betrue12.hateblo.jp/entry/2020/09/23/005940)