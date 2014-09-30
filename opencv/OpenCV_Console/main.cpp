#include <QCoreApplication>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>


int main(int argc, char *argv[])
{
    cv::Mat image = cv::imread("x.png");
    if (image.data) {
        cv::namedWindow("My Image");
        cv::imshow("My Image", image);

        cv::Mat result;
        const int FLIP_X   =  1;
        const int FLIP_Y   =  0;
        const int FLIP_XY  = -1;

        cv::flip(image, result, FLIP_XY);
        cv::namedWindow("Result Image");
        cv::imshow("Result Image", result);

        cv::waitKey(0);
        cv::imwrite("y.jpg", result);
    }

    return 1;
}
