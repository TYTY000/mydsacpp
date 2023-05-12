#include "simu.h"

int delay;

int main (int argc, char *argv[])
{
  if ( argc < 4 )
  {
    std::cout << "Usage : " << argv[0] << " <nWin> <time> <delay(ms)>" << std::endl;
    return -1;
  }
  srand( (unsigned int ) time ( NULL ) );
  delay = atoi ( argv[3] );
  simulate ( atoi ( argv[1] ), atoi ( argv[2] ) );
  return 0;
}
