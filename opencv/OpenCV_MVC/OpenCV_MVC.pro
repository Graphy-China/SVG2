#-------------------------------------------------
#
# Project created by QtCreator 2014-10-08T08:38:27
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = OpenCV_MVC
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    colordector.cpp \
    colordetectcontroller.cpp \
    imagermerge.cpp

HEADERS  += mainwindow.h \
    colordector.h \
    colordetectcontroller.h \
    imagermerge.h

FORMS    += mainwindow.ui \
    imagermerge.ui

INCLUDEPATH += /usr/local/include
LIBS += -L/usr/local/lib \
-lopencv_core \
-lopencv_highgui \
-lopencv_imgproc \
-lopencv_features2d \
-lopencv_calib3d

