#include "WordSearchSolver.h"

char** build_matrix(int rows, int columns)
{
	char** matrix = new char*[rows];
  for (int i = 0; i < rows; i++)
    matrix[i] = new char[columns];
  return matrix;
}

void fill_matrix(int rows, int columns, char **matrix, ifstream &data_file)
{
  data_file.clear();
  data_file.seekg(0);
  string line;
  char c;
  for (int i = 0; i < columns; i++)
    matrix[0][i] = ' ';
  for (int i = 0; i < columns; i++)
    matrix[rows - 1][i] = ' ';
  for (int i = 0; i < rows; i++)
    matrix[i][0] = ' ';
  for (int i = 0; i < rows; i++)
    matrix[i][columns - 1] = ' ';
  int j = 1;
  while (getline(data_file, line))
  {
    for (int i = 1; i < columns - 1; i++)
      matrix[j][i] = line[i - 1];
    j++;
  }
}

void delete_matrix(int rows, char** matrix) 
{
  for (int i = 0; i < rows; i++)
    delete[] matrix[i];
  delete[] matrix;
  matrix = nullptr;
}

void matrix_search(string word, int rows, int columns, MatrixCell* collected_cells, char** matrix)
{
  static bool found = false;
  static int current_x = 0;
  static int current_y = 0;
  static int counter = 0;
  if (counter == 0)
  {
    int y = 1;
    while (y < rows)
    {
      for (int x = 1; x < columns; x++)
      {
        if (matrix[y][x] == word[counter])
        {
          collected_cells[counter].letter = word[counter];
          collected_cells[counter].x = x;
          collected_cells[counter].y = y;
          counter++;
          current_x = x;
          current_y = y;
          matrix_search(word, rows, columns, collected_cells, matrix);
        }
        if ((found == false) && (y == rows - 1))
        {
          cout << "The word, " << word << ", was not found." << endl;
          cout << endl;
          break;
        }
      }
      if ((found == true))
      {
        cout << "The word, " << word << ", was found." << endl;
        for (int i = 0; i < word.length(); i++)
          cout << collected_cells[i];
        cout << endl;
        found = false;
        break;
      }
      y++;
    }
  }
  else if (counter < word.length())
  {
    if (matrix[current_y + 1][current_x + 1] == word[counter])  
     matrix_directional_search(word, collected_cells, matrix, current_x, current_y, counter, found, 1, 1);;
    if (matrix[current_y - 1][current_x + 1] == word[counter])  
     matrix_directional_search(word, collected_cells, matrix, current_x, current_y, counter, found, -1, 1);;
    if (matrix[current_y + 1][current_x - 1] == word[counter]) 
     matrix_directional_search(word, collected_cells, matrix, current_x, current_y, counter, found, 1, -1);;
    if (matrix[current_y - 1][current_x - 1] == word[counter]) 
     matrix_directional_search(word, collected_cells, matrix, current_x, current_y, counter, found, -1, -1);;
    if (matrix[current_y - 1][current_x] == word[counter]) 
     matrix_directional_search(word, collected_cells, matrix, current_x, current_y, counter, found, -1, 0);;
    if (matrix[current_y + 1][current_x] == word[counter]) 
     matrix_directional_search(word, collected_cells, matrix, current_x, current_y, counter, found, 1, 0);;
    if (matrix[current_y][current_x + 1] == word[counter]) 
     matrix_directional_search(word, collected_cells, matrix, current_x, current_y, counter, found, 0, 1);
    if (matrix[current_y][current_x - 1] == word[counter]) 
     matrix_directional_search(word, collected_cells, matrix, current_x, current_y, counter, found, 0, -1);
  }
  counter = 0;
}

void matrix_directional_search(string word, MatrixCell* collected_cells, char** matrix, int& current_x, int& current_y, int& counter, bool& found,
  int increment_y, int increment_x)
{
  collected_cells[counter].x = current_x + increment_x;
  collected_cells[counter].y = current_y + increment_y;
  collected_cells[counter].letter = word[counter];
  counter++;
  current_x += increment_x;
  current_y += increment_y;
  if (counter == word.length())
  {
    found = true;
  }
  if (matrix[current_y + increment_y][current_x + increment_x] == word[counter])
    matrix_directional_search(word, collected_cells, matrix, current_x, current_y, counter, found, increment_y, increment_x);
  counter--;
  current_x -= increment_x;
  current_y -= increment_y;
}

