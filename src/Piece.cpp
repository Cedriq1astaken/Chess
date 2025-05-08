//
// Created by cedri on 2/25/2025.
//

//Code below written by Alessandro Perea on 3/11/2025, modified by Cedric on 2/25/2025
#include <iostream>
#include "Piece.h"

using namespace std;

// Private data members
char color; // 'B' for black, 'W' for white
char symbol; // 'r', 'n', 'b', 'q', 'k', 'p' for black pieces  'R', 'N', 'B', 'Q', 'K', 'P' for white pieces
int moveSet[8][8];
bool hasMoved; // this is used to check if the piece has moved, so it can be used to check if the pawn can move 2 spaces or not


Piece::Piece(){
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            moveSet[i][j] = 0;
        }
    }
}

char Piece::getColor() {    // Getter for the piece color
    return color;
}
char Piece::getSymbol() {    // Getter for the piece symbol
    return symbol;
}


