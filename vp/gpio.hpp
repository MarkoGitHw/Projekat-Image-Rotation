#ifndef _GPIO_HPP_
#define _GPIO_HPP_

#include "common.hpp"
#include "vp_address.hpp"
#include <tlm>
#include <tlm_utils/simple_target_socket.h>
#include <tlm_utils/simple_initiator_socket.h>
#include <tlm_utils/tlm_quantumkeeper.h>

class gpio:public sc_core::sc_module
{
public:
  gpio(sc_core::sc_module_name);

  tlm_utils::simple_target_socket<gpio> gpio_ic_tsoc;
  tlm_utils::simple_initiator_socket<gpio> gpio_mem_isoc;
  tlm_utils::simple_initiator_socket<gpio> gpio_ic_isoc;

protected:
  int rows, cols;
  int nrows, ncols;
  int Angle;
  Point2i Boundary, NewBoundary;
  sc_core::sc_time offset;
  unsigned char ready;
  std::string direction;
  ImageMatrix2D Image2D, RotatedImage;
  double radians;
  
  tlm::tlm_generic_payload pl;
  tlm_utils::tlm_quantumkeeper qk;

  ImageMatrix2D GetRotatedImage(Point2i NewBoundary, Point2i OldBoundary, ImageMatrix2D OldImage, sc_angle angle, std::string direction);
  double radian(double x);
  
  typedef tlm::tlm_base_protocol_types::tlm_payload_type pl_t;
  void b_transport(pl_t &, sc_core::sc_time &);
  void gpio_s();
  void msg(const pl_t&);
};

#endif
