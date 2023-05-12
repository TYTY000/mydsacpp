#ifndef __QUEEN_STACK__
#define __QUEEN_STACK__

#include <iostream>
using namespace std;
#include <cstdio>
#include <cstdlib>
#include "./stack.h"
#include "./queen.h"

typedef enum {Continuous, Step} RunMode;

extern RunMode runMode; 
extern int nSolu;   // ans
extern int nCheck; //try 

void placeQueens ( Rank );
void displayRow ( Queen& q, Rank );
void displayProgress ( Stack<Queen>& S, Rank );

#endif // !__QUEEN_STACK__
