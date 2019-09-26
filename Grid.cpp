#include <iostream>
#include "Grid.h"

using namespace std;

Grid::Grid(){
  // declares default length and height - 10
  length = 10;
  height = 10;
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

Grid::Grid(int numRows, int numColumns, double populationDensity){
  // declares default length and height - 10
  length = numRows;
  height = numColumns;
  popDensity = populationDensity;
  // creates an array of arrays on the heap
  myGrid = new char*[length];
  for (int i = 0; i < length; ++i){
    myGrid[i] = new char[height];
    // initialization of the dashes into the grid
    for (int j = 0; j < height; ++j){
      // Generates random decimal number between 0 and 1
      double random_decimal = (double)(rand() % 10000) / 10000;
      // Inserts '-' or 'X' depending if the random decimal is above or below the given density
      if (random_decimal <= popDensity){
        myGrid[i][j] = 'X';
      }
      else{
        myGrid[i][j] = '-';
      }
    }
  }
}

Grid::~Grid(){
  // deletes each inner array
  for (int i = 0; i < length; ++i){
    delete myGrid[i];
  }
  // deletes the outer array that was holding all of the inner arrays (columns)
  delete []myGrid;
  cout << "Deleted objects from heap" << endl;
}

void Grid::printGrid(){
  for (int i = 0; i < length; ++i){
    for (int j = 0; j < height; ++j){
      cout << myGrid[i][j];
    }
    cout << "\n";
  }
}
