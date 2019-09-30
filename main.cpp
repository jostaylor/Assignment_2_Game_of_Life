#include <iostream>
#include <fstream>
#include <cstdlib>
#include <unistd.h>
#include "Grid.h"
#include "GameRules.h"
// #include "Classic.h"

using namespace std;

Grid* user_input();
void user_input_2(Grid* g1);
// void clearScreen();
void multipleGenerations(GameRules gr, Grid* g, Grid* g1);

int main(int argc, char const *argv[])
{
  // Runs initial user_input to create a grid before simulation and set mode variables
  Grid* g = user_input();
  user_input_2(g);

  g->myGrid[2][3] = 'X';
  g->myGrid[2][2] = 'X';
  g->myGrid[2][1] = 'X';
  g->myGrid[2][0] = 'X';
  g->myGrid[1][0] = 'X';
  Grid* testGrid = new Grid(g->length, g->height, g->popDensity); // creates new grid on the heap
  //testGrid->printGrid();
  //g->gameMode = "Donut"; // sets mode to donut
  GameRules gr;
  //use the grid created by the user
  system("pause");
  multipleGenerations(gr, g, testGrid);
  // gr.generateNextGrid(g);
  // clearScreen();
  //gr.generateNextGrid(testGrid);

  return 0;
}

// Handles initial user input before simulation begins
Grid* user_input(){
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

    // Process file
    // here
    Grid* g1 = new Grid();
    return g1;
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
    return g1;
    //search through array and find whether or not the array is open or filled
    //int checked = 0;
    //checked = g1->checkGrid();
    //cout << "There are: " << checked << " cells on the board." << endl;
    //cout << "\n" << endl;
    //Classic* c = new Classic(g1);
    //c->printGrid();
  }

}

void user_input_2(Grid* g1){
  // --------- User chooses mode ---------------
  int inputted_game_mode = 0;
  cout << "What game mode would like to run in?" << endl;
  cout << "(1) Classic mode\n(2) Donut Mode\n(3) Mirror Mode" << endl;
  cin >> inputted_game_mode;
  // Ensures valid input
  while (!cin || inputted_game_mode <= 0 || inputted_game_mode >= 4){
    cin.clear();
    cin.ignore(999999, '\n');
    cout << "Please input a valid number." << endl;
    cout << "What game mode would like to run in?" << endl;
    cout << "(1) Classic mode\n(2) Donut Mode\n(3) Mirror Mode" << endl;
    cin >> inputted_game_mode;
  }
  // correctly initializes variable
  if (inputted_game_mode == 1){
    g1->gameMode = "Classic";
  }
  else if (inputted_game_mode == 2){
    g1->gameMode = "Donut";
  }
  else if (inputted_game_mode == 3){
    g1->gameMode = "Mirror";
  }
  else{
    cout << "Something went wrong. Please try again." << endl;
    exit(1);
  }
  // ---------------- User chooses output method ------------------------
  int inputted_output_mode = 0;
  cout << "Would you like to:\n(1) Have a pause in between generations\n(2) Press ENTER to view the generation\n(3) Output the generations to a file" << endl;
  cin >> inputted_output_mode;
  // Ensures valid input
  while (!cin || inputted_output_mode <= 0 || inputted_output_mode >= 4){
    cin.clear();
    cin.ignore(999999, '\n');
    cout << "Please input a valid number." << endl;
    cout << "Would you like to:\n(1) Have a pause in between generations\n(2) Press ENTER to view the generation\n(3) Output the generations to a file" << endl;
    cin >> inputted_output_mode;
  }
  // correctly initializes variable
  if (inputted_output_mode == 1){
    g1->outputMode = "Pause";
  }
  else if (inputted_output_mode == 2){
    g1->outputMode = "Enter";
  }
  else if (inputted_output_mode == 3){
    g1->outputMode = "File";
  }
  else{
    cout << "Something went wrong. Please try again." << endl;
    exit(1);
  }
}
// ------------------ Clear screen method --------------------------------
void static clearScreen()
{
  for(int i = 0; i < 10; ++i)
  {
    cout << "\n\n\n\n\n\n\n\n\n\n";
  }
  //add space between generations
  cout << "----------" << endl;
}
// ------------------- Runs Multiple Generations --------------------------
void multipleGenerations(GameRules gr, Grid* g, Grid* g1)
{
  string user = g->outputMode;
  // while(user != "Pause" || user != "Enter" || user != "File")
  // {
  //   gr.generateNextGrid(g);
  //   clearScreen();
  // }
  //Don't need an if statement for pause because the while loop will just stop running so it will be paused
  //This is to do the "Enter" key.
  if(user == "Enter")
  {
    char end;
    g1 = gr.generateNextGrid(g);
    int counter = 0;
    while(counter != 50)
    {
      //system("pause");
      g1 = gr.generateNextGrid(g1);
      cout << "Press enter to continue.... " << endl;
      cin.get(end);
      counter += 1;
    }
  }
  else if(user == "Pause")
  {
    g1 = gr.generateNextGrid(g);
    int counter = 0;
    while(true)//counter != 50)
    {
      //system("pause");
      g1 = gr.generateNextGrid(g1);
      usleep(750000);
      //counter += 1;
    }
  }

}
