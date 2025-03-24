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


/*function that updates the moveSet array with a matrix/2d array with 1 and 0s, 0s representing the space where the piece cannot go and
 * 1s representing where the pieces can go. Function requieres the current board to determine
 */
void Pawn::checkAvailable(char board[8][8], int row, int col) {
    for (int i = 1; i <= 2; i++) {
        if (Piece::color == 'w') {
            if (board[row - i][col] == '0') {
                Pawn::moveSet[row - i][col] = 1;
            }
        }
        else {
            if (board[row + i][col] == '0') {
                Pawn::moveSet[row + i][col] = 1;
            }
        }
    }
}




