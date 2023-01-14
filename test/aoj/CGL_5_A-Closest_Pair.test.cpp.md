---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: geometry/2dGeometryTemplate.hpp
    title: geometry/2dGeometryTemplate.hpp
  - icon: ':x:'
    path: geometry/2dPointSet.hpp
    title: geometry/2dPointSet.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/problems/CGL_5_A
    links:
    - https://onlinejudge.u-aizu.ac.jp/problems/CGL_5_A
  bundledCode: "#line 1 \"test/aoj/CGL_5_A-Closest_Pair.test.cpp\"\n#define PROBLEM\
    \ \"https://onlinejudge.u-aizu.ac.jp/problems/CGL_5_A\"\n#include <bits/stdc++.h>\n\
    using namespace std;\n#line 2 \"geometry/2dGeometryTemplate.hpp\"\n\nusing Real\
    \ = double;\nusing Point = complex<Real>;\nusing Polygon = vector<Point>;\nconst\
    \ Real EPS = 1e-8, PI = acos(-1);\n\nPoint operator*(const Point& p, const Real&\
    \ d) {\n    return Point(p.real() * d, p.imag() * d);\n}\n\nPoint operator/(const\
    \ Point& p, const Real& d) {\n    return Point(p.real() / d, p.imag() / d);\n\
    }\n\nistream& operator>>(istream& is, Point& p) {\n    Real a, b;\n    is >> a\
    \ >> b;\n    p = Point(a, b);\n    return is;\n}\n\nostream& operator<<(ostream&\
    \ os, const Point& p) {\n    return os << fixed << setprecision(20) << p.real()\
    \ << \" \" << p.imag();\n}\n\nint sign(const Real& r) {\n    if (r <= -EPS) return\
    \ -1;\n    if (r >= +EPS) return +1;\n    return 0;\n}\n\nbool equals(const Real&\
    \ a, const Real& b) {\n    return sign(a - b) == 0;\n}\n\nnamespace std {\nbool\
    \ operator<(const Point& a, const Point& b) {\n    if (equals(a.real(), b.real()))\
    \ return a.imag() < b.imag();\n    return a.real() < b.real();\n}\n}  // namespace\
    \ std\n\nReal dot(const Point& a, const Point& b) {\n    return (conj(a) * b).real();\n\
    }\n\nReal cross(const Point& a, const Point& b) {\n    return (conj(a) * b).imag();\n\
    }\n\nstruct Line {\n    Point a, b;\n    Line() = default;\n    Line(Point a,\
    \ Point b) : a(a), b(b) {}\n};\nusing Segment = Line;\n#line 3 \"geometry/2dPointSet.hpp\"\
    \n\nReal closest_pair(Polygon ps) {\n    sort(ps.begin(), ps.end());\n    Polygon\
    \ a(ps.size());\n\n    function<Real(int, int)> rec = [&](int left, int right)\
    \ -> Real {\n        if (right - left <= 1) return 1e18;\n        int mid = (left\
    \ + right) / 2;\n        Real x = ps[mid].real();\n        Real ret = min(rec(left,\
    \ mid), rec(mid, right));\n        inplace_merge(ps.begin() + left, ps.begin()\
    \ + mid, ps.begin() + right,\n                      [&](const Point& a, const\
    \ Point& b) { return a.imag() < b.imag(); });\n        int pos = 0;\n        for\
    \ (int i = left; i < right; i++) {\n            if (fabs((ps[i].real()) - x) >=\
    \ ret) continue;\n            for (int j = 0; j < pos; j++) {\n              \
    \  auto tar = ps[i] - a[pos - j - 1];\n                if (tar.imag() >= ret)\
    \ break;\n                ret = min(ret, abs(tar));\n            }\n         \
    \   a[pos++] = ps[i];\n        }\n        return ret;\n    };\n    return rec(0,\
    \ (int)ps.size());\n}\n#line 5 \"test/aoj/CGL_5_A-Closest_Pair.test.cpp\"\n\n\
    int main() {\n    int n;\n    cin>>n;\n    Polygon ps(n);\n    for(int i=0;i<n;++i)\
    \ {\n        cin>>ps[i];\n    }\n    cout<<fixed<<setprecision(20)<<closest_pair(ps)<<'\\\
    n';\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/CGL_5_A\"\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\n#include \"../../geometry/2dPointSet.hpp\"\
    \n\nint main() {\n    int n;\n    cin>>n;\n    Polygon ps(n);\n    for(int i=0;i<n;++i)\
    \ {\n        cin>>ps[i];\n    }\n    cout<<fixed<<setprecision(20)<<closest_pair(ps)<<'\\\
    n';\n    return 0;\n}"
  dependsOn:
  - geometry/2dPointSet.hpp
  - geometry/2dGeometryTemplate.hpp
  isVerificationFile: true
  path: test/aoj/CGL_5_A-Closest_Pair.test.cpp
  requiredBy: []
  timestamp: '2023-01-15 02:17:43+06:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/aoj/CGL_5_A-Closest_Pair.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/CGL_5_A-Closest_Pair.test.cpp
- /verify/test/aoj/CGL_5_A-Closest_Pair.test.cpp.html
title: test/aoj/CGL_5_A-Closest_Pair.test.cpp
---
