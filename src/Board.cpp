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
#include <Knight.h>

using namespace std;

Board::Board() {
    for (int i = 0; i < 8; ++i)
        for (int j = 0; j < 8; ++j)
            board[i][j] = nullptr;

    // set up white pieces
    board[0][0] = new Rook();    board[0][0]->symbol = 'r'; board[0][0]->color = 'B';
    board[0][1] = new Knight();  board[0][1]->symbol = 'n'; board[0][1]->color = 'B';
    board[0][2] = new Bishop();  board[0][2]->symbol = 'b'; board[0][2]->color = 'B';
    board[0][3] = new Queen();   board[0][3]->symbol = 'q'; board[0][3]->color = 'B';
    board[0][4] = new King();    board[0][4]->symbol = 'k'; board[0][4]->color = 'B';
    board[0][5] = new Bishop();  board[0][5]->symbol = 'b'; board[0][5]->color = 'B';
    board[0][6] = new Knight();  board[0][6]->symbol = 'n'; board[0][6]->color = 'B';
    board[0][7] = new Rook();    board[0][7]->symbol = 'r'; board[0][7]->color = 'B';
    // set up black pawns
    for (int i = 0; i < 8; ++i) {
        board[1][i] = new Pawn();
        board[1][i]->symbol = 'p';
        board[1][i]->color = 'B';
    }
    // set up black pieces
    board[7][0] = new Rook();    board[7][0]->symbol = 'R'; board[7][0]->color = 'W';
    board[7][1] = new Knight();  board[7][1]->symbol = 'N'; board[7][1]->color = 'W';
    board[7][2] = new Bishop();  board[7][2]->symbol = 'B'; board[7][2]->color = 'W';
    board[7][3] = new Queen();   board[7][3]->symbol = 'Q'; board[7][3]->color = 'W';
    board[7][4] = new King();    board[7][4]->symbol = 'K'; board[7][4]->color = 'W';
    board[7][5] = new Bishop();  board[7][5]->symbol = 'B'; board[7][5]->color = 'W';
    board[7][6] = new Knight();  board[7][6]->symbol = 'N'; board[7][6]->color = 'W';
    board[7][7] = new Rook();    board[7][7]->symbol = 'R'; board[7][7]->color = 'W';
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

void Board::movePieceHelper(int fromRow, int fromCol, int toRow, int toCol) {

    // capturing, if destination has a piece.
    if (board[fromRow][fromCol]->moveSet[toRow][toCol]) {
        if ((board[fromRow][fromCol]->symbol == 'K' || board[fromRow][fromCol]->symbol == 'k') &&\
            !board[fromRow][fromCol]->hasMoved && \
            board[fromRow][fromCol]->moveSet[toRow][toCol] &&\
            toCol == 6) {
                castle(board[fromRow][fromCol]->color, true);
            }
        else if ((board[fromRow][fromCol]->symbol == 'K' || board[fromRow][fromCol]->symbol == 'k') &&\
            !board[fromRow][fromCol]->hasMoved &&\
            board[fromRow][fromCol]->moveSet[toRow][toCol] &&\
            toCol == 2) {
                castle(board[fromRow][fromCol]->color, false);
            }
        else {
            movePiece(fromRow, fromCol, toRow, toCol);
        }
        board[toRow][toCol]->hasMoved = true;
    }
    else {
        cout << "Invalid move!" << endl;
    }
}

void Board::movePiece(int fromRow, int fromCol, int toRow, int toCol) {
    Piece* piece = board[fromRow][fromCol];

    if (piece != nullptr) {
        piece->hasMoved = true; // mark the piece as moved
    }

    // capturing, if destination has a piece.
    if (board[toRow][toCol] != nullptr) {
        delete board[toRow][toCol];
    }

    board[toRow][toCol] = piece;
    board[fromRow][fromCol] = nullptr;
}

void Board::displayMoves(int row, int col) {
    if (board[row][col] != nullptr) {

        board[row][col]->displayMoves(board, row, col);
        if (board[row][col]->symbol == 'K' || board[row][col]->symbol == 'k') {
            cout << canCastle(board[row][col]->color, true);
            cout << canCastle(board[row][col]->color, false);
            if (canCastle(board[row][col]->color, true)) {
                board[row][col]->moveSet[((board[row][col]->color == 'W')? 7 : 0)][6] = 1;
            }
            if (canCastle(board[row][col]->color, false)) {
                board[row][col]->moveSet[((board[row][col]->color == 'W')? 7 : 0)][2] = 1;
            }
        }

    }
    else
        std::cout << "There is not piece here\n";

}

string Board::getFEN(){
    string fen = "";
    for (int row = 0; row < 8; ++row){
        int emptyCount = 0;

        for (int col = 0; col < 8; ++col){
            if (board[row][col] == nullptr){
                ++emptyCount;
            }
            else{
                if (emptyCount > 0){
                    fen += to_string(emptyCount);
                    emptyCount = 0;
                }
                fen += board[row][col]->symbol;
            }
        }
        if (emptyCount > 0){
            fen += to_string(emptyCount);
        }
        if (row < 7){
            fen += "/";
        }
    }
    return fen;
}

bool Board::isKingUnderAttack(int row, int col, char kingColor){
    for (int r = 0; r < 8; ++r){
        for (int c = 0; c < 8; ++c){
            if (board[r][c] != nullptr && board[r][c]->color != kingColor){
                // Check if the piece can attack the king's position
                board[r][c]->displayMoves(board, r, c);
                if (board[r][c]->moveSet[row][col] == 1)
                    return true; // King is under attack
            }
        }
    }
    return false; // King is not under attack
}

bool Board::isKingInCheck(char kingColor) {
    // Check if the king is in check and intialize the kingRow and kingCol variables
    int kingRow = -1, kingCol = -1;
    for (int row = 0; row < 8; ++row) {
        for (int col = 0; col < 8; ++col) {
            if (board[row][col] != nullptr && (board[row][col]->symbol == 'k' || board[row][col]->symbol == 'K') && board[row][col]->color == kingColor) {
                kingRow = row;
                kingCol = col;
                break;
            }
        }
    }
    if (kingRow == -1) {
        return false;
    }
    // Now check if any enemy piece can attack the king
    for (int row = 0; row < 8; ++row) {
        for (int col = 0; col < 8; ++col) {
            if (board[row][col] != nullptr && board[row][col]->color != kingColor && board[row][col]->symbol != 'k' && board[row][col]->symbol != 'K') {
                // Using the movesBoard to check if the piece can attack the king
                board[row][col]->displayMoves(board, row, col);

                // Check if the king's position is marked as a valid move (capturable)
                if (board[row][col]->moveSet[kingRow][kingCol] == 1) {
                    return true;
                }
            }
        }
    }
    return false; // If no enemy piece can attack the king, king is not in check
};

bool Board::canCastle(char kingColor, bool isKingSide){
    int row = (kingColor == 'W') ? 7 : 0;
    int kingCol = 4;
    int rookCol = (isKingSide) ? 7 : 0;

    if (board[row][kingCol] == nullptr || board[row][rookCol] == nullptr)
        return false; // No king or rook to castle with
    if (board[row][kingCol]->hasMoved || board[row][rookCol]->hasMoved)
        return false;

    if (toupper(board[row][kingCol]->symbol) != 'K' || toupper(board[row][rookCol]->symbol) != 'R')
        return false;


    int startCol = min(kingCol, rookCol) + 1;
    int endCol = max(kingCol, rookCol) - 1;
    for (int col = startCol; col <= endCol; ++col){
        if (board[row][col] != nullptr)
            return false; // There is a piece in the way
    }

    for (int col = min(kingCol, rookCol); col <= max(kingCol, rookCol); ++col){
        if (isKingUnderAttack(row, col, kingColor))
            return false; // King is in check after castling
    }
    return true; // Castling can be done
}

void Board::castle(char kingColor, bool isKingSide){
    if (!canCastle(kingColor, isKingSide)){
        cout << "Castling not possible" << endl;
        return;
    }

    int row = (kingColor == 'W') ? 7 : 0;
    int kingCol = 4;
    int rookCol = (isKingSide) ? 7 : 0;
    int newKingCol = (isKingSide) ? 6 : 2;
    int newRookCol = (isKingSide) ? 5 : 3;

    // Move the king
    movePiece(row, kingCol, row, newKingCol);

    // Move the rook
    movePiece(row, rookCol, row, newRookCol);

    cout << "Castling successful" << endl;
}