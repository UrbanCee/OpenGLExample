#ifndef MYGLWIDGET_H
#define MYGLWIDGET_H

#include <QOpenGLWidget>
#include <QOpenGLFunctions_4_0_Core>
#include <QOpenGLShaderProgram>

#include "renderobjects.h"


#define BUFFER_OFFSET(i) ((char *)NULL + (i))


class MyGLWidget : public QOpenGLWidget, QOpenGLFunctions_4_0_Core
{
    Q_OBJECT

public:
    MyGLWidget(QWidget *parent);

signals:
    showStatusBarMessage(QString,int);

protected:
    void initializeGL();
    void paintGL();
    void resizeGL(int w, int h);

    void mousePressEvent(QMouseEvent *);
    void mouseReleaseEvent(QMouseEvent *);
    void mouseMoveEvent(QMouseEvent *);
    void wheelEvent(QWheelEvent *);
    void keyPressEvent(QKeyEvent *);


private:
    QMatrix4x4 projection, transformation, currRot, transRotOnly;
    QVector2D rotStartPos;
    bool bRotate;
    float zoomFactor;
    int oldMouseX,oldMouseY;


    QTimer *timer;


    CCuboid cuboid;
    CCoordSys coordSys;
    CPlane plane;
    CToroid toroid;



private:
    void startRotation(int, int);
    void stopRotation();
    void updateProjectionMatrix(int w, int h);
};

#endif // MYGLWIDGET_H
