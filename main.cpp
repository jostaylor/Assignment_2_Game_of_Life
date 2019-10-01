#include <iostream>
#include <fstream>
#include <cstdlib>
#include <unistd.h>
#include "Grid.h"
#include "GameRules.h"
// #include "Classic.h"

using namespace std;

Grid* user_input();
string user_input_2(Grid* g1);
// void clearScreen();
void multipleGenerations(GameRules gr, Grid* g, Grid* g1, string s);

int main(int argc, char const *argv[])
{
  string gameMode = "";
  // Runs initial user_input to create a grid before simulation and set mode variables
  Grid* g = user_input();
  gameMode = user_input_2(g);

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
  //system("pause");
  multipleGenerations(gr, g, testGrid, gameMode);
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
    // Opens text file and declares variable
    ifstream text_file;
    string line;
    int grid_length = 1;
    int grid_height = 1;
    string grid_from_text_file = "";
    int line_count = 0;
    text_file.open(file_name);
    // Iterates through every line in map file if it opens successfully
    if (text_file.is_open()){
      cout << "File opened successfully" << endl;
      // Iterates through file and adds grid text to string grid_from_text_file
      while (getline(text_file, line)){
        // first line in file
        if (line_count == 0){ // number of rows here ie length
          // Checks to make sure the dimension is listed properly in the text file
          try{
            grid_length = stoi(line);
          }
          catch (const std::invalid_argument e){
            cout << "Error reading dimensions of grid: " << line << endl;
            cout << "Please fix and retry." << endl;
            exit(1);
          }
          line_count++;
          continue;
        }
        // second line in file
        if (line_count == 1){ // number of columns here ie height
          // Checks to make sure the dimension is listed properly in the text file
          try{
            grid_height = stoi(line);
          }
          catch (const std::invalid_argument e){
            cout << "Error reading dimensions of grid: " << line << endl;
            cout << "Please fix and retry." << endl;
            exit(1);
          }
          line_count++;
          continue;
        }
        // Iterates through a single line of the grid
        for (int i = 0; i < line.size(); ++i){
          // Checks to make sure every line is the corrct length (grid_height)
          if (line.size()-1 != grid_height){
            cout << "Map grid does not match dimensions listed. Please fix and try again." << endl;
            exit(1);
          }
          // Checks to make sure only Xs and dashes exist in the grid
          if (line[i] != '\r' && line[i] != '\n'){ // Makes sures it isn't falsely identifying inivisble characters
            if (line[i] != 'X' && line[i] != '-'){ // If the grid contains something other than a dash or X
              cout << "Invalid character in map file: " << line << endl;
              cout << "Please ensure that there are only \'X\' and \'-\' characters in the grid, and then retry." << endl;
              exit(1);
            }
          }
        }
        // Inserts each char from the txt file into the string variable grid_from_text_file
        grid_from_text_file = grid_from_text_file + line + "\n";
        line_count++;
      }
    }
    else{
      // Handles error if file could not be read
      cout << "Could not open the file" << "\n";
      cout << "Usage \'./a.out [filename]\'" <<  endl;
      exit(1);
    }
    // Checks to make sure there are the correct amount of lines (grid_length)
    if (line_count-2 != grid_length){
      cout << "Dimensions of map grid incorrect. Please fix and try again." << endl;
      exit(1);
    }

    // Creates grid object with correctly inputted dimensions
    Grid* g1 = new Grid(grid_length, grid_height, 0);
    // This variables iterates through every char in the string variable grid_from_text_file
    // INCLUDING \r and \n characters
    int string_index = 0;
    // Loops for each index in the grid
    for (int i = 0; i < grid_length; ++i){
      for (int j = 0; j < grid_height; ++j){
        // If the char is NOT a special/inivisble \n or \r char
        if (grid_from_text_file[string_index] != '\n' && grid_from_text_file[string_index] != '\r'){
          // Adds char from the string variable to the grid object
          g1->myGrid[i][j] = grid_from_text_file[string_index];
          string_index++;
        }
        // Continues the index through the string variable and resets the loop so the grid object's index is correct
        else{
          string_index++;
          j--;
        }
      }
    }
    // Prints the grid for the user to see
    cout << "Grid successfully built from map file:" << endl;
    g1->printGrid();
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
  }

}

string user_input_2(Grid* g1){
  // --------- User chooses mode ---------------
  string mode;
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
    mode = "Classic";
    //g1->gameMode = "Classic";
  }
  else if (inputted_game_mode == 2){
    mode = "Donut";
    //g1->gameMode = "Donut";
  }
  else if (inputted_game_mode == 3){
    mode = "Mirror";
    //g1->gameMode = "Mirror";
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
  return mode;
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
void multipleGenerations(GameRules gr, Grid* g, Grid* g1, string s)
{
  string user = g->outputMode;

  if(user == "Enter")
  {
    char end;
    cout << "Generation 1" << endl;
    g1 = gr.generateNextGrid(g, s);
    //grab char so it runs within the loop properly
    cin.get(end);
    int counter = 2;
    while(end != 'c')
    {
      cout << "Generation " << counter << endl;
      g1 = gr.generateNextGrid(g1, s);
      cout << "Press enter to continue....(c to exit) " << endl;
      cin.get(end);
      counter++;
    }
  }
  else if(user == "Pause")
  {
    g1 = gr.generateNextGrid(g, s);
    int counter = 0;
    while(true)
    {
      cout << "Generation " << counter << endl;
      g1 = gr.generateNextGrid(g1, s);
      counter++;
      usleep(750000);
      //counter += 1;
    }
  }
  else if (user == "File")
  {
    string output_file_name = "";
    cout << "Please input the name of the text file you'd like to output to (with file extension)." << endl;
    cin >> output_file_name;
    ofstream output_text_file;
    output_text_file.open(output_file_name);
    
    output_text_file << "test text" << endl;
    output_text_file.close();
  }
}
