#include "ImageProcessing.hpp"

using namespace cv;
using namespace std;

ImageMatrix2D SCGetRotatedImage (point_rotated NewBoundry,point_unrotated OldBoundry,ImageMatrix2D OldImage,sc_angle angle,char * direction){
  ImageMatrix2D RotatedImage;
  ImageMatrix1D PixelArray;
  
  //lookup_vector lookup_tabela = { 0.000000, 0.017452, 0.034899, 0.052336, 0.069756, 0.087156, 0.104528, 0.121869, 0.139173, 0.156434, 0.173648, 0.190809, 0.207912, 0.224951, 0.241922, 0.258819, 0.275637, 0.292372, 0.309017, 0.325568, 0.342020, 0.358368, 0.374607, 0.390731, 0.406737, 0.422618, 0.438371, 0.453991, 0.469472, 0.484810, 0.500000, 0.515038, 0.529919, 0.544639, 0.559193, 0.573576, 0.587785, 0.601815, 0.615661, 0.629320, 0.642788, 0.656059, 0.669131, 0.681998, 0.694658, 0.707107, 0.719340, 0.731354, 0.743145, 0.754710, 0.766044, 0.777146, 0.788011, 0.798636, 0.809017, 0.819152, 0.829038, 0.838671, 0.848048, 0.857167, 0.866025, 0.874620, 0.882948, 0.891007, 0.898794, 0.906308, 0.913545, 0.920505, 0.927184, 0.933580, 0.939693, 0.945519, 0.951057, 0.956305, 0.961262, 0.965926, 0.970296, 0.974370, 0.978148, 0.981627, 0.984808, 0.987688, 0.990268, 0.992546, 0.994522, 0.996195, 0.997564, 0.998630, 0.999391, 0.999848 ,1 , 0.99985, 0.99939, 0.99863, 0.99756, 0.99619, 0.99452, 0.99255, 0.99027, 0.98769, 0.98481, 0.98163, 0.97815, 0.97437, 0.9703, 0.96593, 0.96126, 0.9563, 0.95106, 0.94552, 0.93969, 0.93358, 0.92718, 0.9205, 0.91355, 0.90631, 0.89879, 0.89101, 0.88295, 0.87462, 0.86603, 0.85717, 0.84805, 0.83867, 0.82904, 0.81915, 0.80902, 0.79864, 0.78801, 0.77715, 0.76604, 0.75471, 0.74314, 0.73135, 0.71934, 0.70711, 0.69466, 0.68199, 0.66913, 0.65606, 0.64279, 0.62932, 0.61566, 0.60182, 0.58779, 0.57358, 0.55919, 0.54464, 0.52992, 0.51504, 0.5, 0.48481, 0.46947, 0.45399, 0.43837, 0.42262, 0.40674, 0.39073, 0.37461, 0.35837, 0.34202, 0.32557, 0.30902, 0.29237, 0.27564, 0.25882, 0.24192, 0.22495, 0.20791, 0.19081, 0.17365, 0.15643, 0.13917, 0.12187, 0.10453, 0.08716, 0.06976, 0.05234, 0.0349, 0.01745, 0, -0.01745, -0.03490, -0.05234, -0.06976, -0.08716, -0.10453, -0.12187, -0.13917, -0.15643, -0.17365, -0.19081, -0.20791, -0.22495, -0.24192, -0.25882, -0.27564, -0.29237, -0.30902, -0.32557, -0.34202, -0.35837, -0.37461, -0.39073, -0.40674, -0.42262, -0.43837, -0.45399, -0.46947, -0.48481, -0.5, -0.51504, -0.52992, -0.54464, -0.55919, -0.57358, -0.58779, -0.60182, -0.61566, -0.62932, -0.64279, -0.65606, -0.66913, -0.68199, -0.69466, -0.70711, -0.71934, -0.73135, -0.74314, -0.75471, -0.76604, -0.77715, -0.78801, -0.79864, -0.80902, -0.81915, -0.82904, -0.83867, -0.84805, -0.85717, -0.86603, -0.87462, -0.88295, -0.89101, -0.89879, -0.90631, -0.91355, -0.92050, -0.92718, -0.93358, -0.93969, -0.94552, -0.95106, -0.95630, -0.96126, -0.96593, -0.97030, -0.97437, -0.97815, -0.98163, -0.98481, -0.98769, -0.99027, -0.99255, -0.99452, -0.99619, -0.99756, -0.99863, -0.99939, -0.99985, -1,};
  rotated_size x,y;
  unrotated_size OldHeight = OldBoundry.x;
  unrotated_size OldWidth = OldBoundry.y;
  cout << "Stara granica: " << OldHeight << "."<<OldWidth <<endl;
  //sin_result_sc lookup_table[1024];
  //LookupGenerateBitAnalysis(lookup_table,1024);
  
  
  sin_result_sc  sinc;
  sinc= sin(radian(angle));
  sin_result_sc  cosc;
  cosc =cos(radian(angle));
  cout << "SINUS:" << sinc <<endl;
  cout << "COsinus: " << cosc <<endl;
  
  unrotated_padding cy = (OldWidth)/ 2;
  unrotated_padding  cx = (OldHeight)/ 2;
  string smer = direction;
  rotated_size NewHeight = NewBoundry.x;
  rotated_size NewWidth  = NewBoundry.y;
  cout << "Nova granica: " << NewHeight << "."<<NewWidth <<endl;
  rotated_padding  midx = NewHeight/2 ;
  rotated_padding  midy = NewWidth/2 ;
  RotatedImage.resize(NewHeight,vector<pixel>(NewWidth));
  
  for (rotated_size row = 0; row < NewHeight ; row++){

    for (rotated_size col= 0; col < NewWidth ; col++){
   
      if (smer == "right"){
      x  = ((row-midx ) * cosc - (col-midy) * sinc +cx);
      y  = ((col-midy ) * cosc + (row-midx) * sinc +cy);
      
      
      }

      if (smer == "left"){

       x  = ((row-midx ) * cosc + (col-midy) * sinc +cx);
       y  = ((col-midy ) * cosc - (row-midx) * sinc +cy);

       
      }
      if (x >= 0 && x< OldHeight && y >= 0 && y< OldWidth)
	{
	  RotatedImage[row][col]=(OldImage[x][y]);
	  
	}
      
      
    }
    
    
  }
  
  cout << "Finished" << endl;
  
  return RotatedImage;
  
  

  
}
Point2i FindNewBorder(Point2i CurrentBoundry,double angle){

  Point2i NewBoundry;
  double  sinc = 0;
  double  cosc = 0;
  double  rad  = 0;
  if(angle < 90) {
    rad=radian(angle);
    sinc = sin(rad);
    cosc = sin(radian(90)-rad);
   
    NewBoundry.x =(int)(abs( CurrentBoundry.x * cosc) + abs(CurrentBoundry.y * sinc));
    NewBoundry.y =(int)(abs( CurrentBoundry.x * sinc) + abs(CurrentBoundry.y * cosc));
  }
  else{
    int x = CurrentBoundry.y;
    int y = CurrentBoundry.x;
    rad =radian( angle - 90);
    sinc = sin(rad);
    cosc = sin(radian(90)-rad);
    cout << "Sinus: " << sinc << "Cosinus:" << cosc <<endl;
    
    NewBoundry.x =(int)((abs(x * cosc) + abs(y * sinc)));
    NewBoundry.y =(int)((abs(x * sinc) + abs(y * cosc)));
    

  }
  cout << NewBoundry.x<<" ";
  cout << NewBoundry.y <<endl;
  
  
  return NewBoundry;
}

