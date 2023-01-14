---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: geometry/2dGeometryTemplate.hpp
    title: geometry/2dGeometryTemplate.hpp
  - icon: ':question:'
    path: geometry/2dPointAndVector.hpp
    title: geometry/2dPointAndVector.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/problems/CGL_1_A
    links:
    - https://onlinejudge.u-aizu.ac.jp/problems/CGL_1_A
  bundledCode: "#line 1 \"test/aoj/CGL_1_A-Projection.test.cpp\"\n#define PROBLEM\
    \ \"https://onlinejudge.u-aizu.ac.jp/problems/CGL_1_A\"\n#include <bits/stdc++.h>\n\
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
    \ Point b) : a(a), b(b) {}\n};\nusing Segment = Line;\n#line 3 \"geometry/2dPointAndVector.hpp\"\
    \n\nPoint projection(const Line& l, const Point& p) {\n    return l.a + (l.a -\
    \ l.b) * dot(p - l.a, l.a - l.b) / norm(l.a - l.b);\n}\n\nPoint reflection(const\
    \ Line& l, const Point& p) {\n    return p + (projection(l, p) - p) * 2.0;\n}\n\
    \nint ccw(const Point& a, Point b, Point c) {\n    b -= a, c -= a;\n    if (sign(cross(b,\
    \ c)) == +1) return +1; // COUNTER_CLOCKWISE\n    if (sign(cross(b, c)) == -1)\
    \ return -1;// CLOCKWISE\n    if (sign(dot(b, c)) == -1) return +2; // ONLINE_BACK\n\
    \    if (norm(b) < norm(c)) return -2; // ONLINE_FRONT\n    return 0; // ON_SEGMENT\n\
    }\n#line 5 \"test/aoj/CGL_1_A-Projection.test.cpp\"\n\nint main() {\n    ios_base::sync_with_stdio(0);\n\
    \    Point p1, p2;\n    cin>>p1>>p2;\n    Line l = Line(p1, p2);\n\n    int q;\n\
    \    cin>>q;\n    while(q--) {\n        Point p;\n        cin>>p;\n        cout<<projection(l,\
    \ p)<<'\\n';\n    }\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/CGL_1_A\"\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\n#include \"../../geometry/2dPointAndVector.hpp\"\
    \n\nint main() {\n    ios_base::sync_with_stdio(0);\n    Point p1, p2;\n    cin>>p1>>p2;\n\
    \    Line l = Line(p1, p2);\n\n    int q;\n    cin>>q;\n    while(q--) {\n   \
    \     Point p;\n        cin>>p;\n        cout<<projection(l, p)<<'\\n';\n    }\n\
    \    return 0;\n}"
  dependsOn:
  - geometry/2dPointAndVector.hpp
  - geometry/2dGeometryTemplate.hpp
  isVerificationFile: true
  path: test/aoj/CGL_1_A-Projection.test.cpp
  requiredBy: []
  timestamp: '2023-01-15 01:54:03+06:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/aoj/CGL_1_A-Projection.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/CGL_1_A-Projection.test.cpp
- /verify/test/aoj/CGL_1_A-Projection.test.cpp.html
title: test/aoj/CGL_1_A-Projection.test.cpp
---
