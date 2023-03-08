#include "common.hpp"
#include "FileOps.hpp"
#include "ImageProcessing.hpp"
using namespace cv;
using namespace std;



int main ()
{
  Point2f Boundry;
  Point2f NewBoundry;
  Boundry = LoadBoundry("/home/marko/Desktop/Projekat/Projekat-Image-Rotation/Data/Dimenzije.txt");
  cout << Boundry.x << "."<< Boundry.y<< endl;
  ImageMatrix2D image,image2;
 
  image = LoadImageMakeMatrix("/home/marko/Desktop/Projekat/Projekat-Image-Rotation/Data/SlikaPixel.txt",Boundry.x,Boundry.y);
  cout <<image[1][1].red <<endl;
  NewBoundry = FindNewBorder(Boundry,30);
  cout <<"New boudnry:" << NewBoundry.x << NewBoundry.y; 

  image2=GetRotatedImage(NewBoundry,Boundry,image,30);
  cout << image2[500][500].red<<" "<< image2[500][500].green<<" " <<image2[500][500].blue<<endl;
  StoreImageToFile("/home/marko/Desktop/Projekat/Projekat-Image-Rotation/Data/Output.txt",image2,NewBoundry.x,NewBoundry.y);
  
  
  
  
  

  return 0;
  
} 
