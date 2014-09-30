#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>

#include <opencv2/imgproc/imgproc.hpp>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->FlipX->setCheckable(false);
    ui->FlipY->setCheckable(false);
    ui->FlipXY->setCheckable(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_OpenImageBtn_clicked()
{
    QString filename = QFileDialog::getOpenFileName(this,tr("Open Image"), ".",tr("Image Files (*.png *.jpg *.jpeg *.bmp)"));
    cv::Mat img = cv::imread(filename.toStdString());
    if(img.data) {
        image = img;
        updateCanvas();
        ui->FlipX->setCheckable(true);
        ui->FlipY->setCheckable(true);
        ui->FlipXY->setCheckable(true);
    }

}

void MainWindow::process(IMG_FLIP method)
{
    if(!image.data)
        return;
    cv::flip(image, image, method);
    updateCanvas();
}

void MainWindow::updateCanvas()
{
    // 1. opencv's pixel: BGR.
    // 2.cvtColor is declared in imgproc/imgproc.hpp.
    assert(image.data);
    cv::cvtColor(image, image, CV_BGR2RGB);
    QImage img= QImage((const unsigned char*)(image.data),image.cols,image.rows,QImage::Format_RGB888);
    ui->ImageCanvas->setPixmap(QPixmap::fromImage(img));
    ui->ImageCanvas->resize(ui->ImageCanvas->pixmap()->size());
}

void MainWindow::on_FlipX_clicked()
{
    process(IMG_FLIPX);
}

void MainWindow::on_FlipY_clicked()
{
    process(IMG_FLIPY);
}

void MainWindow::on_FlipXY_clicked()
{
    process(IMG_FLIPXY);
}
