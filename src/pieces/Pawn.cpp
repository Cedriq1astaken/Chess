//
// Created by cedri on 2/25/2025.
//

#include "iostream"
#include "Pawn.h"
#include "Piece.h"

using namespace std;



//this creates a char board to store and display the valid moves
void Pawn::displayMoves(Piece* board[8][8], int fromRow, int fromCol) {
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
    //this checks if the pawn is black or white
    if (board[fromRow][fromCol]->color == 'W') { //White pawn moves

        // 1 step forward
        if (fromRow - 1 >= 0 && // this checks if the pawn is not in the last row (will be modified later to add promoting rules)
            board[fromRow - 1][fromCol] == nullptr){ //this checks if the square in front of the pawn is empty
                Piece::moveSet[fromRow - 1][fromCol] = 1;
                movesBoard[fromRow - 1][fromCol] = '1'; // this marks the square in front of the pawn square with a "1"
            }

        // 2 steps from white starting row (6)
        if (fromRow == 6 && //checks if the white pawn is the row 6, meaning it wasnt moved yet and can advance 2 spaces
            board[fromRow - 1][fromCol] == nullptr && //checks if the space in front of the pawn is empty
            board[fromRow - 2][fromCol] == nullptr){ //checks if the second space in front of the pawn is empty
                Piece::moveSet[fromRow - 2][fromCol] = 1;
                movesBoard[fromRow - 2][fromCol] = '1'; //marks second square with a "1"
            }

        // capture diagonally to the left
        if (fromRow - 1 >= 0 &&
            fromCol - 1 >= 0 &&
            board[fromRow - 1][fromCol - 1] != nullptr &&
            board[fromRow - 1][fromCol - 1]->color != board[fromRow][fromCol]->color) {
                Piece::moveSet[fromRow - 1][fromCol - 1] = 1;
                movesBoard[fromRow - 1][fromCol - 1] = 'X';
        }

        // capture diagonally to the right
        if (fromRow - 1 >= 0 &&
            fromCol + 1 < 8 &&
            board[fromRow - 1][fromCol + 1] != nullptr &&
            board[fromRow - 1][fromCol + 1]->color != board[fromRow][fromCol]->color) {
                Piece::moveSet[fromRow - 1][fromCol + 1] = 1;
                movesBoard[fromRow - 1][fromCol + 1] = 'X';
        }
    }
    //this checks if the pawn is black or white
    if (board[fromRow][fromCol]->color == 'B') {
        //Black pawn moves
        //1 step forward
        if (fromRow + 1 <= 7 && // this checks if the pawn is not in the last row (will be modified later to add promoting rules)
            board[fromRow + 1][fromCol] == nullptr){ //this checks if the square in front of the pawn is empty
                Piece::moveSet[fromRow + 1][fromCol ] = 1;
                movesBoard[fromRow + 1][fromCol] = '1'; // this marks the square in front of the pawn square with a "1"
            }

        // 2 steps from black starting row (1)
        if (fromRow == 1 && //checks if the black pawn is the row 1, meaning it wasnt moved yet and can advance 2 spaces
            board[fromRow + 1][fromCol] == nullptr && //checks if the space in front of the pawn is empty
            board[fromRow + 2][fromCol] == nullptr) {//checks if the second space in front of the pawn is empty
                Piece::moveSet[fromRow + 2][fromCol] = 1;
                movesBoard[fromRow + 2][fromCol] = '1'; //marks second square with a "1"
            }

        // capture diagonally to the left
        if (fromRow + 1 >= 0 &&
            fromCol - 1 >= 0 &&
            board[fromRow + 1][fromCol - 1] != nullptr &&
            board[fromRow + 1][fromCol - 1]->color != board[fromRow][fromCol]->color) {
                Piece::moveSet[fromRow + 1][fromCol - 1] = 1;
                movesBoard[fromRow + 1][fromCol - 1] = 'X';
        }

        // capture diagonally to the right
        if (fromRow + 1 >= 0 &&
            fromCol + 1 < 8 &&
            board[fromRow + 1][fromCol + 1] != nullptr &&
            board[fromRow + 1][fromCol + 1]->color != board[fromRow][fromCol]->color) {
                Piece::moveSet[fromRow + 1][fromCol + 1] = 1;
                movesBoard[fromRow + 1][fromCol + 1] = 'X';
            }
    }
    //this prints the char movesBoard with the valid moves


}





