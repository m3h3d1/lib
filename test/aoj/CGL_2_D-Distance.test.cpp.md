---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: geometry/2dGeometryTemplate.hpp
    title: geometry/2dGeometryTemplate.hpp
  - icon: ':heavy_check_mark:'
    path: geometry/2dPointAndVector.hpp
    title: geometry/2dPointAndVector.hpp
  - icon: ':heavy_check_mark:'
    path: geometry/2dSegmentAndLine.hpp
    title: geometry/2dSegmentAndLine.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    ERROR: '0.00000001'
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/problems/CGL_2_D
    links:
    - https://onlinejudge.u-aizu.ac.jp/problems/CGL_2_D
  bundledCode: "#line 1 \"test/aoj/CGL_2_D-Distance.test.cpp\"\n#define PROBLEM \"\
    https://onlinejudge.u-aizu.ac.jp/problems/CGL_2_D\"\n#include <bits/stdc++.h>\n\
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
    }\n#line 2 \"geometry/2dSegmentAndLine.hpp\"\n\nbool is_orthogonal(const Line&\
    \ a, const Line& b) {\n    return equals(dot(a.b - a.a, b.b - b.a), 0);\n}\n\n\
    bool is_parallel(const Line& a, const Line& b) {\n    return equals(cross(a.b\
    \ - a.a, b.b - b.a), 0);\n}\n\nbool is_intersect_ss(const Segment& s, const Segment&\
    \ t) {\n    return ccw(s.a, s.b, t.a) * ccw(s.a, s.b, t.b) <= 0 &&\n         \
    \  ccw(t.a, t.b, s.a) * ccw(t.a, t.b, s.b) <= 0;\n}\n\nPoint cross_point_ll(const\
    \ Line& l, const Line& m) {\n    Real A = cross(l.b - l.a, m.b - m.a);\n    Real\
    \ B = cross(l.b - l.a, l.b - m.a);\n    if (equals(abs(A), 0) && equals(abs(B),\
    \ 0)) return m.a;\n    return m.a + (m.b - m.a) * B / A;\n}\n\nReal distance_sp(const\
    \ Segment& s, const Point& p) {\n    Point r = projection(s, p);\n    if (ccw(s.a,\
    \ s.b, r) == 0) return abs(r - p);\n    return min(abs(s.a - p), abs(s.b - p));\n\
    }\n\nReal distance_ss(const Segment& a, const Segment& b) {\n    if (is_intersect_ss(a,\
    \ b)) return 0;\n    return min({distance_sp(a, b.a), distance_sp(a, b.b), distance_sp(b,\
    \ a.a), distance_sp(b, a.b)});\n}\n#line 5 \"test/aoj/CGL_2_D-Distance.test.cpp\"\
    \n#define ERROR 0.00000001\n\nint main() {\n    ios_base::sync_with_stdio(0);\n\
    \    int q;\n    cin>>q;\n    while(q--) {\n        Point p0, p1, p2, p3;\n  \
    \      cin>>p0>>p1>>p2>>p3;\n        Segment s1 = Segment(p0, p1);\n        Segment\
    \ s2 = Segment(p2, p3);\n\n        Real d = distance_ss(s1, s2);\n\n        cout<<fixed<<setprecision(12)<<d<<'\\\
    n';\n    }\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/CGL_2_D\"\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\n#include \"../../geometry/2dSegmentAndLine.hpp\"\
    \n#define ERROR 0.00000001\n\nint main() {\n    ios_base::sync_with_stdio(0);\n\
    \    int q;\n    cin>>q;\n    while(q--) {\n        Point p0, p1, p2, p3;\n  \
    \      cin>>p0>>p1>>p2>>p3;\n        Segment s1 = Segment(p0, p1);\n        Segment\
    \ s2 = Segment(p2, p3);\n\n        Real d = distance_ss(s1, s2);\n\n        cout<<fixed<<setprecision(12)<<d<<'\\\
    n';\n    }\n    return 0;\n}"
  dependsOn:
  - geometry/2dSegmentAndLine.hpp
  - geometry/2dPointAndVector.hpp
  - geometry/2dGeometryTemplate.hpp
  isVerificationFile: true
  path: test/aoj/CGL_2_D-Distance.test.cpp
  requiredBy: []
  timestamp: '2023-01-15 03:18:30+06:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/CGL_2_D-Distance.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/CGL_2_D-Distance.test.cpp
- /verify/test/aoj/CGL_2_D-Distance.test.cpp.html
title: test/aoj/CGL_2_D-Distance.test.cpp
---
