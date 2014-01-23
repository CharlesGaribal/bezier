#ifndef BEZIER_H
#define BEZIER_H

#include <QPointF>
#include <vector>
#include <iterator>

class Bezier
{
public:
    static const float DEFAULT_PRECISION;

    Bezier();
    Bezier(const QPointF &, const QPointF &);
    Bezier(const QPointF &, const QPointF &, float precision);

    void addControl(const QPointF &c);
    void setControl(std::size_t num, const QPointF &c);
    void removeControl(std::size_t num);

    const QPointF &getControl(std::size_t num) const;
    const std::vector<QPointF>& getCurve() const;

    float getPrecision() const;
    void setPrecision(float value);

private:
    std::vector<QPointF> controls;
    std::vector<QPointF> curve;
    float precision;

    void update();
    QPointF tCurve(std::vector<QPointF> points, float t);
};

#endif // BEZIER_H
