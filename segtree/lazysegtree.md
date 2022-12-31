---
title: Lazy Segtree
documentation_of: ./lazysegtree.hpp
---

## Constructor
1. lazy_segtree<S, op, e, F, mapping, composition, id> seg(int n); <br/>
2. lazy_segtree<S, op, e, F, mapping, composition, id> seg(vector<T> v); <br/>

The following should be defined.

- The type S of the monoid
- The binary operation S op(S a, S b)
- The function S e() that returns ee
- The type F of the map
- The function S mapping(F f, S x) that returns $f(x)$
- The function F composition(F f, F g) that returns f $\mathrm{\circ gf∘g}$
- The function F id() that returns $\mathrm{id}$

### S & F
S is data, the type of each element and interval retrieval result. <br/>
F is lazy, the type of values that represent operations(maps).

### S op(S a, S b)
Defines what kind of calculation is used to obtain the interval.

### S mapping(F f, S x)
A function $\mathrm{f}$ that operates on the data value of each node $x$.

### F composition(F f, F g)
It is a function that adds a new operation to lazy that has already accumulated the operations so far. g is the operation so far, f is the operation to be added after, and returns "a set of operations (composition map) that performs the two operations in order".

### S e(), F id()
These are the functions that return the identity map for the interval retrieval operation and the interval manipulation operation respectively.<br/>
The identity element e of a binary operation is the one that satisfies all op. <br/>

As a frequently used unit element or identity map, if minimum: +∞, if maximum: −∞, if sum or addition: 0, if it is a product or multiplication: 1 should be used. <br/>

$\mathrm{mapping}$ The identity map in an operating function is id. In the case of an interval addition operation, "a value that never changes the target value even if added". <br/>

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
Since the interval width is required, it has a value in a structure. Get the value with $\mathrm{seg.prod(l, r).value}$
[RSQ and RAQ](https://onlinejudge.u-aizu.ac.jp/problems/DSL_2_G)
```cpp
struct S {
    long long value; // actual value
    int size; // interval width
};
using F = long long;

S op(S a, S b) { return {a.value+b.value, a.size+b.size}; }
S e() { return {0, 0}; }
S mapping(F f, S x) { return (x.value + f*x.size, x.size); }
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
    std::vector<S> v(N);
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