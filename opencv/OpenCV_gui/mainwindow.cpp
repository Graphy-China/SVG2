#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>

#include <opencv2/imgproc/imgproc.hpp>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->FlipX->setEnabled(false);
    ui->FlipY->setEnabled(false);
    ui->FlipXY->setEnabled(false);
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
        ui->FlipX->setEnabled(true);
        ui->FlipY->setEnabled(true);
        ui->FlipXY->setEnabled(true);
        // not work
        ui->FlipX->setChecked(false);
        ui->FlipY->setChecked(false);
        ui->FlipXY->setChecked(false);
    }

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

void MainWindow::on_SaltBtn_clicked()
{
    if( !image.data)
        return;
    processSalt(3000);
}

void MainWindow::on_ReduceBtn_clicked()
{
    if(!image.data)
        return;

    processReduceColor(64);
    updateCanvas();
}


void MainWindow::process(IMG_FLIP method)
{
    if(!image.data)
        return;
    cv::flip(image, image, method);
    updateCanvas();
}

void MainWindow::processSalt(int n)
{
    for (int k=0; k<n; ++k) {
        int x = rand()%image.cols;
        int y = rand()%image.rows;
        if(image.channels() == 1) {
            image.at<uchar>(y,x) = 255;
        } else if(image.channels() == 3) {
            cv::Vec3b& rgb = image.at<cv::Vec3b>(y,x);
            rgb[0]=255; rgb[1]=255; rgb[2]=255;
        }
    }

    updateCanvas();
}

void MainWindow::processReduceColor(int div)
{
    int nl = image.rows;
    int nc = image.cols*image.channels();

    for (int y=0; y<nl; ++y) {
        uchar* row = image.ptr<uchar>(y);
        for(int x=0; x<nc; ++x) {
            row[x] = row[x]/div*div + div/2;
        }
    }

    updateCanvas();
}


void MainWindow::updateCanvas()
{
    // 1. opencv's pixel: BGR.
    // 2.cvtColor is declared in imgproc/imgproc.hpp.
    assert(image.data);
    cv::Mat result;
    cv::cvtColor(image, result, CV_BGR2RGB);
    QImage img= QImage((const unsigned char*)(result.data),result.cols,result.rows,QImage::Format_RGB888);
    ui->ImageCanvas->setPixmap(QPixmap::fromImage(img));
    ui->ImageCanvas->resize(ui->ImageCanvas->pixmap()->size());
}


