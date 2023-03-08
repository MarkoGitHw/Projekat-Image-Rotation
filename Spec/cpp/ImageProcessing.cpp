#include "ImageProcessing.hpp"

using namespace cv;
using namespace std;

ImageMatrix2D GetRotatedImage(Point2i NewBoundry,Point2i OldBoundry,ImageMatrix2D OldImage,double angle){
  float rads = (angle * 3.14159265359 ) / 180 ;
  ImageMatrix2D RotatedImage;
  ImageMatrix1D PixelArray;
  pixel ZeroPixel;
  
  int OldHeight = OldBoundry.x;
  int OldWidth = OldBoundry.y;
  cout << OldHeight << " " << OldWidth <<endl;
  
  int cy = OldWidth / 2;
  int cx = OldHeight / 2;
  cout << cx << cy;
  
  int NewHeight = NewBoundry.x;
  int NewWidth  = NewBoundry.y;
  cout << NewHeight <<" "<<NewWidth <<endl;
  int midx = NewHeight/2 ;
  int midy = NewWidth/2 ;
  RotatedImage.resize(NewHeight,vector<pixel>(NewWidth));
  
  for (int row = 0; row < NewHeight ; row++){

    for (int col= 0; col < NewWidth ; col++){
      //cout <<"New:"<<row<< "." << col <<endl;//
      
      int x  = (int)((row-midx ) * cos(rads) - (col-midy) * sin(rads) +cx);
      int y  = (int)((col-midy ) * cos(rads) + (row-midx) * sin(rads) +cy);
      //    cout << "Old:"<< OldRow <<"."<< OldCol << endl;//
      if (x >= 0 && x< OldHeight && y >= 0 && y< OldWidth)
	{
	  RotatedImage[row][col]=(OldImage[x][y]);
	  
	}
      //  cout << RotatedImage[row][col].red <<" "<< RotatedImage[row][col].green <<" "<<RotatedImage[col][row].blue << " at "<<col<< " "<< row << endl;
      
      
    }
    
    
  }
  
  cout << "Finished" << endl;
  
  return RotatedImage;
  
  

  
}
Point2i FindNewBorder(Point2f CurrentBoundry,float angle){

  Point2i NewBoundry;
  float rads = (angle * 3.14159265359 ) / 180 ;
  if(angle < 90) {
    NewBoundry.x =(int)( CurrentBoundry.x * cos(rads) + CurrentBoundry.y * sin(rads));
    NewBoundry.y =(int)( CurrentBoundry.x * sin(rads) + CurrentBoundry.y * cos(rads));
  }
  else{
    float x = CurrentBoundry.y;
    float y = CurrentBoundry.x;
    float rotangle = angle - 90;
    float rotanglerads =(rotangle*3.14159265359)/180;
    NewBoundry.x =(int)( x * cos(rotanglerads) + y * sin(rotanglerads));
    NewBoundry.y =(int)( x * sin(rotanglerads) + y * cos(rotanglerads));


  }
  return NewBoundry;
}
