#ifndef _CPU_HPP_
#define _CPU_HPP_

#include "common.hpp"
#include "vp_address.hpp"
#include "hardware.hpp"
#include <tlm>
#include <tlm_utils/simple_target_socket.h>
#include <tlm_utils/simple_initiator_socket.h>
#include <tlm_utils/tlm_quantumkeeper.h>

class cpu:public sc_core::sc_module
{
public:
  cpu(sc_core::sc_module_name);

  tlm_utils::simple_initiator_socket<cpu> cpu_ic_isoc1;
  tlm_utils::simple_initiator_socket<cpu> cpu_ic_isoc2;
  tlm_utils::simple_target_socket<cpu> cpu_ic_tsoc;

  void setPathBoundary(char *pathBoundary);
  void setPathIn(char *pathIn);
  void setPathOut(char *pathOut);
  void setPathAngle(char *pathAngle);
  void setPathDirection(char *pathDirection);
  
protected:
  int row, col;
  unsigned char ready;
  Point2i Boundary;
  ImageMatrix2D Image2D, RotatedImage;
  Point2i NewBoundary;
  char *pathBoundary;
  char *pathIn;
  char *pathOut;
  char *pathAngle;
  char *pathDirection;
  int Angle;
  double radians = 0;
  std::string direction;
  
  void CPU_process();
  Point2i LoadBoundary(std::string path);
  ImageMatrix2D LoadImageMakeMatrix(std::string path, int rows, int cols);
  int getAngle(std::string path);
  std::string getDirection(std::string path);
  double radian(double x);
  void StoreImageToFile(std::string path, ImageMatrix2D image, int x, int y);
  Point2i FindNewBorder(Point2i CurrentBoundary, double angle);
  
  //void scanFromFile();
  //void writeImageToFile();
  
  typedef tlm::tlm_base_protocol_types::tlm_payload_type pl_t;
  void b_transport(pl_t &, sc_core::sc_time &);
};

#endif
