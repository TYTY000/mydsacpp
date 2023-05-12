#ifndef __DISP__
#define __DISP__

#include "./simu.h"
#include <cstdlib>
#include <iomanip>

void printCustomer ( Customer c )
{
  std::cout << std::setw(4) << c.time;
}

void displayProgress ( Queue<Customer> windows[], Rank nWin, Rank now )
{
  system ("clear");
  std::cout << "============== Time: " << std::setw(4) << now << " =================" << std::endl;
  for (Rank i = 0; i < nWin; i++) {
    std::cout << "Window #" << 'A' + i << ": "  << sum( windows[i] ) << std::endl;
    windows[i].traverse ( printCustomer );  std::cout << std::endl;
  }
}

#endif // !__DISP__

