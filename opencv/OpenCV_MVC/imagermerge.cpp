#include "imagermerge.h"
#include "ui_imagermerge.h"
#include <QFileDialog>

#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

ImagerMerge::ImagerMerge(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ImagerMerge)
{
    ui->setupUi(this);

}

ImagerMerge::~ImagerMerge()
{
    delete ui;
}

void ImagerMerge::on_openTarget_clicked()
{
      QString filename = QFileDialog::getOpenFileName(this,tr("Open Image"), ".",tr("Image Files (*.png *.jpg *.jpeg *.bmp)"));
      target = cv::imread(filename.toStdString());
      if(target.data) {
          updateCanvas(ui->targetImage, target);
      }
}

void ImagerMerge::on_openSrc_clicked()
{
    QString filename = QFileDialog::getOpenFileName(this,tr("Open Image"), ".",tr("Image Files (*.png *.jpg *.jpeg *.bmp)"));
    src = cv::imread(filename.toStdString());
    if(src.data) {
        updateCanvas(ui->srcImage, src);
    }
}

void ImagerMerge::on_processBtn_clicked()
{
    int margin = 50;
    int width  = src.cols;
    int height = src.rows;
    int x = target.cols - width  - margin;
    int y = margin;
    x = 385;
    y = 270;

    cv::Mat imageROI = target(cv::Rect(x,y, width, height));

#if 0
    cv::addWeighted(imageROI,1.0, src, 0.3, 0.0, imageROI);
#else
    cv::Mat mask;
    mask.create(src.rows, src.cols, CV_8U);
    cv::cvtColor(src, mask, CV_BGR2GRAY);
    double threshold = 0.5;
    cv::threshold(mask, mask, threshold, 255, CV_THRESH_BINARY);

    src.copyTo(imageROI, mask);
#endif
    updateCanvas(ui->targetImage, target);

}

void ImagerMerge::on_exitBtn_clicked()
{

}


void ImagerMerge::updateCanvas(QLabel* canvas, cv::Mat& image)
{
    if(image.data) {
        cv::Mat rgbresult;
        cv::cvtColor(image, rgbresult, CV_BGR2RGB);
        QImage img= QImage((const unsigned char*)(rgbresult.data),rgbresult.cols,rgbresult.rows,QImage::Format_RGB888);
        canvas->setPixmap(QPixmap::fromImage(img));
        canvas->resize(canvas->pixmap()->size());
    }
}
