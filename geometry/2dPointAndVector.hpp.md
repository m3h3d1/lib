---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: geometry/2dGeometryTemplate.hpp
    title: geometry/2dGeometryTemplate.hpp
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: geometry/2dSegmentAndLine.hpp
    title: geometry/2dSegmentAndLine.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/CGL_1_A-Projection.test.cpp
    title: test/aoj/CGL_1_A-Projection.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/CGL_1_B-Reflection.test.cpp
    title: test/aoj/CGL_1_B-Reflection.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/CGL_1_C-CounterClockwise.test.cpp
    title: test/aoj/CGL_1_C-CounterClockwise.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/CGL_2_A-ParallelOrthogonal.test.cpp
    title: test/aoj/CGL_2_A-ParallelOrthogonal.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/CGL_2_B-Intersection.test.cpp
    title: test/aoj/CGL_2_B-Intersection.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/CGL_2_C-Cross_Point.test.cpp
    title: test/aoj/CGL_2_C-Cross_Point.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/CGL_2_D-Distance.test.cpp
    title: test/aoj/CGL_2_D-Distance.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"geometry/2dGeometryTemplate.hpp\"\n\nusing Real = double;\n\
    using Point = complex<Real>;\nusing Polygon = vector<Point>;\nconst Real EPS =\
    \ 1e-8, PI = acos(-1);\n\nPoint operator*(const Point& p, const Real& d) {\n \
    \   return Point(p.real() * d, p.imag() * d);\n}\n\nPoint operator/(const Point&\
    \ p, const Real& d) {\n    return Point(p.real() / d, p.imag() / d);\n}\n\nistream&\
    \ operator>>(istream& is, Point& p) {\n    Real a, b;\n    is >> a >> b;\n   \
    \ p = Point(a, b);\n    return is;\n}\n\nostream& operator<<(ostream& os, const\
    \ Point& p) {\n    return os << fixed << setprecision(20) << p.real() << \" \"\
    \ << p.imag();\n}\n\nint sign(const Real& r) {\n    if (r <= -EPS) return -1;\n\
    \    if (r >= +EPS) return +1;\n    return 0;\n}\n\nbool equals(const Real& a,\
    \ const Real& b) {\n    return sign(a - b) == 0;\n}\n\nnamespace std {\nbool operator<(const\
    \ Point& a, const Point& b) {\n    if (equals(a.real(), b.real())) return a.imag()\
    \ < b.imag();\n    return a.real() < b.real();\n}\n}  // namespace std\n\nReal\
    \ dot(const Point& a, const Point& b) {\n    return (conj(a) * b).real();\n}\n\
    \nReal cross(const Point& a, const Point& b) {\n    return (conj(a) * b).imag();\n\
    }\n\nstruct Line {\n    Point a, b;\n    Line() = default;\n    Line(Point a,\
    \ Point b) : a(a), b(b) {}\n};\nusing Segment = Line;\n#line 3 \"geometry/2dPointAndVector.hpp\"\
    \n\nPoint projection(const Line& l, const Point& p) {\n    return l.a + (l.a -\
    \ l.b) * dot(p - l.a, l.a - l.b) / norm(l.a - l.b);\n}\n\nPoint reflection(const\
    \ Line& l, const Point& p) {\n    return p + (projection(l, p) - p) * 2.0;\n}\n\
    \nint ccw(const Point& a, Point b, Point c) {\n    b -= a, c -= a;\n    if (sign(cross(b,\
    \ c)) == +1) return +1; // COUNTER_CLOCKWISE\n    if (sign(cross(b, c)) == -1)\
    \ return -1;// CLOCKWISE\n    if (sign(dot(b, c)) == -1) return +2; // ONLINE_BACK\n\
    \    if (norm(b) < norm(c)) return -2; // ONLINE_FRONT\n    return 0; // ON_SEGMENT\n\
    }\n"
  code: "#pragma once\n#include \"2dGeometryTemplate.hpp\"\n\nPoint projection(const\
    \ Line& l, const Point& p) {\n    return l.a + (l.a - l.b) * dot(p - l.a, l.a\
    \ - l.b) / norm(l.a - l.b);\n}\n\nPoint reflection(const Line& l, const Point&\
    \ p) {\n    return p + (projection(l, p) - p) * 2.0;\n}\n\nint ccw(const Point&\
    \ a, Point b, Point c) {\n    b -= a, c -= a;\n    if (sign(cross(b, c)) == +1)\
    \ return +1; // COUNTER_CLOCKWISE\n    if (sign(cross(b, c)) == -1) return -1;//\
    \ CLOCKWISE\n    if (sign(dot(b, c)) == -1) return +2; // ONLINE_BACK\n    if\
    \ (norm(b) < norm(c)) return -2; // ONLINE_FRONT\n    return 0; // ON_SEGMENT\n\
    }"
  dependsOn:
  - geometry/2dGeometryTemplate.hpp
  isVerificationFile: false
  path: geometry/2dPointAndVector.hpp
  requiredBy:
  - geometry/2dSegmentAndLine.hpp
  timestamp: '2023-01-15 01:54:03+06:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/CGL_2_A-ParallelOrthogonal.test.cpp
  - test/aoj/CGL_1_B-Reflection.test.cpp
  - test/aoj/CGL_2_B-Intersection.test.cpp
  - test/aoj/CGL_1_C-CounterClockwise.test.cpp
  - test/aoj/CGL_1_A-Projection.test.cpp
  - test/aoj/CGL_2_D-Distance.test.cpp
  - test/aoj/CGL_2_C-Cross_Point.test.cpp
documentation_of: geometry/2dPointAndVector.hpp
layout: document
redirect_from:
- /library/geometry/2dPointAndVector.hpp
- /library/geometry/2dPointAndVector.hpp.html
title: geometry/2dPointAndVector.hpp
---
