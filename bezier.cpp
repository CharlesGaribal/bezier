#include "bezier.h"

#include <stdexcept>
#include <cassert>

const float Bezier::DEFAULT_PRECISION = 0.05f;

Bezier::Bezier() :
    Bezier(Point2f(0,0), Point2f(0,0)) {
}

Bezier::Bezier(const Point2f &c1, const Point2f &c2) :
    Bezier(c1, c2, DEFAULT_PRECISION) {
}

Bezier::Bezier(const Point2f &c1, const Point2f &c2, float precision) :
    controls({c1,c2}),
    precision(precision) {
    update();
}

void Bezier::addControl(const Point2f &c) {
    controls.push_back(c);
    update();
}

void Bezier::removeControl(std::size_t num) {
    std::size_t size = controls.size();

    if (size <= 2)
        throw std::logic_error("Bezier curve must contain at least 2 control points");

    assert(num < size);
    controls.erase(controls.begin() + num);
    update();
}

void Bezier::setControl(std::size_t num, const Point2f &c) {
    assert(num < controls.size());
    controls[num] = c;
    update();
}

const Point2f& Bezier::getControl(std::size_t num) const {
    assert(num < controls.size());
    return controls[num];
}

const std::vector<Point2f>& Bezier::getCurve() const {
    return curve;
}

float Bezier::getPrecision() const {
    return precision;
}

void Bezier::setPrecision(float value) {
    precision = value;
}

void Bezier::update() {
    curve.clear();

    for (float t = 0.f ; t <= 1.f ; t += precision)
        curve.push_back(tCurve(controls, t));
}

Point2f Bezier::tCurve(std::vector<Point2f> points, float t) {
    std::vector<Point2f> npoints;
    std::size_t size = points.size();

    if (size == 1)
        return points[0];
    else {
        for (std::size_t i = 0 ; i < size - 1 ; i++)
            npoints.push_back((points[i+1] - points[i]) * t + points[i]);

        return tCurve(npoints, t);
    }
}


