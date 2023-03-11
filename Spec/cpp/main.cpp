#include "common.hpp"
#include "FileOps.hpp"
#include "ImageProcessing.hpp"
#include <valgrind/callgrind.h>
using namespace cv;
using namespace std;



int main (int argc,char * argv[])
{


  if (argc < 2){
    cout << "Error!"<<endl; 

    return 0;
  }

  
  Point2f Boundry;

  Point2f NewBoundry;
 
  Boundry = LoadBoundry("/home/marko/Desktop/Projekat/Projekat-Image-Rotation/Data/Dimenzije.txt");
  
  ImageMatrix2D image,image2;

  
  image = LoadImageMakeMatrix("/home/marko/Desktop/Projekat/Projekat-Image-Rotation/Data/SlikaPixel.txt",Boundry.x,Boundry.y);


 
  
  CALLGRIND_START_INSTRUMENTATION;
  CALLGRIND_TOGGLE_COLLECT;
  NewBoundry = FindNewBorder(Boundry,stod(argv[2]));

  image2=GetRotatedImage(NewBoundry,Boundry,image,stod(argv[2]),argv[1]);

  CALLGRIND_TOGGLE_COLLECT;
  CALLGRIND_STOP_INSTRUMENTATION;
  StoreImageToFile("/home/marko/Desktop/Projekat/Projekat-Image-Rotation/Data/Output.txt",image2,NewBoundry.x,NewBoundry.y);
  
  
  
  
  

  return 0;
  
} 
