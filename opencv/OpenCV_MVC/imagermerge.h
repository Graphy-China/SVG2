#ifndef IMAGERMERGE_H
#define IMAGERMERGE_H

#include <QDialog>

#include <opencv2/core/core.hpp>

namespace Ui {
class ImagerMerge;
}
class QLabel;
class ImagerMerge : public QDialog
{
    Q_OBJECT

public:
    explicit ImagerMerge(QWidget *parent = 0);
    ~ImagerMerge();

private slots:
    void on_openTarget_clicked();

    void on_openSrc_clicked();

    void on_processBtn_clicked();

    void on_exitBtn_clicked();

private:
    void updateCanvas(QLabel* canvas, cv::Mat& image);

    Ui::ImagerMerge *ui;

    cv::Mat target;
    cv::Mat src;
};

#endif // IMAGERMERGE_H
