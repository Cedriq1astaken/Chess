//
// Created by cedri on 3/3/2025.
//


#include "iostream"
#include "Bishop.h"
#include "Piece.h"
#include "Knight.h"


void Knight::displayMoves(Piece* board[8][8], int fromRow, int fromCol) {
    //this creates a char board to store and display the valid moves
    char movesBoard[8][8];
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            Piece::moveSet[i][j] = 0;
        }
    }
    for (int row = 0; row < 8; ++row) {
        for (int col = 0; col < 8; ++col) {
            if (board[row][col]) {
                movesBoard[row][col] = board[row][col]->symbol ;
            }
            else {
                movesBoard[row][col] = '.';
            }
        }
    }
    int knightMoves[8][2] = { // all possible knight moves, knights have 8 possible "L" moves
        {-2, -1},
        {-2, +1},
        {-1, -2},
        {-1, +2},
        {+1, -2},
        {+1, +2},
        {+2, -1},
        {+2, +1}
    };
    for (int i = 0; i < 8; i++) { // loop through all possible knight moves
        int row = fromRow + knightMoves[i][0];
        int col = fromCol + knightMoves[i][1];
        if (row >= 0 && row < 8 && col >= 0 && col < 8) { // check if the move is within the board
            if (board[row][col] == nullptr) { // check if the square is empty
                Piece::moveSet[row][col] = 1;
                movesBoard[row][col] = '1'; // mark valid empty square with a "1"
            }
            else if (board[row][col]->color != board[fromRow][fromCol]->color) { //check if square is occupied by an enemy piece
                Piece::moveSet[row][col] = 1;
                movesBoard[row][col] = 'X'; // mark capturable enemy with an "X"
            }
        }
    }
    //this prints the char movesBoard with the valid moves

}
