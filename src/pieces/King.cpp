//
// Created by Sergio
//
#include "iostream"
#include "King.h"
#include "Piece.h"


void King::displayMoves(Piece* board[8][8], int fromRow, int fromCol) {
    //this creates a char board to store and display the valid moves
    char movesBoard[8][8];
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            Piece::moveSet[i][j] = 0;
        }
    }
    for (int row = 0; row < 8; ++row) {
        for (int col = 0; col < 8; ++col) {
            if (board[row][col])
                movesBoard[row][col] = board[row][col]->symbol ;
            else
                movesBoard[row][col] = '0';
        }
    }
    // indexes for king all 8 possible adjacent directions
    int directions[8][2] = {
        {-1, -1},
        {-1, 0},
        {-1, +1},
        {0, -1},
        {0, +1},
        {+1, -1},
        {+1, 0},
        {+1, +1}
    };
    // loop through all possible king moves
    for (int i = 0; i < 8; ++i) {
        int newRow = fromRow + directions[i][0];
        int newCol = fromCol + directions[i][1];


        if (newRow >= 0 && newRow < 8 && newCol >= 0 && newCol < 8) { // check if the new position is inside the board
            if (board[newRow][newCol] == nullptr) {
                Piece::moveSet[newRow][newCol] = 1;
                movesBoard[newRow][newCol] = '1'; // empty square
            }
            else if (board[newRow][newCol]->color != board[fromRow][fromCol]->color) {
                Piece::moveSet[newRow][newCol] = 1;
                movesBoard[newRow][newCol] = 'X'; // capturable enemy
            }
        }
    }

}


