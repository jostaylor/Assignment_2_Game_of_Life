#include "GameOfLife.h"
#include <iostream>

using namespace std;

GameOfLife::GameOfLife() //default constructor
{
  myArray = new char * [size];
  //initialization of default values;
  //on heap, so must destruct at the end
  //size = 5;
}

GameOfLife::GameOfLife(int maxSize)
{
  myArray = new int[maxSize];
  size = maxSize;
}


void GameOfLife::board(int size)
{
  myArray = new char * [size];
  for(int i = 0; i < size; ++i)
  {
    myArray[i] = new char * [size]
    for(int j = 0; j < i; ++j)
    {
      myArray[i][j] = '-'
    }
  }
}

// GameOfLife::GameOfLife(int maxSize)
// {
//   myArray = new char[maxSize];
//   size = maxSize;
//   top = -1;
// }

// GameOfLife::~GameOfLife()
// {
//   //lets build some character
//   //your job is to research this
//   delete []myArray;
// }

// void GameOfLife::push(char d)
// {
//   //need to check error/boundry check
//   //this is your job
//   myArray[++top] = d;
// }
