#include "GameOfLife.cpp"
#include <iostream>

using namespace std;


// void board(int size)
// {
//   for(int i = 0; i < size; ++i)
//   {
//     for(int j = 0; j < j; ++j)
//     {
//       cout << "0";
//       cout << "   ";
//     }
//     cout << "\n";
//   }
// }

int main(int argc, char const *argv[])
{
  // GameOfLife
  GameOfLife a;
  a.board(5);
  //display board
  cout << a.myArray << endl;

  return 0;
}
