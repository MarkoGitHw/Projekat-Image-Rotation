#include "common.hpp"
#include "FileOps.hpp"
#include "ImageProcessing.hpp"
#include <valgrind/callgrind.h>
using namespace cv;
using namespace std;



int sc_main(int argc,char * argv[])
{

  
  if (argc < 2){
    cout << "Error!"<<endl; 

    return 0;
  }
  int W_angle = 3; /// potrebno za reprezentaciju celobrojnogdela ugla u radijanima //
  cout << "cosinus: " << sin_custom(90-stod(argv[2]),64);
  double angle = stod(argv[2]);
  double rad = radian(angle);
  double delta =0;
  int prviL;
  int prviI;
  int drugiL;
  double delta2 =0;
  double delta3=0;
  int W_sinc =1; 
  sin_result_sc sinc_bit_test;
  bool pass1 = false;
  bool pass2 = false;
  for (int L = 0 ; L < 50 ; L++){
    
    angle_sc rad_bit_test(W_angle+L,W_angle);
    rad_bit_test = radian(angle);
    cout << "Rezultat za format: "<< W_angle << "-" << L << " " << "je" << rad_bit_test <<endl;  
    delta = abs(rad_bit_test - rad);
    if (delta < 1.0e-5){
      cout << "Prvi dobar format za predstavljanje uglova je: " << W_angle << "-" << L <<endl;
      pass1 = true;
    }
    if (pass1 = true) {
      for (int i = 0 ; i<64; i++){

	delta2 = abs(sin_custom(rad_bit_test,i)-sin(rad));
	cout << "Delta za format: " << W_angle << "." << L <<" i broj clanova: "<<i <<" je:"<<delta2<< endl;
	if (delta2 < 1.0e-5){
	  prviL = L;
	  prviI = i;

	  cout << "Prvi dobar broj clanova je : "<< i <<endl;
	  pass2 = true;
	  break;
	}	    
	
	

      }

      if (pass2 == true)
	break;

    }
  }
  
  angle_sc angle1(W_angle+prviL,W_angle);
  angle1= radian(angle);
    

  for (int j = 0 ; j < 52 ; j++)

    {
      sin_result_sc sin_sc(W_sinc+j,W_sinc);
      sin_sc= sin_custom(angle1,prviI);
      delta3 =abs( sin_sc - sin(radian(angle)));
      cout << "Delta za format: " << W_sinc << "." << j << " je: " << delta3 <<endl;

      if (delta3 < 1.0e-5)
	{
	  break;
	}
      
      
      
      
    }
  
  
  
  
  
  
  Point2f Boundry;

  Point2f NewBoundry;
 
  Boundry = LoadBoundry("/home/marko/Desktop/Projekat/Projekat-Image-Rotation/Data/Dimenzije.txt");
  
  ImageMatrix2D image,image2;

  
  image = LoadImageMakeMatrix("/home/marko/Desktop/Projekat/Projekat-Image-Rotation/Data/SlikaPixel.txt",Boundry.x,Boundry.y);


 
  
  //CALLGRIND_START_INSTRUMENTATION;
  //CALLGRIND_TOGGLE_COLLECT;
  NewBoundry = FindNewBorder(Boundry,stod(argv[2]));

  image2=SCGetRotatedImage(NewBoundry,Boundry,image,stod(argv[2]),argv[1]);

  //CALLGRIND_TOGGLE_COLLECT;
  //CALLGRIND_STOP_INSTRUMENTATION;
  StoreImageToFile("/home/marko/Desktop/Projekat/Projekat-Image-Rotation/Data/Output.txt",image2,NewBoundry.x,NewBoundry.y);
  
  
  
  
  

  return 0;
  
} 
