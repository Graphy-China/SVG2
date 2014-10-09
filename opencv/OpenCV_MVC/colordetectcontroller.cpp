#include "colordetectcontroller.h"

#include <opencv2/highgui/highgui.hpp>
ColorDetectController::ColorDetectController()
{
    fColorDetector = new ColorDector();
}

ColorDetectController::~ColorDetectController()
{
    delete fColorDetector;
}

bool ColorDetectController::setInputImage(std::string filename)
{
    fImage = cv::imread(filename);
    return fImage.data? true: false;
}
