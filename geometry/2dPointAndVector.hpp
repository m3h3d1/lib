#pragma once
#include "2dGeometryTemplate.hpp"

Point projection(const Line& l, const Point& p) {
    return l.a + (l.a - l.b) * dot(p - l.a, l.a - l.b) / norm(l.a - l.b);
}

Point reflection(const Line& l, const Point& p) {
    return p + (projection(l, p) - p) * 2.0;
}

int ccw(const Point& a, Point b, Point c) {
    b -= a, c -= a;
    if (sign(cross(b, c)) == +1) return +1; // COUNTER_CLOCKWISE
    if (sign(cross(b, c)) == -1) return -1;// CLOCKWISE
    if (sign(dot(b, c)) == -1) return +2; // ONLINE_BACK
    if (norm(b) < norm(c)) return -2; // ONLINE_FRONT
    return 0; // ON_SEGMENT
}