#include "colordector.h"

ColorDector::ColorDector()
    : fMinDist(100)
{
    fTarget[0]=fTarget[1]=fTarget[2] = 0;
}

cv::Mat ColorDector::process(cv::Mat& image)
{
   // Re-alloc binary image if necessary.
   fResult.create(image.rows, image.cols, CV_8U);

   cv::Mat_<cv::Vec3b>::const_iterator it    = image.begin<cv::Vec3b>();
   cv::Mat_<cv::Vec3b>::const_iterator itend = image.end<cv::Vec3b>();
   cv::Mat_<uchar>::iterator           itout = fResult.begin<uchar>();

   for (; it < itend; ++it, ++itout) {
       if(getDistance(*it) < fMinDist) {
           *itout = 255;
       } else {
           *itout = 0;
       }
   }

    return fResult;
}


int ColorDector::getDistance(cv::Vec3b color)
{
#if 0
    return abs(color[0]-fTarget[0]) +
           abs(color[1]-fTarget[1]) +
           abs(color[2]-fTarget[2]);
#endif
    return static_cast<int> (
               cv::norm<int, 3>(cv::Vec3i(color[0]-fTarget[0], color[1]-fTarget[1], color[2]-fTarget[2] ))
            );
}
