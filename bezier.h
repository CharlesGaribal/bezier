#ifndef BEZIER_H
#define BEZIER_H

#include "point2f.h"
#include <vector>
#include <iterator>

class Bezier
{
public:
    static const float DEFAULT_PRECISION;

    Bezier();
    Bezier(const Point2f &, const Point2f &);
    Bezier(const Point2f &, const Point2f &, float precision);

    void addControl(const Point2f &c);
    void setControl(std::size_t num, const Point2f &c);
    void removeControl(std::size_t num);

    const Point2f &getControl(std::size_t num) const;
    const std::vector<Point2f>& getCurve() const;

    float getPrecision() const;
    void setPrecision(float value);

private:
    std::vector<Point2f> controls;
    std::vector<Point2f> curve;
    float precision;

    void update();
    Point2f tCurve(std::vector<Point2f> points, float t);
};

#endif // BEZIER_H
