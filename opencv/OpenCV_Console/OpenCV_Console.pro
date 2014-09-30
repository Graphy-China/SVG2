#-------------------------------------------------
#
# Project created by QtCreator 2014-09-30T09:22:56
#
#-------------------------------------------------

QT       += core

QT       -= gui

TARGET = OpenCV_Console
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp

INCLUDEPATH += /usr/local/include
LIBS += -L/usr/local/lib \
-lopencv_core \
-lopencv_highgui \
-lopencv_imgproc \
-lopencv_features2d \
-lopencv_calib3d

