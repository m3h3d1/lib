---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: segtree/segtree.hpp
    title: segtree/segtree.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/predecessor_problem
    links:
    - https://judge.yosupo.jp/problem/predecessor_problem
  bundledCode: "#line 1 \"test/yosupo/predecessor_problem.segtree.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/predecessor_problem\"\n#include <bits/stdc++.h>\n\
    using namespace std;\n#line 2 \"segtree/segtree.hpp\"\n\ntemplate <class S, S\
    \ (*op)(S, S), S (*e)()>\nstruct SegmentTree {\n  private:\n    int _n, size,\
    \ log;\n    vector<S> dat;\n    void update(int k) { dat[k] = op(dat[2 * k], dat[2\
    \ * k + 1]); }\n\n  public:\n    SegmentTree() : SegmentTree(0) {}\n    SegmentTree(int\
    \ n) : SegmentTree(vector<S>(n, e())) {}\n    SegmentTree(const vector<S>& v)\
    \ : _n(int(v.size())) {\n        log = 0;\n        while ((1 << log) < _n) log++;\n\
    \        size = 1 << log;\n        dat = vector<S>(2 * size, e());\n        for\
    \ (int i = 0; i < _n; i++) dat[size + i] = v[i];\n        for (int i = size -\
    \ 1; i >= 1; i--) {\n            update(i);\n        }\n    }\n    // a[p] = x\n\
    \    void set(int p, S x) {\n        p += size;\n        dat[p] = x;\n       \
    \ for (int i = 1; i <= log; i++) update(p >> i);\n    }\n    // return a[p]\n\
    \    S get(int p) const { return dat[p + size]; }\n    // return op(a[l], ...,\
    \ a[r-1]), return e() if l = r\n    S prod(int l, int r) const {\n        S sml\
    \ = e(), smr = e();\n        l += size;\n        r += size;\n        while (l\
    \ < r) {\n            if (l & 1) sml = op(sml, dat[l++]);\n            if (r &\
    \ 1) smr = op(dat[--r], smr);\n            l >>= 1;\n            r >>= 1;\n  \
    \      }\n        return op(sml, smr);\n    }\n    // return op(a[l], ..., a[r-1]),\
    \ return e() if n = 0\n    S all_prod() const { return dat[1]; }\n\n    // Binary\
    \ search on SegmentTree (if needed)\n    // return r, f(op(a[l], ..., a[r-1]))\
    \ == true\n    template <bool (*f)(S)>\n    int max_right(int l) const {\n   \
    \     return max_right(l, [](S x) { return f(x); });\n    }\n    template <class\
    \ F>\n    int max_right(int l, F f) const {\n        assert(f(e()));\n       \
    \ if (l == _n) return _n;\n        l += size;\n        S sm = e();\n        do\
    \ {\n            while (l % 2 == 0) l >>= 1;\n            if (!f(op(sm, dat[l])))\
    \ {\n                while (l < size) {\n                    l = (2 * l);\n  \
    \                  if (f(op(sm, dat[l]))) {\n                        sm = op(sm,\
    \ dat[l]);\n                        l++;\n                    }\n            \
    \    }\n                return l - size;\n            }\n            sm = op(sm,\
    \ dat[l]);\n            l++;\n        } while ((l & -l) != l);\n        return\
    \ _n;\n    }\n    // return l, f(op(a[l], ..., a[r-1])) == true\n    template\
    \ <bool (*f)(S)>\n    int min_left(int r) const {\n        return min_left(r,\
    \ [](S x) { return f(x); });\n    }\n    template <class F>\n    int min_left(int\
    \ r, F f) const {\n        assert(f(e()));\n        if (r == 0) return 0;\n  \
    \      r += size;\n        S sm = e();\n        do {\n            r--;\n     \
    \       while (r > 1 && (r % 2)) r >>= 1;\n            if (!f(op(dat[r], sm)))\
    \ {\n                while (r < size) {\n                    r = (2 * r + 1);\n\
    \                    if (f(op(dat[r], sm))) {\n                        sm = op(dat[r],\
    \ sm);\n                        r--;\n                    }\n                }\n\
    \                return r + 1 - size;\n            }\n            sm = op(dat[r],\
    \ sm);\n        } while ((r & -r) != r);\n        return 0;\n    }\n}; // SegmentTree\n\
    #line 5 \"test/yosupo/predecessor_problem.segtree.test.cpp\"\n\n#define ff first\n\
    #define ss second\n#define pb push_back\ntypedef long long ll;\ntypedef pair<int,int>\
    \ pii;\n#define all(v) (v).begin(),(v).end()\n#define db(x) cerr<<__LINE__<<\"\
    : \"<<#x<<\" = \"<<(x)<<'\\n'\nconst char en = '\\n';\nconst int inf = 1e9+7;\n\
    const int N = 1e6+9;\n\nint op(int a, int b) { return a | b; }\nint e() { return\
    \ 0; }\nint f(int a) {\n    return !a;\n}\n\nint main() {\n    ios_base::sync_with_stdio(0);\n\
    \    int n, q;\n    string s;\n    cin>>n>>q>>s;\n    vector<int> v(n);\n    for(int\
    \ i=0;i<n;++i) \n        if(s[i]=='1') v[i] = 1;\n    SegmentTree<int, op, e>\
    \ seg(v);\n    while(q--) {\n        int typ, k;\n        cin>>typ>>k;\n     \
    \   if(typ==0) {\n            if(!seg.get(k))\n                seg.set(k, 1);\n\
    \        } else if(typ==1) {\n            if(seg.get(k))\n                seg.set(k,\
    \ 0);\n        } else if(typ==2) {\n            if(seg.get(k))\n             \
    \   cout<<\"1\\n\";\n            else cout<<\"0\\n\";\n        } else if(typ==3)\
    \ {\n            int res = seg.max_right(k, f);\n            if(res==n) res =\
    \ -1;\n            cout<<res<<en;\n        } else if(typ==4) {\n            int\
    \ res = seg.min_left(k+1, f);\n            --res;\n            cout<<res<<en;\n\
    \        }\n    }\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/predecessor_problem\"\n\
    #include <bits/stdc++.h>\nusing namespace std;\n#include \"../../segtree/segtree.hpp\"\
    \n\n#define ff first\n#define ss second\n#define pb push_back\ntypedef long long\
    \ ll;\ntypedef pair<int,int> pii;\n#define all(v) (v).begin(),(v).end()\n#define\
    \ db(x) cerr<<__LINE__<<\": \"<<#x<<\" = \"<<(x)<<'\\n'\nconst char en = '\\n';\n\
    const int inf = 1e9+7;\nconst int N = 1e6+9;\n\nint op(int a, int b) { return\
    \ a | b; }\nint e() { return 0; }\nint f(int a) {\n    return !a;\n}\n\nint main()\
    \ {\n    ios_base::sync_with_stdio(0);\n    int n, q;\n    string s;\n    cin>>n>>q>>s;\n\
    \    vector<int> v(n);\n    for(int i=0;i<n;++i) \n        if(s[i]=='1') v[i]\
    \ = 1;\n    SegmentTree<int, op, e> seg(v);\n    while(q--) {\n        int typ,\
    \ k;\n        cin>>typ>>k;\n        if(typ==0) {\n            if(!seg.get(k))\n\
    \                seg.set(k, 1);\n        } else if(typ==1) {\n            if(seg.get(k))\n\
    \                seg.set(k, 0);\n        } else if(typ==2) {\n            if(seg.get(k))\n\
    \                cout<<\"1\\n\";\n            else cout<<\"0\\n\";\n        }\
    \ else if(typ==3) {\n            int res = seg.max_right(k, f);\n            if(res==n)\
    \ res = -1;\n            cout<<res<<en;\n        } else if(typ==4) {\n       \
    \     int res = seg.min_left(k+1, f);\n            --res;\n            cout<<res<<en;\n\
    \        }\n    }\n    return 0;\n}"
  dependsOn:
  - segtree/segtree.hpp
  isVerificationFile: true
  path: test/yosupo/predecessor_problem.segtree.test.cpp
  requiredBy: []
  timestamp: '2023-01-01 05:46:32+06:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/predecessor_problem.segtree.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/predecessor_problem.segtree.test.cpp
- /verify/test/yosupo/predecessor_problem.segtree.test.cpp.html
title: test/yosupo/predecessor_problem.segtree.test.cpp
---
