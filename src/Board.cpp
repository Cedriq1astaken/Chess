//
// Created by cedri on 2/28/2025.
//

#include "iostream"
#include "Piece.h"
#include "Rook.h"
#include "Bishop.h"
#include "Queen.h"
#include "Board.h"

#include <King.h>
#include <Pawn.h>

using namespace std;

Piece* board[8][8] = {nullptr};

Board::Board() {
    for (int i = 0; i < 8; ++i)
        for (int j = 0; j < 8; ++j)
            board[i][j] = nullptr;

    // set up black pieces
    board[0][0] = new Rook();    board[0][0]->symbol = 'r'; board[0][0]->color = 'B';
    board[0][7] = new Rook();    board[0][7]->symbol = 'r'; board[0][7]->color = 'B';
    board[0][2] = new Bishop();  board[0][2]->symbol = 'b'; board[0][2]->color = 'B';
    board[0][5] = new Bishop();  board[0][5]->symbol = 'b'; board[0][5]->color = 'B';
    board[0][4] = new Queen(); board[0][4]->symbol = 'q'; board[0][5]->color = 'B';
    // // set up black pawns
    // for (int i = 0; i < 8; ++i) {
    //     board[1][i] = new Pawn();
    //     board[1][i]->symbol = 'p';
    //     board[1][i]->color = 'B';
    // }

    // set up white pieces
    board[7][0] = new Rook();    board[7][0]->symbol = 'R'; board[7][0]->color = 'W';
    board[7][7] = new Rook();    board[7][7]->symbol = 'R'; board[7][7]->color = 'W';
    board[7][2] = new Bishop();  board[7][2]->symbol = 'B'; board[7][2]->color = 'W';
    board[7][5] = new Bishop();  board[7][5]->symbol = 'B'; board[7][5]->color = 'W';
    board[7][3] = new King();  board[7][3]->symbol = 'K'; board[7][3]->color = 'W';

    //set up white pawns
    for (int i = 0; i < 8; ++i) {
        board[6][i] = new Pawn();
        board[6][i]->symbol = 'P';
        board[6][i]->color = 'W';
    }




}

void Board::displayBoard() {
    for (int row = 0; row < 8; ++row) {
        for (int col = 0; col < 8; ++col) {
            if (board[row][col])
                std::cout << board[row][col]->symbol << "  ";
            else
                std::cout << ".  ";
        }
        std::cout << '\n';
    }
}

void Board::movePiece( int fromRow, int fromCol, int toRow, int toCol) {
    Piece* piece = board[fromRow][fromCol];

    displayMoves(fromRow, fromCol);
    // capturing, if destination has a piece.
    if (board[fromRow][fromCol]->moveSet[toRow][toCol]) {
        if (board[toRow][toCol] != nullptr ) {
            delete board[toRow][toCol];
        }

        board[toRow][toCol] = piece;
        board[fromRow][fromCol] = nullptr;
    }
    else {
        cout << "Invalid move!" << endl;
    }
}

void Board::displayMoves(int row, int col) {
    if (board[row][col] != nullptr) {

        board[row][col]->displayMoves(board, row, col);
    }
    else
        std::cout << "There is not piece here\n";
}