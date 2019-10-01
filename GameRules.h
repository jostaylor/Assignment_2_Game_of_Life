#include <iostream>
#ifndef GAMERULES_H
#define GAMERULES_H
#include "Grid.h"

using namespace std;

class GameRules{
public:
  GameRules(); // constructor

  int x;
  int y;
  //uses rules to check and create the next generation
  Grid* generateNextGrid(Grid* g, string mode);
  //compares 2 grids to see if they are identical, returns true if they are identical
  bool compare(Grid* first, Grid* second);
};
#endif
