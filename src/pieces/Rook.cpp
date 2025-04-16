//
// Created by Sergio
//
#include "iostream"
#include "Rook.h"
#include "Piece.h"

void Rook::displayMoves(Piece* board[8][8], int fromRow, int fromCol){
    //this creates a char board to store and display the valid moves
    char movesBoard[8][8];
    for (int row = 0; row < 8; ++row) {
        for (int col = 0; col < 8; ++col) {
            if (board[row][col])
                movesBoard[row][col] = board[row][col]->symbol ;
            else
                movesBoard[row][col] = ' ';
        }
    }
    //this checks the vertical moves going up
    for (int i = fromRow - 1; i >= 0; --i) {
        if (board[i][fromCol] == nullptr) {
            Piece::moveSet[i][fromCol] = 1;
            movesBoard[i][fromCol] = '1'; // mark valid empty square with a "1"
        }
        else if (board[i][fromCol]->color != board[fromRow][fromCol]->color) {
            Piece::moveSet[i][fromCol] = 1;
            movesBoard[i][fromCol] = 'X'; // mark capturable enemy with a "X"
            break;
        }
        else {
            Piece::moveSet[i][fromCol] = 0;

            break; // friendly piece or invalid move
        }
    }
    //this checks the vertical moves going down
    for (int i = fromRow + 1; i <= 7; ++i) {

        if (board[i][fromCol] == nullptr) {
            Piece::moveSet[i][fromCol] = 1;
            movesBoard[i][fromCol] = '1'; // mark valid empty square with a "1"
        }
        else if (board[i][fromCol]->color != board[fromRow][fromCol]->color) {

            Piece::moveSet[i][fromCol] = 1;
            movesBoard[i][fromCol] = 'X'; // mark capturable enemy with an "X"
            break;
        }
        else {
            Piece::moveSet[i][fromCol] = 0;
            break; // friendly piece or invalid move
        }
    }
    //this checks the horizontal moves going right
    for (int i = fromCol + 1; i <= 7; ++i) {
        if (board[fromRow][i] == nullptr) {
            Piece::moveSet[fromRow][i] = 1;
            movesBoard[fromRow][i] = '1'; // mark valid empty square with a "1"
        }
        else if (board[fromRow][i]->color != board[fromRow][fromCol]->color) {
            Piece::moveSet[fromRow][i] = 1;
            movesBoard[fromRow][i] = 'X'; // mark capturable enemy with an "X"
            break;
        }
        else {
            Piece::moveSet[i][fromCol] = 0;
            break; // friendly piece or invalid move
        }
    }
    //this checks the horizontal moves going left
    for (int i = fromCol - 1; i >= 0; --i) {
        if (board[fromRow][i] == nullptr) {
            Piece::moveSet[fromRow][i] = 1;
            movesBoard[fromRow][i] = '1'; // mark valid empty square with a "1"
        }
        else if (board[fromRow][i]->color != board[fromRow][fromCol]->color) {
            Piece::moveSet[fromRow][i] = 1;
            movesBoard[fromRow][i] = 'X'; // mark capturable enemy with an "X"
            break;
        }
        else {
            Piece::moveSet[i][fromCol] = 0;
            break; // friendly piece or invalid move
        }
    }
    // this prints the char movesBoard with the valid moves
    // this board looks different from the others. To make it consistent with the regular board layout,
    // replace this code with the one used in another piece.
    // If you want all the pieces to use this layout, copy this code and replace it in the other piece classes.
    for (int i = 0; i < 8; i++) {
        cout << "  +---+---+---+---+---+---+---+---+" << endl;
        cout << i + 1 << " | ";
        for (int j = 0; j < 8; j++) {
            cout << movesBoard[i][j] << " | ";
        }
        cout << std::endl;
    }
    cout << "  +---+---+---+---+---+---+---+---+" << endl;
    cout << "    a   b   c   d   e   f   g   h" << endl;
};