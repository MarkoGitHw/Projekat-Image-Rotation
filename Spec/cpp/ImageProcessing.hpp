#ifndef IMAGEPROCESSING_H
#define IMAGEPROCESSING_H

#include  "common.hpp"
ImageMatrix2D GetRotatedImage (cv::Point2i NewBoundry,cv::Point2i OldBoundry,ImageMatrix2D Oldimage,double angle,char * direction);
cv::Point2i FindNewBorder (cv::Point2f CurrentBoundry,float angle);



#endif
