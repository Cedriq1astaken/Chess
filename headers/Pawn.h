 
// Created by cedri on 3/24/2025.
//

#ifndef PAWN_H
#define PAWN_H
#include "Piece.h"

class Pawn: public Piece{
public:
    bool moved; //Has the pawn moved once?
    void displayMoves(Piece* board[8][8], int fromRow, int fromCol);
};

#endif //PAWN_H
