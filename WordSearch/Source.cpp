#include "WordSearchSolver.h"
#include <cstdio>

int main()
{
	int data_rows = 0;
	int data_columns = 0;
	int word_list_rows = 0;
	int word_list_count = 0;
	string data_input;
	string word_list_input;
	string line;
	cout << "Enter the name of a text file that contains the data set. User should enter ExampleDataInput.txt or a text file formatted like ExampleDataInput.txt" << endl;
	cin >> data_input;
	cout << "Enter the name of a text file that contains the list of words to search for. User should enter ExampleWordListInput.txt or a text file formatted like ExampleWordListInput.txt" << endl;
	cin >> word_list_input;
	if (data_input.substr(data_input.length() - 4, 4) != ".txt")
	{
		data_input = data_input + ".txt";
	}
	if (word_list_input.substr(word_list_input.length() - 4, 4) != ".txt")
	{
		word_list_input = word_list_input + ".txt";
	}
	char** matrix = nullptr;
	MatrixCell* collected_cells = nullptr;
	string* word_list = nullptr;
	ifstream data_file(data_input);
	while(getline(data_file,line))
		data_rows++;
	data_columns = line.length();
	matrix = build_matrix(data_rows + 2, data_columns + 2);
	collected_cells = new MatrixCell[data_columns];
	fill_matrix(data_rows + 2, data_columns + 2, matrix, data_file);
	ifstream word_list_file(word_list_input);
	while (getline(word_list_file, line))
		word_list_rows++;
	word_list = new string[word_list_rows];
	word_list_file.clear();
	word_list_file.seekg(0);
	while (getline(word_list_file, line))
	{
		word_list[word_list_count] = line;
		word_list_count++;
	}
	for (int i = 0; i < word_list_count; i++)
		matrix_search(word_list[i], data_rows + 2, data_columns + 2, collected_cells, matrix);
	delete_matrix(data_rows + 2, matrix);
	delete[] collected_cells;
	delete[] word_list;
	collected_cells = nullptr;
	word_list = nullptr;
	cout << "Press any key to exit" << endl;
	getchar();
}