//
// Created by cedri on 2/25/2025.
//

#include "iostream"
#include "Pawn.h"
#include "Piece.h"

using namespace std;

bool moved = false;
Pawn::Pawn(char theColor){
    Piece::color = theColor;
}

void Pawn::checkAvailable(char board[8][8], int row, int col) {
    for (int i = 1; i <= 2; i++) {
        if (Piece::color == 'w') {
            if (board[row + i][col] == '0') {

            }
        }
        else {
            if (board[row + i][col] == '0') {

            }
        }
        if (!moved) {
            moved = true;
        }
    }
}




