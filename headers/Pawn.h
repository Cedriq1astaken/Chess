//
// Created by cedri on 3/24/2025.
//

#ifndef PAWN_H
#define PAWN_H
#include "Piece.h"

class Pawn: public Piece{
public:
    bool moved; //Has the pawn moved once?
    Pawn(char theColor);

    void checkAvailable(char board[8][8], int row, int col);

    int **getMoveSet();
};

#endif //PAWN_H
