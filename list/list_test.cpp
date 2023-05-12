#include <iostream>
#include "list.h"
#include "listNode.h"
using namespace std;
Rank testID = 0;

#include "list_testhelper.h"

int main (int argc, char *argv[])
{
  if ( argc > 2 ) 
  {
    std::cout << "Usage: " << argv[0] << " <size of test>\a\a" << std::endl;
    return 1;
  }
  srand( (unsigned int) time (NULL) );
  if(argv[1] == NULL) testList<int>(20);
  else testList<int>( atoi( argv[1]) );
  std::cout << "\n\nUnit test done !" << std::endl;
}
