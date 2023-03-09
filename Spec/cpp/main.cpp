#include "common.hpp"
#include "FileOps.hpp"
#include "ImageProcessing.hpp"
using namespace cv;
using namespace std;



int main (int argc,char * argv[])
{


  if (argc < 2){
    cout << "Error!"<<endl; 

    return 0;
  }

  cout <<argv[1] << " " << argv[2] <<endl;

  
  Point2f Boundry;
  Point2f NewBoundry;
  Boundry = LoadBoundry("/home/marko/Desktop/Projekat/Projekat-Image-Rotation/Data/Dimenzije.txt");
  cout << Boundry.x << "."<< Boundry.y<< endl;
  ImageMatrix2D image,image2;
 
  image = LoadImageMakeMatrix("/home/marko/Desktop/Projekat/Projekat-Image-Rotation/Data/SlikaPixel.txt",Boundry.x,Boundry.y);
  cout <<image[1][1].red <<endl;
  NewBoundry = FindNewBorder(Boundry,stod(argv[2]));
  cout <<"New boudnry:" << NewBoundry.x << NewBoundry.y; 

  image2=GetRotatedImage(NewBoundry,Boundry,image,stod(argv[2]),argv[1]);
  cout << image2[500][500].red<<" "<< image2[500][500].green<<" " <<image2[500][500].blue<<endl;
  StoreImageToFile("/home/marko/Desktop/Projekat/Projekat-Image-Rotation/Data/Output.txt",image2,NewBoundry.x,NewBoundry.y);
  
  
  
  
  

  return 0;
  
} 
