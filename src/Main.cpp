//
// Created by cedri on 2/20/2025.
//

#include "iostream"
#include "Piece.h"
#include "Pawn.h"
#include "Board.h"

using namespace std;





int main(){
    Board b;

    b.printBoard();
    b.movePiece(1, 1, 3, 1);
    b.printBoard();

    return 0;
};


