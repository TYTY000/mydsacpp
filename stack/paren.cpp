#include "./stack.h"
#include <string>
using namespace std;

bool paren ( string expr );

int main (int argc, char *argv[])
{
  string expr = "(";
  string exp1 = "{(([](()))())}";
  string exp2 = " ( 1 + 2 ) * ( 3 * 4 ) / 5";
  string exp3 = " {}[](0((x) ";
  std::cout << std::boolalpha << paren( expr ) << std::endl;
  std::cout << std::boolalpha << paren( exp1 ) << std::endl;
  std::cout << std::boolalpha << paren( exp2 ) << std::endl;
  std::cout << std::boolalpha << paren( exp3 ) << std::endl;
  return 0;
}

bool paren ( string expr )
{
  Stack<char> S;
  std::cout << "expr = " << expr << std::endl;
  for (auto it = expr.cbegin(); it != expr.cend(); it++)
  {
    switch (*it) {
      case '(' : case '[' : case '{' : S.push( *it ); break;
      case ')' : if ( ( S.empty() ) || ( S.pop() != '(' ) ) 
                 {
                 return false;
                 }  break;
      case ']' : if ( ( S.empty() ) || ( S.pop() != '[' ) ) 
                 {
                 return false;
                 }  break;
      case '}' : if ( ( S.empty() ) || ( S.pop() != '{' ) ) 
                 {
                 return false;
                 }  break;
      default:
        break;
    }
  }
  if (!S.empty())
                 std::cout << S << std::endl;
  return S.empty();
}

