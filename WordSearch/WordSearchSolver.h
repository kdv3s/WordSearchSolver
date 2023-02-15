#ifndef WORD_SEARCH_SOLVER_H
#define WORD_SEARCH_SOLVER_H
#include <string>
#include <fstream>
#include "MatrixCell.h"

char** build_matrix(int rows, int columns);

void fill_matrix(int rows, int columns, char** , ifstream &file);

void delete_matrix(int rows, char **matrix);

void matrix_search(string word, int rows, int columns, MatrixCell* collected_cells, char** matrix);

void matrix_directional_search(string word, MatrixCell* collected_cells, char** matrix, int &current_x, int &current_y, int& counter, bool& found,
	int increment_y = 0, int increment_x = 0);


#endif
