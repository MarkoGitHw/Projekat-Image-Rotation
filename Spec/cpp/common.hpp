#ifndef COMMON_H
#define COMMON_H
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp> 
#include <opencv2/imgproc.hpp> 
#include <iostream>
#include <vector>
#include <fstream>

struct pixel{
 int blue;
 int green;
 int red;
 
};

typedef vector < vector < pixel > > ImageMatrix2D;
typedef vector <pixel> ImageMatrix1D;


#endif 
