#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QColorDialog>


#include <opencv2/imgproc/imgproc.hpp>
#include "imagermerge.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->thresholdSlider->setRange(0, 255);
    ui->thresholdSlider->setValue(colordetector.colorDistanceThreshold());
    ui->process->setEnabled(false);
    fMerger = 0;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_openImage_clicked()
{
    QString filename = QFileDialog::getOpenFileName(this,tr("Open Image"), ".",tr("Image Files (*.png *.jpg *.jpeg *.bmp)"));
    if( colordetector.setInputImage(filename.toStdString()) ) {
        // do something.
        ui->process->setDisabled(false);
    } else {
        ui->process->setDisabled(true);
    }
}

void MainWindow::on_selectColor_clicked()
{
    QColor clr = QColorDialog::getColor();
    if(clr.isValid()) {
        colordetector.setTargetColor(clr.red(), clr.green(), clr.blue());
        on_process_clicked();
    }
}

void MainWindow::on_process_clicked()
{
    colordetector.process();
    updateCanvas();
}

void MainWindow::on_thresholdSlider_valueChanged(int value)
{
    colordetector.setColorDistanceThreshold(value);

    QString a;
    a.sprintf("%d", colordetector.colorDistanceThreshold());
    ui->threshold->setText(a);
    on_process_clicked();
}

void MainWindow::updateCanvas()
{
    // 1. opencv's pixel: BGR.
    // 2.cvtColor is declared in imgproc/imgproc.hpp.fMerger
    const cv::Mat binaryResult = colordetector.getResult();
    if(binaryResult.data) {
        cv::Mat rgbresult;
        cv::cvtColor(binaryResult, rgbresult, CV_GRAY2RGB);
        QImage img= QImage((const unsigned char*)(rgbresult.data),rgbresult.cols,rgbresult.rows,QImage::Format_RGB888);
        ui->resultImage->setPixmap(QPixmap::fromImage(img));
        ui->resultImage->resize(ui->resultImage->pixmap()->size());
    }
}

void MainWindow::on_mergeBtn_clicked()
{
    ImagerMerge mergerDialog(this);
    mergerDialog.exec();
}
