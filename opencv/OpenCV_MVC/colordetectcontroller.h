#ifndef COLORDETECTCONTROLLER_H
#define COLORDETECTCONTROLLER_H

#include "colordector.h"

class ColorDetectController
{
public:
    ColorDetectController();
    ~ColorDetectController();

    // function
    void process() {
        if(fImage.data) {
            fResult = fColorDetector->process(fImage);
        }
    }

    // properties
    void setColorDistanceThreshold(int threshold) {
        fColorDetector->setThreshold(threshold);
    }

    int colorDistanceThreshold() const {
        return fColorDetector->threshold();
    }

    void setTargetColor(unsigned char red, unsigned char green, unsigned char blue) {
        fColorDetector->setTargetColor(red, green, blue);
    }

    void targetColor(unsigned char &red, unsigned char &green, unsigned char &blue) const {
        cv::Vec3b color = fColorDetector->targetColor();
        red   = color[2];
        green = color[1];
        blue  = color[0];
    }

    bool setInputImage(std::string filename);
    const cv::Mat inputImage() const {
        return fImage;
    }

    const cv::Mat getResult() const {
        return fResult;
    }

private:
    cv::Mat fImage;
    cv::Mat fResult;
    ColorDector *fColorDetector;
};

#endif // COLORDETECTCONTROLLER_H
