//
// Created by cedri on 3/30/2025.
//

#ifndef BOARD_H
#define BOARD_H

#include <Piece.h>

class Board {
public:
    Piece* board[8][8]; // this sets each of the 64 squares of the chess board to empty
    Board();
    // this displays the board checking each square for a piece and printing the symbol of said piece
    void displayBoard();
    //this moves a piece from one square to another, deleting the piece in the destination square if it is occupied
    void movePiece( int fromRow, int fromCol, int toRow, int toCol);
    //this displays the valid moves of a piece calling the method on said piece
    void displayMoves(int row, int col);
};


#endif //BOARD_H
