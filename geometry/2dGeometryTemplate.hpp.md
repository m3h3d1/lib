---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: geometry/2dPointAndVector.hpp
    title: geometry/2dPointAndVector.hpp
  - icon: ':heavy_check_mark:'
    path: geometry/2dPointSet.hpp
    title: geometry/2dPointSet.hpp
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
    path: test/aoj/CGL_5_A-Closest_Pair.test.cpp
    title: test/aoj/CGL_5_A-Closest_Pair.test.cpp
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
    \ Point b) : a(a), b(b) {}\n};\nusing Segment = Line;\n"
  code: "#pragma once\n\nusing Real = double;\nusing Point = complex<Real>;\nusing\
    \ Polygon = vector<Point>;\nconst Real EPS = 1e-8, PI = acos(-1);\n\nPoint operator*(const\
    \ Point& p, const Real& d) {\n    return Point(p.real() * d, p.imag() * d);\n\
    }\n\nPoint operator/(const Point& p, const Real& d) {\n    return Point(p.real()\
    \ / d, p.imag() / d);\n}\n\nistream& operator>>(istream& is, Point& p) {\n   \
    \ Real a, b;\n    is >> a >> b;\n    p = Point(a, b);\n    return is;\n}\n\nostream&\
    \ operator<<(ostream& os, const Point& p) {\n    return os << fixed << setprecision(20)\
    \ << p.real() << \" \" << p.imag();\n}\n\nint sign(const Real& r) {\n    if (r\
    \ <= -EPS) return -1;\n    if (r >= +EPS) return +1;\n    return 0;\n}\n\nbool\
    \ equals(const Real& a, const Real& b) {\n    return sign(a - b) == 0;\n}\n\n\
    namespace std {\nbool operator<(const Point& a, const Point& b) {\n    if (equals(a.real(),\
    \ b.real())) return a.imag() < b.imag();\n    return a.real() < b.real();\n}\n\
    }  // namespace std\n\nReal dot(const Point& a, const Point& b) {\n    return\
    \ (conj(a) * b).real();\n}\n\nReal cross(const Point& a, const Point& b) {\n \
    \   return (conj(a) * b).imag();\n}\n\nstruct Line {\n    Point a, b;\n    Line()\
    \ = default;\n    Line(Point a, Point b) : a(a), b(b) {}\n};\nusing Segment =\
    \ Line;"
  dependsOn: []
  isVerificationFile: false
  path: geometry/2dGeometryTemplate.hpp
  requiredBy:
  - geometry/2dPointAndVector.hpp
  - geometry/2dSegmentAndLine.hpp
  - geometry/2dPointSet.hpp
  timestamp: '2023-01-15 01:54:03+06:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/CGL_1_C-CounterClockwise.test.cpp
  - test/aoj/CGL_1_A-Projection.test.cpp
  - test/aoj/CGL_5_A-Closest_Pair.test.cpp
  - test/aoj/CGL_2_A-ParallelOrthogonal.test.cpp
  - test/aoj/CGL_1_B-Reflection.test.cpp
documentation_of: geometry/2dGeometryTemplate.hpp
layout: document
redirect_from:
- /library/geometry/2dGeometryTemplate.hpp
- /library/geometry/2dGeometryTemplate.hpp.html
title: geometry/2dGeometryTemplate.hpp
---
