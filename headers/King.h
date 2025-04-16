//
// Created by cedri on 4/15/2025.
//

#ifndef KING_H
#define KING_H
#include "Piece.h"

class King : public Piece {
public:
    void displayMoves(Piece* board[8][8], int fromRow, int fromCol);
};

#endif //KING_H
