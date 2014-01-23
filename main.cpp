#include <QApplication>
#include <QGraphicsEllipseItem>
#include <QGraphicsScene>
#include <QGraphicsView>


#include "bezier.h"
#include "controlitem.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QGraphicsScene scene;
    scene.setSceneRect(0, 0, 400, 400);

    Bezier bezier(QPointF(50,50), QPointF(150,350), 0.01f);
    bezier.addControl(QPointF(250,100));
    bezier.addControl(QPointF(350,200));

    for (int i = 0 ; i < 4 ; i++) {
        ControlItem *ci = new ControlItem();
        ci->setPos(bezier.getControl(i));
        scene.addItem(ci);
    }


    const std::vector<QPointF> &curve = bezier.getCurve();

    for(std::size_t i = 0 ; i < curve.size() - 1 ; i++)
        scene.addLine(curve[i].x(), curve[i].y(), curve[i+1].x(), curve[i+1].y());

    QGraphicsView view(&scene);
    view.setRenderHints(QPainter::Antialiasing);
    view.show();

    return app.exec();
}
