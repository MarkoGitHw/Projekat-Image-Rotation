
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp> 
#include <opencv2/imgproc.hpp> 
#include <iostream>
#include <vector>
#include <fstream>
using namespace cv;
using namespace std;

struct pixel{
 int blue;
 int green;
 int red;
 
};
typedef vector < vector < pixel > > ImageMatrix2D;
typedef vector <pixel> ImageMatrix1D;
		       
Point2i LoadBoundry(string path)
{
 
  Point2i Boundry;
  ifstream myBoundry;
  myBoundry.open(path);
  myBoundry>>Boundry.x>>Boundry.y;

  return Boundry;
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

ImageMatrix2D LoadImageMakeMatrix(string path,int rows, int cols){
  ImageMatrix2D Image2D;
  ImageMatrix1D PixelArray;
  pixel tmp;
  ifstream myimage;
  myimage.open(path);
  
  for ( int i = 0 ; i < rows; i++){
    Image2D.push_back(PixelArray);
    
    
    for (int j = 0 ; j < cols; j++){
      myimage >> tmp.blue >>tmp.green >>tmp.red;
      Image2D[i].push_back(tmp);
    }
  }

  myimage.close();
  return Image2D;
  
}


void StoreImageToFile(string path,ImageMatrix2D image,int x,int y){
  int k = 0;

    
  ofstream outfile;
  outfile.open(path);
  if (k == 0){
    outfile << x << " " << y << endl;
    k=1;
  }
  if (k == 1){
    cout << "0k1" <<endl;
    for (int i = 0; i < image.size(); i++)
      for(int j = 0; j < image[0].size(); j++)
	outfile << image[i][j].blue << " " << image[i][j].green <<" "<<image[i][j].red <<endl;
  }


  cout << "Finished 2" <<endl;
  outfile.close();
  
  
}
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

int main ()
{
  Point2f Boundry;
  Point2f NewBoundry;
  Boundry = LoadBoundry("DimenzijeMacka.txt");
  cout << Boundry.x << "."<< Boundry.y<< endl;
  ImageMatrix2D image,image2;
 
  image = LoadImageMakeMatrix("mackica.txt",Boundry.x,Boundry.y);
  cout <<image[1][1].red <<endl;
  NewBoundry = FindNewBorder(Boundry,0);
  cout <<"New boudnry:" << NewBoundry.x << NewBoundry.y; 

  image2=GetRotatedImage(NewBoundry,Boundry,image,0);
  cout << image2[500][500].red<<" "<< image2[500][500].green<<" " <<image2[500][500].blue<<endl;
  StoreImageToFile("output1.txt",image2,NewBoundry.x,NewBoundry.y);
  
  
  
  
  

  return 0;
  
} 
