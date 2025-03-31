//
// Created by cedri on 3/30/2025.
//

#ifndef BOARD_H
#define BOARD_H

class Board {
public:
    char board[8][8];

    Board();


    //Sergio Orama 05/24 Modified to use regular array instead of vectors.
    void printBoard();

    //Move piece from one place to another
    //Safwaan Arif (the chessboard array is not mine)

    void movePiece(int fromRow, int fromCol, int toRow, int toCol);
};


#endif //BOARD_H
