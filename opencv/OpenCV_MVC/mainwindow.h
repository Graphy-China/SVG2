#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "colordetectcontroller.h"

class ImagerMerge;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_openImage_clicked();

    void on_selectColor_clicked();

    void on_process_clicked();

    void on_thresholdSlider_valueChanged(int value);

    void on_mergeBtn_clicked();

private:
    void updateCanvas();
    Ui::MainWindow *ui;
    ColorDetectController colordetector;

    ImagerMerge *fMerger;
};

#endif // MAINWINDOW_H
