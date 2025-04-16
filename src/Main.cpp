//
// Created by cedri on 2/20/2025.
//

#include "iostream"
#include "Board.h"

using namespace std;

int main(){
    Board *board = new Board();


    board->displayMoves(0, 4);
    board->movePiece(0,4, 4, 4);
    board->displayMoves(4, 4);



    return 1;
};


