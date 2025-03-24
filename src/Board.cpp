//
// Created by cedri on 2/28/2025.
//

#include "iostream"
#include "Piece.cpp"

using namespace std;

char board[8][8];


//Sergio Orama 05/24 Modified to use regular array instead of vectors.
void printBoard(char board[8][8]) { 
    for (int row = 0; row < 8; row++) {
        for (int col = 0; col < 8; col++) {
            std::cout << board[row][col] << " ";
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

// Sergio Orama 05/24 I made the chessboard array again to use regular arrays instead of vectors.
int main() { 
    const int boardSize = 8;
    char chessBoard[boardSize][boardSize] = {
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
