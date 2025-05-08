//
// Created by cedri on 4/15/2025.
//

#ifndef ROOK_H
#define ROOK_H
#include "Piece.h"

class Rook : public Piece {
public:
    void displayMoves(Piece* board[8][8], int fromRow, int fromCol);
};

#endif //ROOK_H
