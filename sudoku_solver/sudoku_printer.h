#include <vector>
#include <iostream>
using std::cout;

void print(std::vector<std::vector<std::vector<int>>>& board)
{
    cout << "\nPrinting sudoku: \n\n";
    for (int i = 0;i < board.size(); i++)
    {

        // print the row
        for (int j = 0;j < board[i].size(); j++){

            if (board[i][j].size()>1){
                // While attempting to solve the board, all possible solutions are marked into each cell until all but one number can be excluded.
                // To print properly, replace all such incompletely solved cells with zero vector.
                cout << " "; // Print space instead of empty
            }

            if (board[i][j][0]==0){
                cout << " "; // Print space instead of empty
            } else {
                cout << board[i][j][0];
            }
            cout << " ";
            // Every 3rd time print |
            if( j == 2 or j == 5){
                cout << "| ";
            }
        }
        cout << "\n"; // Next line after row

        // print horizontal lines every third line
        if( i == 2 or i == 5){
            cout << "- - - - - - - - - - -\n";
        }
    }
    cout << "\n\n";
    return;
}