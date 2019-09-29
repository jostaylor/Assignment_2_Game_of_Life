#include <iostream>
#ifndef GAMERULES_H
#define GAMERULES_H
#include "Grid.h"

using namespace std;

class GameRules{
public:
  // stuff
  GameRules(); // constructor

  int x;
  int y;
  Grid* generateNextGrid(Grid* g);
};
#endif
