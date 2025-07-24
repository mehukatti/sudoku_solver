#include <vector>
#include <iostream>
#include <bits/stdc++.h>
using std::cout;


class SudokuSolver
{
public:
    std::vector<std::vector<std::vector<int>>> board;
    bool eventfull_solution_loop = false;
    void invalid_values(std::vector<int>& cell_values){
        // Check for invalid values in a cell
        if (cell_values.size()==0){
            throw ("Cell should not be empty. Internal error.");
        }
        
        for (int cell_value : cell_values)
        {
            if (cell_value< 0) {
                throw ("Cell contains negative values");
            }
            else if (cell_value>9) {
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

    bool value_in_vector(std::vector<int>& values, int value){
        auto it = find(values.begin(), values.end(), value);
        if (it!=values.end()){
            return true;
        } else {
            return false;
        }
    }

    void remove_from_vector_by_value(std::vector<int>& vec, int value){
        // remove from vector by given value
        if (!(value_in_vector(vec, value))){
            return;
        }
        int index_to_remove;
        for (int i = 0;i < vec.size(); i++){
            if (value==vec[i]){
                index_to_remove = i;
                break;
            }
        }
        vec.erase(vec.begin() + index_to_remove);
        return;
    }

    void area_solutions_by_exlusion(std::vector<int>& possible_numbers, int row_index, int column_index){
        if (unsolved_cell(board[row_index][column_index])){
            return;
        }
        int used_value = board[row_index][column_index][0];
        if (value_in_vector(possible_numbers, used_value)){
            remove_from_vector_by_value(possible_numbers, used_value);
        }
    }

    void solutions_by_exlusion(int row_index, int column_index){
        // Add all possible solutions to the board's zeros
        
        // Required values:
        std::vector<int> possible_numbers;
        possible_numbers = {1,2,3,4,5,6,7,8,9};

        // Remove numbers that already are in the ROW:
        for (int col = 0;col < 9; col++){
            area_solutions_by_exlusion(possible_numbers, row_index, col);
        }

        // Remove numbers that already are in the COLUMN:
        for (int row = 0;row < 9; row++){
            area_solutions_by_exlusion(possible_numbers, row, column_index);
        }

        // Remove numbers that already are in the BOX:
        int box_start_row;
        box_start_row = row_index / 3 * 3;
        int box_start_column;
        box_start_column = column_index / 3 * 3;

        for (int row = box_start_row;row < box_start_row+3; row++){
            for (int col = box_start_column;col < box_start_column+3; col++){
                area_solutions_by_exlusion(possible_numbers, row, col);
            }
        }

        if (possible_numbers.size()==1){
            board[row_index][column_index] = possible_numbers;
            eventfull_solution_loop = true;
        }

        return;
    }


    bool unsolved_board(){
        // Check if the board is still unsolved
        for (std::vector<std::vector<int>> row : board){
            for (std::vector<int> cell_values : row){
                if (unsolved_cell(cell_values)){
                    return true;
                }
            }
        }
        return false;
    }

    bool solve(){
        // Check if all the cells have one and only one solution that is not zero.
        bool stuck = false;
        while (unsolved_board() && !stuck) {
            eventfull_solution_loop = false;
            for (int row_index = 0;row_index < 9; row_index++)
            {
                for (int column_index = 0;column_index < 9; column_index++){
                    // Check for invalid values before checking if there is unsolved cells
                    invalid_values(board[row_index][column_index]);
                    if (!(unsolved_cell(board[row_index][column_index]))){
                        continue;
                    }

                    solutions_by_exlusion(row_index, column_index);
                }
            }
            if (eventfull_solution_loop){
                stuck = false;
            } else {
                stuck = true;
            }
        }
        if (stuck){
            cout << "\nSudoku stuck.\n";
            return false;
        } else {
            cout << "\nSudoku solved.\n";
            return true;
        }
    }
};