#include <iostream>

using namespace std;

class GameOfLife
{
  public:
    GameOfLife(); //default constructor
    GameOfLife(int maxSize); //overload
    ~GameOfLife(); //destructor

    void board(int size);

    int size;

    char ** myArray;
};
