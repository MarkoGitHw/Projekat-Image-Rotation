#ifndef COMMON_H
#define COMMON_H
#define SC_INCLUDE_FX
#include <systemc>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp> 
#include <opencv2/imgproc.hpp>
#include <iostream>
#include <vector>
#include <fstream>


struct pixel
{
  int blue;
  int green;
  int red;
 
};
typedef sc_dt::sc_ufix_fast angle_sc;
typedef sc_dt::sc_fix_fast sin_result_sc;
typedef std::vector <std::vector < pixel > > ImageMatrix2D;
typedef std::vector <pixel> ImageMatrix1D;


#endif 
