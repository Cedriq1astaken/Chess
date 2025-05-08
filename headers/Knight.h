//
// Created by cedri on 5/3/2025.
//

#ifndef KNIGHT_H
#define KNIGHT_H
#include "Piece.h"

class Knight : public Piece {
public:
    void displayMoves(Piece* board[8][8], int fromRow, int fromCol);
};


#endif //KNIGHT_H
