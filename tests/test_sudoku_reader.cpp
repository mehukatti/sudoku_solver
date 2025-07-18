#include "../sudoku_solver/sudoku_file_reader.h"
#include "../sudoku_solver/sudoku_printer.h"

#include <iostream>
using std::cout;

int main()
{
	cout << "Test reading example sudoku. \n";
    std::string file_path = "example_sudokus/easy/sudoku_1.txt";
	std::vector<std::vector<int>> board = read_sudoku(file_path);
    print(board);
	return 0;
}