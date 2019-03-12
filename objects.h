#ifndef OBJECTS_H
#define OBJECTS_H

#include <QOpenGLWidget>
#include <QOpenGLFunctions>
#include <vector>
#include <QMouseEvent>
#include <RayTracer/CommonFunc.h>
#include "RayTracer/QuadraticCreator.h"

class Objects : public QOpenGLWidget, protected QOpenGLFunctions
{
    Q_OBJECT
public:
    Objects(QWidget *parent = 0);
    QSize minimumSizeHint() const override;
    QSize sizeHint() const override;
    void setParameters(int _index, const std::vector<double>& param);
    void clearParameters();

protected:
    void initializeGL() override;
    void paintGL() override;
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void wheelEvent(QWheelEvent *event) override;

private:
    QuadraticCreator *creator;
    Surface *sf;
    int index;

    float m_zoom;
    QPoint m_lastPos;
};

#endif // OBJECTS_H
