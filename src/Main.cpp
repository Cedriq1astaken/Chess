//
// Created by cedri on 2/20/2025.
//

#include "iostream"
#include "Piece.h"
#include "Pawn.h"

using namespace std;





int main(){
    char board[8][8] = {
        {'0', '0', '0', '0', '0', '0', '0', '0'},
        {'0', '0', '0', '0', '0', '0', '0', '0'},
        {'0', '0', '0', '0', '0', '0', '0', '0'},
        {'0', '0', '0', '0', '0', '0', '0', '0'},
        {'0', '0', '0', '0', '0', '0', '0', '0'},
        {'0', '0', '0', '0', '0', '0', '0', '0'},
        {'0', '0', '0', '0', '0', '0', '0', '0'},
        {'0', '0', '0', '0', '0', '0', '0', '0'}
    };
    Pawn p('w');

    p.checkAvailable(board, 6, 7);

    Pawn p2('b');

    p2.checkAvailable(board, 1, 7);
    p2.display();
    p.display();

    return 0;
};


