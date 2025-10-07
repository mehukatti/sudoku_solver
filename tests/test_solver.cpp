#include "../sudoku_solver/sudoku_file_reader.h"
#include "../sudoku_solver/sudoku_printer.h"
#include "../sudoku_solver/sudoku_solver.h"

#include <iostream>
using std::cout;

int main()
{
	cout << "Test reading example sudoku. \n";
    std::string file_path = "example_sudokus/hard/sudoku_1.txt";
	std::vector<std::vector<std::vector<int>>> board = read_sudoku(file_path);
    print(board);
    SudokuSolver solver;
    solver.board = board;
    solver.solve();
    cout << "After solving:\n";
    print(solver.board);
	return 0;
}