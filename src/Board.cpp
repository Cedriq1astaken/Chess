//
// Created by cedri on 2/28/2025.
//

#include "iostream"
#include "Piece.cpp"
##include <vector>

using namespace std;

char board[8][8];

//Print board
//Sergio Orama
void printBoard(const std::vector<std::vector<char>>& board) {
    for (const auto& row : board) {
        for (char square : row) {
            std::cout << square << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    std::vector<std::vector<char>> chessBoard = {
        {'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'},
        {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
        {'.', '.', '.', '.', '.', '.', '.', '.'},
        {'.', '.', '.', '.', '.', '.', '.', '.'},
        {'.', '.', '.', '.', '.', '.', '.', '.'},
        {'.', '.', '.', '.', '.', '.', '.', '.'},
        {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
        {'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'}
    };

    printBoard(chessBoard);

    return 0;
}

//Move piece from one place to another


int main() {



    return 1;
}
