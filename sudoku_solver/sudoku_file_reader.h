#include <fstream>
#include <iostream>
#include <string.h>
#include <regex>
#include <vector>

using namespace std;


std::vector<std::vector<int>> integers_to_vector(std::string& str)
{
    // Arguments: string of numbers separated by spaces and special charachers
    // Return vector of those numbers as integers
    std::vector<std::vector<int>> numbers;

    std::regex integer_regex("[[:digit:]]+");
    auto words_begin = std::sregex_iterator(str.begin(), str.end(), integer_regex);
    auto words_end = std::sregex_iterator();

    for (std::sregex_iterator i = words_begin; i != words_end; ++i) {
        std::smatch match = *i;
        int match_int = stoi(match.str()); // stoi = string to integer
        std::vector<int> number;
        number.push_back(match_int);
        numbers.push_back(number);
    }
    return numbers;
}


std::vector<std::vector<std::vector<int>>> read_sudoku(std::string& sudoku_path)
{
    // the board is a three layer vector.
    // 1st vector is the row
    // 2nd vector is the column
    // 3rd vector is vector containing the solution in the cell. There should only be one, which is not zero, after all the solving algorithms are done
    cout << "Reading the file:"<< sudoku_path << "\n";

    //variables for saving the file contents into a single string
    std::vector<std::vector<std::vector<int>>> board;
    
    std::string line;

    std::ifstream sudoku_file(sudoku_path);
    cout << "reading the lines" << "\n";

    // Create a vector of vectors containing numbers from the given sudoku file
    while( getline(sudoku_file, line) ){
        // There is rows of dashes to separate boxes horizontally. Ignore those.
        if(isdigit(line[0])){
            std::vector<std::vector<int>> row_numbers = integers_to_vector(line);
            board.push_back(row_numbers);
        }
    }
    sudoku_file.close();
    return board;
}