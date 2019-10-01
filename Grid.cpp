#include <iostream>
#include "Grid.h"

using namespace std;

Grid::Grid(){
  // declares default length and height - 10 (and other variables)
  length = 10;
  height = 10;
  gameMode = "Classic";
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
  // declares variables
  length = numRows;
  height = numColumns;
  gameMode = "Classic";
  outputMode = "Pause";
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

// -------------- do we need this? -------------------
int Grid::checkGrid()
{
  int isFilled = 0;
  for(int i = 0; i < length; ++i)
  {
    for(int j = 0; j < height; ++j)
    {
      if(myGrid[i][j] == 'X')
      {
        isFilled +=1;
      }
    }
  }
  return isFilled;
}
// ---------------------^^^^^^--------------------------

// returns 0 if dash and 1 if X
// contatins conditionals for each MODE
int Grid::getValue(int x, int y, string gameMode){
  //cout << "GameMode is: " << gameMode << endl;
  // -------------------------Classic Mode-------------------------------
  if (gameMode == "Classic"){
    if (x == -1 || x >= length || y == -1 || y >= height){ // if coordinate is outside grid
      return 0;
    }
    // Returns numerical value for char
    else{
      if (myGrid[x][y] == 'X'){
        return 1;
      }
      else if (myGrid[x][y] == '-'){
        return 0;
      }
      else{
        cout << "slot has invalid char" << endl;
      }
    }
  }
  // -----------------------------Mirror Mode------------------------------
  else if (gameMode == "Mirror"){
    // Sets x and/or y to its reflection if the search is outside of the grid
    if (x == -1){
      x++;
    }
    if (x == length){
      x--;
    }
    if (y == -1){
      y++;
    }
    if (y == height){
      y--;
    }
    // Returns numerical value for char
    if (myGrid[x][y] == 'X'){
      return 1;
    }
    else if (myGrid[x][y] == '-'){
      return 0;
    }
    else{
      cout << "slot has invalid char" << endl;
    }
  }
  // -----------------------------Donut Mode------------------------------
  else if (gameMode == "Donut"){
    // Wraps x or y around the grid if the search exists outside the grid
    if (x == -1){
      x = length-1;
    }
    if (x == length){
      x = 0;
    }
    if (y == -1){
      y = height-1;
    }
    if (y == height){
      y = 0;
    }
    // Returns numerical value for char
    if (myGrid[x][y] == 'X'){
      return 1;
    }
    else if (myGrid[x][y] == '-'){
      return 0;
    }
    else{
      cout << "slot has invalid char" << endl;
    }
  }
  else{
    cout << "whoops, mode incorrect" << endl;
  }
}
