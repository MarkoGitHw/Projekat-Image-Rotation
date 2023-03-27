#include "vp.hpp"

using namespace std;

int sc_main(int argc, char *argv[])
{
  if(argc != 6)
    {
      cout << "VP takes 6 arguments." << endl;
      cout << "For example: ./main_d dimension.txt inputFile.txt outputFile.txt angle direction" << endl;
      cout << "For example: angle = 45, direction = right " << endl;
      
      return 0;
    }
  
  vp uut("VirPlat");
  uut.soft.setPathBoundary(argv[1]);
  uut.soft.setPathIn(argv[2]);
  uut.soft.setPathOut(argv[3]);
  uut.soft.setPathAngle(argv[4]);
  uut.soft.setPathDirection(argv[5]);
  
  sc_start(2, sc_core::SC_SEC);

  return 0;
}
