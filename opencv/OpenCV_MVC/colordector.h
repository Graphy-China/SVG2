#ifndef COLORDECTOR_H
#define COLORDECTOR_H

#include <opencv2/core/core.hpp>

class ColorDector
{
public:
    ColorDector();

    // function
    cv::Mat process(cv::Mat& image);

    // properties.
    void setThreshold(int distance ) {
        if(distance < 0)
            distance = 0;
        fMinDist = distance;
    }

    int threshold() const {
        return fMinDist;
    }

    void setTargetColor(cv::Vec3b color) {
        fTarget = color;
    }

    void setTargetColor(unsigned char red, unsigned char green, unsigned char blue) {
        fTarget[2] = red;
        fTarget[1] = green;
        fTarget[0] = blue;
    }

    cv::Vec3b targetColor() const {
        return fTarget;
    }

    cv::Mat result() const {
        return fResult;
    }

private:

    int getDistance(cv::Vec3b color);

    int fMinDist;
    cv::Vec3b fTarget; // BGR
    cv::Mat fResult;


};

#endif // COLORDECTOR_H
