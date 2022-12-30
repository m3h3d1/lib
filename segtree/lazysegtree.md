https://atcoder.github.io/ac-library/production/document_en/lazysegtree.html

https://atcoder.jp/contests/practice2/editorial/100

## Constructor
(1) lazy_segtree<S, op, e, F, mapping, composition, id> seg(int n);
(2) lazy_segtree<S, op, e, F, mapping, composition, id> seg(vector<T> v);

The following should be defined.

- The type S of the monoid
- The binary operation S op(S a, S b)
- The function S e() that returns ee
- The type F of the map
- The function S mapping(F f, S x) that returns f(x)f(x)
- The function F composition(F f, F g) that returns f \circ gf∘g
- The function F id() that returns \mathrm{id}id