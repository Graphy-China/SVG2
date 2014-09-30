#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

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
    void on_OpenImageBtn_clicked();
    void on_FlipX_clicked();

    void on_FlipY_clicked();

    void on_FlipXY_clicked();

    void on_SaltBtn_clicked();

private:
    typedef enum {
        IMG_FLIPX = 1,
        IMG_FLIPY = 0,
        IMG_FLIPXY= -1
    } IMG_FLIP;

    void process(IMG_FLIP method);
    void processSalt(int n);
    void updateCanvas();

private:
    Ui::MainWindow *ui;

    cv::Mat image;
};

#endif // MAINWINDOW_H
