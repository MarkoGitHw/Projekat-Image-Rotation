#include "vp.hpp"

using namespace sc_core;

vp::vp(sc_module_name name):
  sc_module(name),
  soft("cpu"),
  hard("gpio"),
  ic("interconnect"),
  bram("memory")
{
  soft.cpu_ic_isoc1.bind(ic.ic_cpu_tsoc1);
  soft.cpu_ic_isoc2.bind(ic.ic_cpu_tsoc2);
  ic.ic_cpu_isoc.bind(soft.cpu_ic_tsoc);
  ic.ic_gpio_isoc.bind(hard.gpio_ic_tsoc);
  ic.ic_mem_isoc.bind(bram.mem_ic_tsoc);
  hard.gpio_ic_isoc.bind(ic.ic_gpio_tsoc);
  hard.gpio_mem_isoc.bind(bram.mem_gpio_tsoc);

  SC_REPORT_INFO("VP", "Platform is constructed");
}
  
