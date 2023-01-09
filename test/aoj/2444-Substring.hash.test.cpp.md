---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: string/rollingHash.hpp
    title: string/rollingHash.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/problems/2444
    links:
    - https://onlinejudge.u-aizu.ac.jp/problems/2444
  bundledCode: "#line 1 \"test/aoj/2444-Substring.hash.test.cpp\"\n#include <bits/stdc++.h>\n\
    using namespace std;\n#line 2 \"string/rollingHash.hpp\"\n\nstruct RollingHash\
    \ {\n    static constexpr int M = 2;\n    static constexpr long long MODS[M] =\
    \ {999999937, 1000000007};\n    static constexpr long long BASE = 9973;\n    vector<long\
    \ long> powb[M], hash[M];\n    int n;\n    RollingHash() {}\n    RollingHash(const\
    \ string& str) { init(str); }\n    void init(const string& str) {\n        n =\
    \ str.size();\n        for (int k = 0; k < M; k++) {\n            powb[k].resize(n\
    \ + 1, 1);\n            hash[k].resize(n + 1, 0);\n            for (int i = 0;\
    \ i < n; i++) {\n                hash[k][i + 1] = (hash[k][i] * BASE + str[i])\
    \ % MODS[k];\n                powb[k][i + 1] = powb[k][i] * BASE % MODS[k];\n\
    \            }\n        }\n    }\n    // get hash str[l,r)\n    long long get(int\
    \ l, int r, int k) {\n        long long res = hash[k][r] - hash[k][l] * powb[k][r\
    \ - l] % MODS[k];\n        if (res < 0) res += MODS[k];\n        return res;\n\
    \    }\n};\n\nbool match(RollingHash& rh1, int l1, int r1, RollingHash& rh2, int\
    \ l2, int r2) {\n    bool res = true;\n    for (int k = 0; k < RollingHash::M;\
    \ k++) {\n        res &= rh1.get(l1, r1, k) == rh2.get(l2, r2, k);\n    }\n  \
    \  return res;\n}\n#line 4 \"test/aoj/2444-Substring.hash.test.cpp\"\n#define\
    \ PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/2444\"\n#define ll long\
    \ long\n\nint main() {\n    ios_base::sync_with_stdio(0);\n    string str, s;\n\
    \    int n, q;\n    cin>>n>>q; cin.ignore();\n    getline(cin, str);\n\n    RollingHash\
    \ rh(str);\n    set<pair<ll, ll>> st;\n    int l=0, r=0;\n    while(q--) {\n \
    \       cin>>s;\n        if(s==\"L++\") {\n            l++;\n        } else if(s==\"\
    L--\") {\n            l--;\n        } else if(s==\"R++\") {\n            r++;\n\
    \        } else {\n            r--;\n        }\n        assert(l>=0 && r>=0);\n\
    \        st.insert({rh.get(l, r+1, 0), rh.get(l, r+1, 1)});\n    }    \n    cout<<st.size()<<'\\\
    n';\n    return 0;\n}\n"
  code: "#include <bits/stdc++.h>\nusing namespace std;\n#include \"../../string/rollingHash.hpp\"\
    \n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/2444\"\n#define\
    \ ll long long\n\nint main() {\n    ios_base::sync_with_stdio(0);\n    string\
    \ str, s;\n    int n, q;\n    cin>>n>>q; cin.ignore();\n    getline(cin, str);\n\
    \n    RollingHash rh(str);\n    set<pair<ll, ll>> st;\n    int l=0, r=0;\n   \
    \ while(q--) {\n        cin>>s;\n        if(s==\"L++\") {\n            l++;\n\
    \        } else if(s==\"L--\") {\n            l--;\n        } else if(s==\"R++\"\
    ) {\n            r++;\n        } else {\n            r--;\n        }\n       \
    \ assert(l>=0 && r>=0);\n        st.insert({rh.get(l, r+1, 0), rh.get(l, r+1,\
    \ 1)});\n    }    \n    cout<<st.size()<<'\\n';\n    return 0;\n}"
  dependsOn:
  - string/rollingHash.hpp
  isVerificationFile: true
  path: test/aoj/2444-Substring.hash.test.cpp
  requiredBy: []
  timestamp: '2023-01-10 04:57:30+06:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/2444-Substring.hash.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/2444-Substring.hash.test.cpp
- /verify/test/aoj/2444-Substring.hash.test.cpp.html
title: test/aoj/2444-Substring.hash.test.cpp
---
