//
// Created by Sergio
//
#include "iostream"
#include "Queen.h"
#include "Piece.h"

void Queen::displayMoves(Piece* board[8][8], int fromRow, int fromCol) {
    //this creates a char board to store and display the valid moves

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            Piece::moveSet[i][j] = 0;
        }
    }

    char movesBoard[8][8];
    for (int row = 0; row < 8; ++row) {
        for (int col = 0; col < 8; ++col) {
            if (board[row][col])
                movesBoard[row][col] = board[row][col]->symbol ;
            else
                movesBoard[row][col] = '.';
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
            break; // friendly piece or invalid move
        }
    }
    //this checks diagonal right moves going up
    for (int i = fromRow - 1, j = fromCol + 1; i >= 0 && j < 8; --i, ++j) {
        if (board[i][j] == nullptr) {
            Piece::moveSet[i][j] = 1;
            movesBoard[i][j] = '1'; // mark valid empty square with a "1"
        }
        else if (board[i][j]->color != board[fromRow][fromCol]->color) {
            Piece::moveSet[i][j] = 1;
            movesBoard[i][j] = 'X'; // mark capturable enemy with an "X"
            break;
        }
        else {
            break; // friendly piece or invalid move
        }
    }
    //this checks diagonal left moves going up
    for (int i = fromRow - 1, j = fromCol - 1; i >= 0 && j >= 0; --i, --j) {
        if (board[i][j] == nullptr) {
            Piece::moveSet[i][j] = 1;
            movesBoard[i][j] = '1'; // mark valid empty square with a "1"
        }
        else if (board[i][j]->color != board[fromRow][fromCol]->color) {
            Piece::moveSet[i][j] = 1;
            movesBoard[i][j] = 'X'; // mark capturable enemy with an "X"
            break;
        }
        else {
            break; // friendly piece or invalid move
        }
    }
    //this checks diagonal right moves going down
    for (int i = fromRow + 1, j = fromCol + 1; i < 8 && j < 8; ++i, ++j) {
        if (board[i][j] == nullptr) {
            Piece::moveSet[i][j] = 1;
            movesBoard[i][j] = '1'; // mark valid empty square with a "1"
        }
        else if (board[i][j]->color != board[fromRow][fromCol]->color) {
            Piece::moveSet[i][j] = 1;
            movesBoard[i][j] = 'X'; // mark capturable enemy with an "X"
            break;
        }
        else {
            break; // friendly piece or invalid move
        }
    }
    //this checks diagonal left moves going down
    for (int i = fromRow + 1, j = fromCol - 1; i < 8 && j >= 0; ++i, --j) {
        if (board[i][j] == nullptr) {
            Piece::moveSet[i][j] = 1;
            movesBoard[i][j] = '1'; // mark valid empty square with a "1"
        }
        else if (board[i][j]->color != board[fromRow][fromCol]->color) {
            Piece::moveSet[i][j] = 1;
            movesBoard[i][j] = 'X'; // mark capturable enemy with an "X"
            break;
        }
        else {
            break; // friendly piece or invalid move
        }
    }

    //this prints the char movesBoard with the valid moves

}
