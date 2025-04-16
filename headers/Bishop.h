//
// Created by cedri on 4/15/2025.
//

#ifndef BISHOP_H
#define BISHOP_H
#include "Piece.h"

class Bishop : public Piece {
public:
    void displayMoves(Piece* board[8][8], int fromRow, int fromCol);
};

#endif //BISHOP_H
