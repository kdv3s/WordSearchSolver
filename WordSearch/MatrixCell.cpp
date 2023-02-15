#include "MatrixCell.h"

ostream& operator<< (ostream& os, const MatrixCell& m)
{
	os << "The letter, " << m.letter << ", is at row: " << m.y << ", column: " << m.x << endl;
	return os;
}
