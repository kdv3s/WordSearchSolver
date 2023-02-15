#ifndef MATRIX_CELL_H
#define MATRIX_CELL_H
#include <iostream>
using namespace std;

struct MatrixCell
{
	int x;
	int y;
	char letter;

	friend ostream& operator<<(ostream& os, const MatrixCell& m);
};

#endif