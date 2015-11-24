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

#OPENCV_INST_DIR = /usr/local
OPENCV_DIR = C:/OpenCV/opencv/build

INCLUDEPATH += C:/OpenCV/opencv/build/include
LIBS += -LC:/OpenCV/opencv/build/x86/vc11/lib \
-lopencv_core249 \
-lopencv_highgui249 \
-lopencv_imgproc249 \
-lopencv_features2d249 \
-lopencv_calib3d249
