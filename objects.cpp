#include "objects.h"

Objects::Objects(QWidget *parent) :QOpenGLWidget(parent)
{
    creator = new QuadraticCreator();
    index = -1;
    sf = NULL;
}

void Objects::setParameters(int _index, const std::vector<double> &param)
{
    index = _index;
    sf = creator->Create(index);
    sf->SetParameters(param);
    if(index == 4)
        sf->setIndex(index + param[0]);
    else
        sf->setIndex(index);
}

QSize Objects::minimumSizeHint() const
{
    return QSize(WINWIDTH, WINHEIGHT);
}

QSize Objects::sizeHint() const
{
    return QSize(WINWIDTH, WINHEIGHT);
}

void Objects::initializeGL()
{

    initializeOpenGLFunctions();

    glClearColor(0, 0, 0, 0);

}

void Objects::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

    if(sf == NULL){
        GLfloat* data = new GLfloat[3 * WINWIDTH*WINHEIGHT];
        glDrawPixels(WINWIDTH, WINHEIGHT, GL_RGB, GL_FLOAT, data);
    }
    else
        glDrawPixels(WINWIDTH, WINHEIGHT, GL_RGB, GL_FLOAT, sf->RayTracing());

}

void Objects::clearParameters()
{
    index = -1;
    delete sf;
    sf = NULL;
}

void Objects::mousePressEvent(QMouseEvent *event)
{
    m_lastPos = event->pos();
}

void Objects::mouseMoveEvent(QMouseEvent *event)
{
    double dx = event->x() - m_lastPos.x();
    double dy = event->y() - m_lastPos.y();

    if(event->buttons() && Qt::LeftButton){
        sf->RotationZ(dx / 100.0);
        sf->RotationY(-dy / 100.0);
    }

    m_lastPos = event->pos();

    update();
}

void Objects::wheelEvent(QWheelEvent *event)
{
    if(event->delta() > 0)
        sf->Scale(20);
    else
        sf->Scale(-20);
    update();
}
