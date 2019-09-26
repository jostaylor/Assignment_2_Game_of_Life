#include <iostream>

using namespace std;

class Grid{
public:
  Grid(); // constructor
  Grid(int numRows, int numColumns, double populationDensity); // overload constructor
  ~Grid(); // destructor
  void printGrid();

  int length;
  int height;
  double popDensity;
  char** myGrid;
};
