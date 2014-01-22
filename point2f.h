#ifndef POINT2F_H
#define POINT2F_H

class Point2f
{
public:
    double x, y;

    Point2f();
    Point2f(int, int);

    Point2f &operator+=(const Point2f &);
    Point2f &operator-=(const Point2f &);
    Point2f &operator*=(float s);
};

Point2f operator+(const Point2f &, const Point2f &);
Point2f operator-(const Point2f &, const Point2f &);
Point2f operator*(const Point2f &, float s);


#endif // POINT2F_H
