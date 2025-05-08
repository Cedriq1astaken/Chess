//
// Created by cedri on 3/23/2025.
//
#ifndef HEADER_H
#define HEADER_H

#include "iostream"

using namespace std;

class Piece {

public:
    char color; // 'B' for black, 'W' for white
    char symbol; // 'r', 'n', 'b', 'q', 'k', 'p' for black pieces  'R', 'N', 'B', 'Q', 'K', 'P' for white pieces
    int moveSet[8][8];
    bool hasMoved; // this is used to check if the piece has moved, so it can be used to check if the pawn can move 2 spaces or not

    Piece(); // virtual destructor for proper cleanup, so it not only cleans up the base class but also derived classes
    char getColor();
    char getSymbol();
    virtual void displayMoves(Piece* board[8][8], int fromRow, int fromCol) = 0;// function to display possible moves
};



#endif //HEADER_H
