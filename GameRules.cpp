#include <iostream>
#include "GameRules.h"
//#include "Grid.h"

using namespace std;

Grid* GameRules::generateNextGrid(Grid* g){

  // Creates second grid of same size
  Grid* g2 = new Grid(g->length, g->height, 0);
  g->myGrid[2][3] = 'X';
  g->myGrid[2][2] = 'X';
  g->myGrid[2][1] = 'X';
  g->myGrid[2][0] = 'X';
  g->myGrid[1][0] = 'X';
  cout << "Original grid being printed" << endl;
  g -> printGrid();
  cout<< "New Grid being printed" << endl;
  g2->printGrid();
  // declare variables
  char current_cell;
  int amount_of_neighbors;
  // Iterates through every cell
  for (int i = 0; i < g->length; ++i){
    for (int j = 0; j < g->height; ++j){
      // declare variables
      current_cell = g->myGrid[i][j];
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
      //cout << "Amount of neighbors: " << amount_of_neighbors << endl;
      if(amount_of_neighbors < 2)
      {
        //should be empty next generation
        g2->myGrid[i][j] = '-';
        //code
      }
      else if(amount_of_neighbors == 2)
      {
        //if empty stay empty
        if(current_cell = '-')
        {
          g2->myGrid[i][j] = '-';
        }
        else
        {
          g2->myGrid[i][j] = 'X';
        }
        //if filled stay filled
      }
      else if(amount_of_neighbors == 3)
      {
        //cell stays and if empty cell is made
        g2->myGrid[i][j] = 'X';
      }
      else
      {
        //if 4 or more neighbors then cell dies or space will remain empty
        g2->myGrid[i][j] = '-';
      }
    }
  }
  cout << "updated grid" << endl;
  g2->printGrid();
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
