#include <iostream>
#include "GameRules.h"
//#include "Grid.h"

using namespace std;

Grid* GameRules::generateNextGrid(Grid* g){

  // Creates second grid of same size
  Grid* g2 = new Grid(g->length, g->height, 0);
  g2->myGrid[2][3] = 'X';
  g2->printGrid();
  // declare variables
  char current_cell;
  int amount_of_neighbors;
  // Iterates through every cell
  for (int i = 0; i < g->length; ++i){
    for (int j = 0; j < g->height; ++j){
      // declare variables
      current_cell = g2->myGrid[i][j];
      amount_of_neighbors = 0;
      // Checks every cell around [i][j]
      amount_of_neighbors += g->getValue(i+1, j);
      amount_of_neighbors += g->getValue(i+1, j+1);
      amount_of_neighbors += g->getValue(i, j+1);
      amount_of_neighbors += g->getValue(i-1, j+1);
      amount_of_neighbors += g->getValue(i-1, j);
      amount_of_neighbors += g->getValue(i-1, j-1);
      amount_of_neighbors += g->getValue(i, j-1);
      amount_of_neighbors += g->getValue(i+1, j-1);
      // Implements Game of Life Rules to determine the cell's state in next generation
      // here
      if(amount_of_neighbors < 2)
      {
        //should be empty next generation
        current_cell = '-';
        //code
      }
      else if(neighbors == 2)
      {
        //if empty stay empty
        if(current_cell = '-')
        {
          current_cell = '-';
        }
        else
        {
          current_cell = 'X';
        }
        //if filled stay filled
      }
      else if(cell == 3)
      {
        //cell stays and if empty cell is made
        current_cell = 'X';
      }
      else
      {
        //if 4 or more neighbors then cell dies or space will remain empty
        current_cell = '-';
      }
    }
  }

  // test work. not sure if we will need to keep these x and y variables
  x = g->length;
  y = g->height;
  cout << x << endl;
  cout << y << endl;
  cout << g->getValue(x, y) << endl;
  return g;
}

GameRules::GameRules(){
  x = 0;
  y = 0;
}
