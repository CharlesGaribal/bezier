#include <QApplication>
#include <QGraphicsEllipseItem>
#include <QGraphicsScene>
#include <QGraphicsView>

#include "bezier.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QGraphicsScene scene;
    scene.setSceneRect(0, 0, 400, 400);

    Bezier bezier(Point2f(50,50), Point2f(150,350), 0.01f);
    bezier.addControl(Point2f(250,100));
    bezier.addControl(Point2f(350,200));

    for (int i = 0 ; i < 4 ; i++)
        scene.addRect(bezier.getControl(i).x - 5, bezier.getControl(i).y - 5, 10, 10);

    const std::vector<Point2f> &curve = bezier.getCurve();

    for(std::size_t i = 0 ; i < curve.size() - 1 ; i++)
        scene.addLine(curve[i].x, curve[i].y, curve[i+1].x, curve[i+1].y);

    QGraphicsView view(&scene);
    view.setRenderHints(QPainter::Antialiasing);
    view.show();

    return app.exec();
}
