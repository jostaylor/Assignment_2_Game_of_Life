#include <iostream>
#ifndef GRID_H
#define GRID_H

using namespace std;

class Grid{
public:
  Grid(); // constructor
  Grid(int numRows, int numColumns, double populationDensity); // overload constructor
  ~Grid(); // destructor
  void printGrid(); //prints grid to the screen
  int getValue(int x, int y, string gameMode); // returns 0 if dash or 1 if X

  string outputMode; // either Pause, Enter, or File
  string gameMode; // either Classic, Donut, or Mirror
  int length; // length of grid
  int height; // height of grid
  double popDensity; // population density of the grid
  char** myGrid; // the actual grid object
};
#endif
