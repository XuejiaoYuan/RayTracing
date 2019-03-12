QT += core
QT += gui
QT += opengl

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

TARGET = RayTracer
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    tabwidget.cpp \
    window.cpp \
    RayTracer/Ellipsoid.cpp \
    RayTracer/Paraboloid.cpp \
    RayTracer/Quadratic.cpp \
    RayTracer/Saddle.cpp \
    RayTracer/Surface.cpp \
    TabWidget/cylindertab.cpp \
    TabWidget/ellipsoidtab.cpp \
    TabWidget/paraboloidtab.cpp \
    TabWidget/quadratictab.cpp \
    TabWidget/saddletab.cpp \
    objects.cpp \
    RayTracer/Cylinder.cpp

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

HEADERS += \
    tabwidget.h \
    window.h \
    RayTracer/CommonFunc.h \
    RayTracer/Cylinder.h \
    RayTracer/Ellipsoid.h \
    RayTracer/Paraboloid.h \
    RayTracer/Quadratic.h \
    RayTracer/QuadraticCreator.h \
    RayTracer/Saddle.h \
    RayTracer/Surface.h \
    TabWidget/cylindertab.h \
    TabWidget/ellipsoidtab.h \
    TabWidget/paraboloidtab.h \
    TabWidget/quadratictab.h \
    TabWidget/saddletab.h \
    objects.h
