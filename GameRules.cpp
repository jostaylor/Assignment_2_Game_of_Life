#include <iostream>
#include "GameRules.h"

using namespace std;

Grid* GameRules::generateNextGrid(Grid* g, string mode, string outputMode){
  // Creates second grid of same size
  Grid* g2 = new Grid(g->length, g->height, 0);
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
      amount_of_neighbors += g->getValue(i+1, j, mode);
      amount_of_neighbors += g->getValue(i+1, j+1, mode);
      amount_of_neighbors += g->getValue(i, j+1, mode);
      amount_of_neighbors += g->getValue(i-1, j+1, mode);
      amount_of_neighbors += g->getValue(i-1, j, mode);
      amount_of_neighbors += g->getValue(i-1, j-1, mode);
      amount_of_neighbors += g->getValue(i, j-1, mode);
      amount_of_neighbors += g->getValue(i+1, j-1, mode);
      // Implements Game of Life Rules to determine the cell's state in next generation

      //cout << "Amount of neighbors: " << amount_of_neighbors << endl;
      if(amount_of_neighbors < 2)
      {
        //should be empty next generation
        g2->myGrid[i][j] = '-';
      }
      else if(amount_of_neighbors == 2)
      {
        //if empty stay empty
        if(current_cell == '-')
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
  if(outputMode != "File")
  {
    g2->printGrid();
  }
  return g2;
}

bool GameRules::compare(Grid* first, Grid* second)
{
  //to see how many similarties there are
  int similarities = 0;
  //total number of possible similarities
  int total = first->length * first->height;
  //only need to use one of their heights and lengths since they are the same
  for(int i = 0; i < first->length; ++i)
  {
    for(int j = 0; j < first->height; ++j)
    {
      //if the same spots on the grid share the same value then increment similarties
      if(first->myGrid[i][j] == second->myGrid[i][j])
      {
        similarities++;
      }
    }
  }
  //if similarties are equal to the total possible then the grids are the same and the program should stop
  if(similarities == total)
  {
    return true;
  }
  else
  //else continue but keep checking
  {
    return false;
  }
}

GameRules::GameRules(){
  x = 0;
  y = 0;
}
