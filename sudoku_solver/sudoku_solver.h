#include <vector>
#include <iostream>
using std::cout;

void invalid_values(std::vector<int>& cell_values){
    // Check for invalid values in a cell
    if (cell_values.size()==0){
        throw ("Cell should not be empty. Internal error.");
    }
    
    for (int i = 0;i < cell_values.size(); i++)
    {
        if (cell_values[i]< 0) {
            throw ("Cell contains negative values");
        }
        else if (cell_values[i]>9) {
            throw ("Cell contains values over 9");
        }
    }
}

bool unsolved_cell(std::vector<int>& cell_values){
    // Check if the cell is unsolved.
    // Unsolved cell contains only zero at the beginning.
    // After some iterations, the zero is removed and all possible solutions are stored in the cell.
    // Possible solutions are removed until only one number between 1-9 is fullfills the rules.
    // Cell is solved if it contains only one value that is between 1-9.

    if (cell_values.size()> 1) {
        // contains more than one possible solution
        return true;
    }

    if (cell_values[0]==0){
        // is still zero
        return true;
    }
    else {
        // is solved
        return false;
    }
}

bool missing_solutions(std::vector<std::vector<std::vector<int>>>& board){
    // Check if all the cells have one and only one solution that is not zero.
    for (int i = 0;i < board.size(); i++)
    {
        for (int j = 0;j < board[i].size(); j++){
            // Check for invalid values before checking if there is unsolved cells
            invalid_values(board[i][j]);

            if (unsolved_cell(board[i][j])){
                // TODO: search for solution
                cout << "Unsolved cell: ";
                cout << i;
                cout << " ";
                cout << j;
                cout << "\n";
                return true;
            }
        }
    }
    return false;
}