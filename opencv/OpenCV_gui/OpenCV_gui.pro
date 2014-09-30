#-------------------------------------------------
#
# Project created by QtCreator 2014-09-30T09:40:48
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = OpenCV_gui
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h

FORMS    += mainwindow.ui

INCLUDEPATH += /usr/local/include
LIBS += -L/usr/local/lib \
-lopencv_core \
-lopencv_highgui \
-lopencv_imgproc \
-lopencv_features2d \
-lopencv_calib3d