double factorial(int x) 
{
	double result_fact=1;

	for (;x>=1;x--){
		result_fact*=x;
	}	
return result_fact;
}

double radian(double x){
	double radians =0;
	double pi = 3.14159265358979323846;
	radians=pi*(x/180.0);

return radians;
}

double sin_custom(double x,int br_clanova){

	double tejlor = 0;
	double a,b,c;

	for(int y=0; y!=br_clanova; y++){
		a=power(-1,y);	
		b=factorial((2*y)+1);
		c=power(x,(2*y)+1);
		tejlor=tejlor+(a*c/b);
}
return tejlor;
}

double power(double base, int exponent)
{
double result=1;
for (exponent; exponent>0; exponent--)
{
result = result * base;
}
return result;
}

void LookupGenerateBitAnalysis(double * lookup,int n){
  
  for (int i = 0 ; i <= 359 ; i ++) {

    lookup[i] = sin (i*PI/180);
    

  }
  for (int i = 0 ; i <= 359 ; i ++) {

    lookup[360+i] = cos (i*PI/180);
  }


  cout << lookup[0]  << "."<< lookup[90] << "." << lookup[180] << "." << lookup[360] << "."<<  lookup[450] <<endl;
}



bool SCGetRotatedImage_FormatChecker(Point2i NewBoundry,Point2i OldBoundry,ImageMatrix2D OldImage,int angle,char* direction,lookup_vector lookup_tabela,int w,int l){
  ImageMatrix2D RotatedImage;
  ImageMatrix1D PixelArray;
  pixel ZeroPixel;
  int x,y;
  int x_check,y_check;
  int tolerance = 0;
  int OldHeight = OldBoundry.x;
  int OldWidth = OldBoundry.y;
 
  //double temp_array [MAX_SIZE_LOOKUP];
  //LookupGenerateBitAnalysis(temp_array,MAX_SIZE_LOOKUP);
 
  sin_result_sc1 sin_result(w,l);
  sin_result = sin(radian(angle));
  sin_result_sc1 cos_result(w,l);
  cos_result = cos(radian(angle));
  cout << "Sin lookup: "<<sin_result  << "Cos lookup: "<<cos_result <<endl;
  double sinc = sin(angle*PI/180);
  double cosc = cos(angle*PI/180);
  cout << "Sin : "<<sinc  << "Cos : "<<cosc <<endl;
  int cy = OldWidth / 2;
  int cx = OldHeight / 2;
  string smer = direction;
  int NewHeight = NewBoundry.x;
  int NewWidth  = NewBoundry.y;
  
  int midx = NewHeight/2 ;
  int midy = NewWidth/2 ;
  RotatedImage.resize(NewHeight,vector<pixel>(NewWidth));
  
  for(int row = 0; row < NewHeight ; row++){

    for(int col = 0; col < NewWidth ; col++){
   
      if (smer == "right"){
      x  = (int)((row-midx ) * cosc - (col-midy) * sinc +cx);
      y  = (int)((col-midy ) * cosc + (row-midx) * sinc +cy);

       x_check  = (int)((row-midx ) * cos_result - (col-midy) * sin_result +cx);
       y_check  = (int)((col-midy ) * cos_result + (row-midx) * sin_result +cy);
      if(x!=x_check || y!=y_check){
	 tolerance++;
	 if (tolerance > 100){
	   return false;}
	
	}
      
      }

      if (smer == "left"){

       x  = (int)((row-midx ) * cosc + (col-midy) * sinc +cx);
       y  = (int)((col-midy ) * cosc - (row-midx) * sinc +cy);

       x_check  = (int)((row-midx ) * cos_result + (col-midy) * sin_result +cx);
       y_check  = (int)((col-midy ) * cos_result - (row-midx) * sin_result +cy);
       
       if(x!=x_check || y!=y_check){
	 tolerance++;
	 if (tolerance > 100){
	   return false;}
	 }

       
      }
      if (x >= 0 && x< OldHeight && y >= 0 && y< OldWidth)
	{
	  RotatedImage[row][col]=(OldImage[x_check][y_check]);
	  
	}
      
      
    }
    
    
  }
  
  cout << "Finished" << endl;
  
  return true;
  
  

  
}
