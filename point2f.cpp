#include "point2f.h"

Point2f::Point2f() :
    Point2f(0,0) {
}

Point2f::Point2f(int x = 0, int y = 0) :
    x(x),
    y(y) {
}

Point2f &Point2f::operator+=(const Point2f &p) {
    x += p.x;
    y += p.y;
    return *this;
}

Point2f &Point2f::operator-=(const Point2f &p) {
    x -= p.x;
    y -= p.y;
    return *this;
}

Point2f &Point2f::operator*=(float s) {
    x *= s;
    y *= s;
    return *this;
}

 Point2f operator+(const Point2f &p1, const Point2f &p2) {
    Point2f p(p1);
    p += p2;
    return p;
}

Point2f operator-(const Point2f &p1, const Point2f &p2) {
    Point2f p(p1);
    p -= p2;
    return p;
}

Point2f operator*(const Point2f &p, float s) {
    Point2f np(p);
    np *= s;
    return np;
}
