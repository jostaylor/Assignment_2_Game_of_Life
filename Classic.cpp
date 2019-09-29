/*
#include <iostream>
#include "Classic.h"

using namespace std;

Classic::Classic()
{
  // creates an array of arrays on the heap
  myGrid = new char*[length];
  for (int i = 0; i < length; ++i){
    myGrid[i] = new char[height];
    // initialization of the dashes into the grid
    for (int j = 0; j < height; ++j){
      myGrid[i][j] = '-';
    }
  }
}

Classic::Classic(Grid g)
{
  myGrid = new char*[length];
  for (int i = 0; i < g.length; ++i){
    // initialization of the dashes into the grid
    for (int j = 0; j < g.height; ++j){
      myGrid[i][j] = g[i][j];
    }
  }
}

Classic::~Classic(){
  delete []myGrid;
}

void printGrid()
{
  for (int i = 0; i < myGrid.length; ++i){
    for (int j = 0; j < myGrid.height; ++j){
      cout << myGrid[i][j];
    }
    cout << "\n";
  }
}

*/

//int checkLocation();
