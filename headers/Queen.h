//
// Created by cedri on 4/15/2025.
//

#ifndef QUEEN_H
#define QUEEN_H
#include "Piece.h"

class Queen : public Piece {
public:
    void displayMoves(Piece* board[8][8], int fromRow, int fromCol);
};

#endif //QUEEN_H
