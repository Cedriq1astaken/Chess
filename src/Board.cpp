//
// Created by cedri on 2/28/2025.
//

#include "iostream"
#include "Piece.cpp"

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

//Move piece from one place to another
//Safwaan Arif (the chessboard array is not mine)

void movePiece(char Board[8][8], int fromRow, int fromCol, int toRow, int toCol)
{
    board[toRow][toCol] = board[fromRow][fromCol];
    board[fromRow][fromCol] = '.';
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

    movePiece(chessBoard, 7, 0, 6, 2);
    std::cout << "\nAfter moving the piece:\n";
    printBoard(chessBoard);

    return 0;
}
