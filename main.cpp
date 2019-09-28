#include <iostream>
#include <fstream>
#include "Grid.h"
#include "Classic.h"

using namespace std;

void user_input();

int main(int argc, char const *argv[])
{
  // Runs initial user_input to create a grid before simulation
  user_input();

  Grid* g = new Grid(); // creates new grid on the heap
  g->printGrid();

  return 0;
}

// Handles initial user input before simulation begins
void user_input(){
  // Introduction
  cout << "Hello! Welcome to the game of life!" << endl;
  string response1 = "";
  cout << "Would you like to \n(1) Provide a map file for the grid\n(2) Use random assignment for the grid" << endl;
  cin >> response1;
  // Ensures valid response from the user
  while (response1 != "1" && response1 != "2"){
    cout << "Would you like to \n(1) Provide a map file for the grid\n(2) Use random assignment for the grid" << endl;
    cin >> response1;
  }
  // ----------------- MAP FILE ---------------------------
  if (response1 == "1"){
    string file_name = "";
    cout << "Please input the filepath for your map file (with the .txt extension)." << endl;
    cin >> file_name;
    // Opens text file
    ifstream text_file;
    string line;
    text_file.open(file_name);
    string all_text_from_map_file = "";
    // Iterates through every line in map file if it opens successfully
    if (text_file.is_open()){
      cout << "File opened successfully" << endl;
      while (getline(text_file, line)){
        all_text_from_map_file += line + "\n";
      }
    }
    else{
      // Handles error if file could not be read
      cout << "Could not open the file" << "\n";
      cout << "Usage \'./a.out [filename]\'" <<  endl;
      exit(1);
    }
    // Prints text from map file
    cout << all_text_from_map_file << endl;

  }
  // ----------------- Random Assignment ----------------------
  else{
    // Declare variables
    int input_numRows;
    int input_numColumns;
    double input_populationDensity;
    // Gathers input from user
    cout << "Please input the number of rows for your grid (integer): " << endl;
    cin >> input_numRows;
    cout << "Please input the number of columns for your grid (integer): " << endl;
    cin >> input_numColumns;
    cout << "Please input a DECIMAL value greater than 0 and less than or equal to 1 for population density: " << endl;
    cin >> input_populationDensity;

    // Ensures that values were inputted correctly
    while (!cin){
      cin.clear();
      cin.ignore(999999, '\n');
      cout << "Please input valid values for row amount, column amount, and population density." << endl;
      // Gathers input from user
      cout << "Please input the number of rows for your grid (integer): " << endl;
      cin >> input_numRows;
      cout << "Please input the number of columns for your grid (integer): " << endl;
      cin >> input_numColumns;
      cout << "Please input a DECIMAL value greater than 0 and less than or equal to 1 for population density: " << endl;
      cin >> input_populationDensity;
    }

    // Creates grid with inputted values
    Grid* g1 = new Grid(input_numRows, input_numColumns, input_populationDensity);
    g1->printGrid();

    //search through array and find whether or not the array is open or filled
    int checked = 0;
    checked = g1->checkGrid();
    cout << "There are: " << checked << " cells on the board." << endl;
    cout << "\n" << endl;
    Classic* c = new Classic(g1);
    c->printGrid();
  }
}
