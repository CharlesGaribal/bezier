bezier
======

Bezier curves implementation with Qt (c++)

I use wikipedia algorithm (http://en.wikipedia.org/wiki/Bezier_curve#Generalization) to create n-curves.
Now I want to implement a more complex GUI to see how bezier curves work.

An example to see how add a GraphicsBezierItem to a QGraphicsScene :

    QGraphicsScene scene;
    scene.setSceneRect(0, 0, 400, 400);
    
    GraphicsBezierItem *gbi = new GraphicsBezierItem(QPointF(50,50), QPointF(350,50));
    gbi->addControl(QPointF(200,200));
    scene.addItem(gbi);


