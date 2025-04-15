#include <iostream>
using namespace std;

class Piece {
public:
    char color; // 'B' for black, 'W' for white
    char symbol; // 'r', 'n', 'b', 'q', 'k', 'p' for black pieces  'R', 'N', 'B', 'Q', 'K', 'P' for white pieces
    virtual void displayMoves(Piece* board[8][8], int fromRow, int fromCol) = 0;// function to display possible moves
    virtual ~Piece() {} // virtual destructor for proper cleanup, so it not only cleans up the base class but also derived classes
};

class Rook : public Piece {
public:
    char getColor() {
        return color;
    }
    char getSymbol() {
        return symbol;
    }
    void displayMoves(Piece* board[8][8], int fromRow, int fromCol) override {
        //this creates a char board to store and display the valid moves
        char movesBoard[8][8];
        for (int row = 0; row < 8; ++row) {
            for (int col = 0; col < 8; ++col) {
                if (board[row][col])
                    movesBoard[row][col] = board[row][col]->symbol ;
                else
                    movesBoard[row][col] = ' ';
            }
        }
        //this checks the vertical moves going up
        for (int i = fromRow - 1; i >= 0; --i) {
            if (board[i][fromCol] == nullptr) {
                movesBoard[i][fromCol] = '1'; // mark valid empty square with a "1"
            }
            else if (board[i][fromCol]->color != board[fromRow][fromCol]->color) {
                movesBoard[i][fromCol] = 'X'; // mark capturable enemy with a "X"
                break;
            }
            else {
                break; // friendly piece or invalid move
            }
        }
        //this checks the vertical moves going down
        for (int i = fromRow + 1; i <= 7; ++i) {
            if (board[i][fromCol] == nullptr) {
                movesBoard[i][fromCol] = '1'; // mark valid empty square with a "1"
            }
            else if (board[i][fromCol]->color != board[fromRow][fromCol]->color) {
                movesBoard[i][fromCol] = 'X'; // mark capturable enemy with an "X"
                break;
            }
            else {
                break; // friendly piece or invalid move
            }
        }
        //this checks the horizontal moves going right
        for (int i = fromCol + 1; i <= 7; ++i) {
            if (board[fromRow][i] == nullptr) {
                movesBoard[fromRow][i] = '1'; // mark valid empty square with a "1"
            }
            else if (board[fromRow][i]->color != board[fromRow][fromCol]->color) {
                movesBoard[fromRow][i] = 'X'; // mark capturable enemy with an "X"
                break;
            }
            else {
                break; // friendly piece or invalid move
            }
        }
        //this checks the horizontal moves going left
        for (int i = fromCol - 1; i >= 0; --i) {
            if (board[fromRow][i] == nullptr) {
                movesBoard[fromRow][i] = '1'; // mark valid empty square with a "1"
            }
            else if (board[fromRow][i]->color != board[fromRow][fromCol]->color) {
                movesBoard[fromRow][i] = 'X'; // mark capturable enemy with an "X"
                break;
            }
            else {
                break; // friendly piece or invalid move
            }
        }
        // this prints the char movesBoard with the valid moves
        // this board looks different from the others. To make it consistent with the regular board layout,
        // replace this code with the one used in another piece.
        // If you want all the pieces to use this layout, copy this code and replace it in the other piece classes.
        for (int i = 0; i < 8; i++) {
            cout << "  +---+---+---+---+---+---+---+---+" << endl;
            cout << i + 1 << " | ";
            for (int j = 0; j < 8; j++) {
                cout << movesBoard[i][j] << " | ";
            }
            cout << std::endl;
        }
        cout << "  +---+---+---+---+---+---+---+---+" << endl;
        cout << "    a   b   c   d   e   f   g   h" << endl;
    }
};

class Knight : public Piece {
public:
    char getColor() { // not in use yet
        return color;
    }
    char getSymbol() { // not in use yet
        return symbol;
    }
    void displayMoves(Piece* board[8][8], int fromRow, int fromCol) override {
        //this creates a char board to store and display the valid moves
        char movesBoard[8][8];
        for (int row = 0; row < 8; ++row) {
            for (int col = 0; col < 8; ++col) {
                if (board[row][col])
                    movesBoard[row][col] = board[row][col]->symbol ;
                else
                    movesBoard[row][col] = '.';
            }
        }
        int knightMoves[8][2] = { // all possible knight moves, knights have 8 possible "L" moves
            {-2, -1},
            {-2, +1},
            {-1, -2},
            {-1, +2},
            {+1, -2},
            {+1, +2},
            {+2, -1},
            {+2, +1}
        };
        for (int i = 0; i < 8; i++) { // loop through all possible knight moves
            int row = fromRow + knightMoves[i][0];
            int col = fromCol + knightMoves[i][1];
            if (row >= 0 && row < 8 && col >= 0 && col < 8) { // check if the move is within the board
                if (board[row][col] == nullptr) { // check if the square is empty
                    movesBoard[row][col] = '1'; // mark valid empty square with a "1"
                }
                else if (board[row][col]->color != board[fromRow][fromCol]->color) { //check if square is occupied by an enemy piece
                    movesBoard[row][col] = 'X'; // mark capturable enemy with an "X"
                }
            }
        }
        //this prints the char movesBoard with the valid moves
        std::cout << '\n';
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                cout << movesBoard[i][j] << "  ";
            }
            cout << std::endl;
        }
    }
};

class Bishop : public Piece {
public:
    char getColor() { // not in use yet
        return color;
    }
    char getSymbol() { // not in use yet
        return symbol;
    }
        void displayMoves(Piece* board[8][8], int fromRow, int fromCol) override {
        //this creates a char board to store and display the valid moves
        char movesBoard[8][8];
        for (int row = 0; row < 8; ++row) {
            for (int col = 0; col < 8; ++col) {
                if (board[row][col])
                    movesBoard[row][col] = board[row][col]->symbol ;
                else
                    movesBoard[row][col] = '.';
            }
        }
        //this checks diagonal right moves going up
        for (int i = fromRow - 1, j = fromCol + 1; i >= 0 && j < 8; --i, ++j) {
            if (board[i][j] == nullptr) {
                movesBoard[i][j] = '1'; // mark valid empty square with a "1"
            }
            else if (board[i][j]->color != board[fromRow][fromCol]->color) {
                movesBoard[i][j] = 'X'; // mark capturable enemy with an "X"
                break;
            }
            else {
                break; // friendly piece or invalid move
            }
        }
        //this checks diagonal left moves going up
        for (int i = fromRow - 1, j = fromCol - 1; i >= 0 && j < 8; --i, --j) {
            if (board[i][j] == nullptr) {
                movesBoard[i][j] = '1'; // mark valid empty square with a "1"
            }
            else if (board[i][j]->color != board[fromRow][fromCol]->color) {
                movesBoard[i][j] = 'X'; // mark capturable enemy with an "X"
                break;
            }
            else {
                break; // friendly piece or invalid move
            }
        }
        //this checks diagonal right moves going down
        for (int i = fromRow + 1, j = fromCol + 1; i >= 0 && j < 8; ++i, ++j) {
            if (board[i][j] == nullptr) {
                movesBoard[i][j] = '1'; // mark valid empty square with a "1"
            }
            else if (board[i][j]->color != board[fromRow][fromCol]->color) {
                movesBoard[i][j] = 'X'; // mark capturable enemy with an "X"
                break;
            }
            else {
                break; // friendly piece or invalid move
            }
        }
        //this checks diagonal left moves going down
        for (int i = fromRow + 1, j = fromCol - 1; i >= 0 && j < 8; ++i, --j) {
            if (board[i][j] == nullptr) {
                movesBoard[i][j] = '1'; // mark valid empty square with a "1"
            }
            else if (board[i][j]->color != board[fromRow][fromCol]->color) {
                movesBoard[i][j] = 'X'; // mark capturable enemy with an "X"
                break;
            }
            else {
                break; // friendly piece or invalid move
            }
        }
        //this prints the char movesBoard with the valid moves
        std::cout << '\n';
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                cout << movesBoard[i][j] << "  ";
            }
            cout << std::endl;
        }
    }
};

class King : public Piece {
public:
    char getColor() { // not in use yet
        return color;
    }
    char getSymbol() { // not in use yet
        return symbol;
    }
     void displayMoves(Piece* board[8][8], int fromRow, int fromCol) override {
        //this creates a char board to store and display the valid moves
        char movesBoard[8][8];
        for (int row = 0; row < 8; ++row) {
            for (int col = 0; col < 8; ++col) {
                if (board[row][col])
                    movesBoard[row][col] = board[row][col]->symbol ;
                else
                    movesBoard[row][col] = '.';
            }
        }
        // indexes for king all 8 possible adjacent directions
        int directions[8][2] = {
            {-1, -1},
            {-1, 0},
            {-1, +1},
            {0, -1},
            {0, +1},
            {+1, -1},
            {+1, 0},
            {+1, +1}
        };
        // loop through all possible king moves
        for (int i = 0; i < 8; ++i) {
            int newRow = fromRow + directions[i][0];
            int newCol = fromCol + directions[i][1];


            if (newRow >= 0 && newRow < 8 && newCol >= 0 && newCol < 8) { // check if the new position is inside the board
                if (board[newRow][newCol] == nullptr) {
                    movesBoard[newRow][newCol] = '1'; // empty square
                }
                else if (board[newRow][newCol]->color != board[fromRow][fromCol]->color) {
                    movesBoard[newRow][newCol] = 'X'; // capturable enemy
                }
            }
        }
        //this prints the char movesBoard with the valid moves
        std::cout << '\n';
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                cout << movesBoard[i][j] << "  ";
            }
            cout << std::endl;
        }
    }
};

class Queen : public Piece {
public:
    char getColor() { // not in use yet
        return color;
    }
    char getSymbol() { // not in use yet
        return symbol;
    }
    void displayMoves(Piece* board[8][8], int fromRow, int fromCol) override {
        //this creates a char board to store and display the valid moves
        char movesBoard[8][8];
        for (int row = 0; row < 8; ++row) {
            for (int col = 0; col < 8; ++col) {
                if (board[row][col])
                    movesBoard[row][col] = board[row][col]->symbol ;
                else
                    movesBoard[row][col] = '.';
            }
        }
        //this checks the vertical moves going up
        for (int i = fromRow - 1; i >= 0; --i) {
            if (board[i][fromCol] == nullptr) {
                movesBoard[i][fromCol] = '1'; // mark valid empty square with a "1"
            }
            else if (board[i][fromCol]->color != board[fromRow][fromCol]->color) {
                movesBoard[i][fromCol] = 'X'; // mark capturable enemy with a "X"
                break;
            }
            else {
                break; // friendly piece or invalid move
            }
        }
        //this checks the vertical moves going down
        for (int i = fromRow + 1; i <= 7; ++i) {
            if (board[i][fromCol] == nullptr) {
                movesBoard[i][fromCol] = '1'; // mark valid empty square with a "1"
            }
            else if (board[i][fromCol]->color != board[fromRow][fromCol]->color) {
                movesBoard[i][fromCol] = 'X'; // mark capturable enemy with an "X"
                break;
            }
            else {
                break; // friendly piece or invalid move
            }
        }
        //this checks the horizontal moves going right
        for (int i = fromCol + 1; i <= 7; ++i) {
            if (board[fromRow][i] == nullptr) {
                movesBoard[fromRow][i] = '1'; // mark valid empty square with a "1"
            }
            else if (board[fromRow][i]->color != board[fromRow][fromCol]->color) {
                movesBoard[fromRow][i] = 'X'; // mark capturable enemy with an "X"
                break;
            }
            else {
                break; // friendly piece or invalid move
            }
        }
        //this checks the horizontal moves going left
        for (int i = fromCol - 1; i >= 0; --i) {
            if (board[fromRow][i] == nullptr) {
                movesBoard[fromRow][i] = '1'; // mark valid empty square with a "1"
            }
            else if (board[fromRow][i]->color != board[fromRow][fromCol]->color) {
                movesBoard[fromRow][i] = 'X'; // mark capturable enemy with an "X"
                break;
            }
            else {
                break; // friendly piece or invalid move
            }
        }
        //this checks diagonal right moves going up
        for (int i = fromRow - 1, j = fromCol + 1; i >= 0 && j < 8; --i, ++j) {
            if (board[i][j] == nullptr) {
                movesBoard[i][j] = '1'; // mark valid empty square with a "1"
            }
            else if (board[i][j]->color != board[fromRow][fromCol]->color) {
                movesBoard[i][j] = 'X'; // mark capturable enemy with an "X"
                break;
            }
            else {
                break; // friendly piece or invalid move
            }
        }
        //this checks diagonal left moves going up
        for (int i = fromRow - 1, j = fromCol - 1; i >= 0 && j < 8; --i, --j) {
            if (board[i][j] == nullptr) {
                movesBoard[i][j] = '1'; // mark valid empty square with a "1"
            }
            else if (board[i][j]->color != board[fromRow][fromCol]->color) {
                movesBoard[i][j] = 'X'; // mark capturable enemy with an "X"
                break;
            }
            else {
                break; // friendly piece or invalid move
            }
        }
        //this checks diagonal right moves going down
        for (int i = fromRow + 1, j = fromCol + 1; i >= 0 && j < 8; ++i, ++j) {
            if (board[i][j] == nullptr) {
                movesBoard[i][j] = '1'; // mark valid empty square with a "1"
            }
            else if (board[i][j]->color != board[fromRow][fromCol]->color) {
                movesBoard[i][j] = 'X'; // mark capturable enemy with an "X"
                break;
            }
            else {
                break; // friendly piece or invalid move
            }
        }
        //this checks diagonal left moves going down
        for (int i = fromRow + 1, j = fromCol - 1; i >= 0 && j < 8; ++i, --j) {
            if (board[i][j] == nullptr) {
                movesBoard[i][j] = '1'; // mark valid empty square with a "1"
            }
            else if (board[i][j]->color != board[fromRow][fromCol]->color) {
                movesBoard[i][j] = 'X'; // mark capturable enemy with an "X"
                break;
            }
            else {
                break; // friendly piece or invalid move
            }
        }

        //this prints the char movesBoard with the valid moves
        std::cout << '\n';
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                cout << movesBoard[i][j] << "  ";
            }
            cout << std::endl;
        }
    }
};

class Pawn : public Piece {
public:
    char getColor() { // not in use yet
        return color;
    }
    char getSymbol() { // not in use yet
        return symbol;
    }
    //this creates a char board to store and display the valid moves
    void displayMoves(Piece* board[8][8], int fromRow, int fromCol) override {
        char movesBoard[8][8];
        for (int row = 0; row < 8; ++row) {
            for (int col = 0; col < 8; ++col) {
                if (board[row][col])
                    movesBoard[row][col] = board[row][col]->symbol ;
                else
                    movesBoard[row][col] = '.';
            }
        }
        //this checks if the pawn is black or white
        if (board[fromRow][fromCol]->color == 'W') { //White pawn moves

            // 1 step forward
            if (fromRow - 1 >= 0 && // this checks if the pawn is not in the last row (will be modified later to add promoting rules)
                board[fromRow - 1][fromCol] == nullptr) //this checks if the square in front of the pawn is empty
                    movesBoard[fromRow - 1][fromCol] = '1'; // this marks the square in front of the pawn square with a "1"

            // 2 steps from white starting row (6)
            if (fromRow == 6 && //checks if the white pawn is the row 6, meaning it wasnt moved yet and can advance 2 spaces
                board[fromRow - 1][fromCol] == nullptr && //checks if the space in front of the pawn is empty
                board[fromRow - 2][fromCol] == nullptr) //checks if the second space in front of the pawn is empty
                    movesBoard[fromRow - 2][fromCol] = '1'; //marks second square with a "1"

            // capture diagonally to the left
            if (fromRow - 1 >= 0 &&
                fromCol - 1 >= 0 &&
                board[fromRow - 1][fromCol - 1] != nullptr &&
                board[fromRow - 1][fromCol - 1]->color != board[fromRow][fromCol]->color)

                movesBoard[fromRow - 1][fromCol - 1] = 'X';

            // capture diagonally to the right
            if (fromRow - 1 >= 0 &&
                fromCol + 1 < 8 &&
                board[fromRow - 1][fromCol + 1] != nullptr &&
                board[fromRow - 1][fromCol + 1]->color != board[fromRow][fromCol]->color)
                movesBoard[fromRow - 1][fromCol + 1] = 'X';
        }
        //this checks if the pawn is black or white
        if (board[fromRow][fromCol]->color == 'B') {
            //Black pawn moves
            //1 step forward
            if (fromRow + 1 <= 7 && // this checks if the pawn is not in the last row (will be modified later to add promoting rules)
                board[fromRow + 1][fromCol] == nullptr) //this checks if the square in front of the pawn is empty
                    movesBoard[fromRow + 1][fromCol] = '1'; // this marks the square in front of the pawn square with a "1"

            // 2 steps from white starting row (1)
            if (fromRow == 1 && //checks if the white pawn is the row 1, meaning it wasnt moved yet and can advance 2 spaces
                board[fromRow + 1][fromCol] == nullptr && //checks if the space in front of the pawn is empty
                board[fromRow + 2][fromCol] == nullptr) //checks if the second space in front of the pawn is empty
                    movesBoard[fromRow + 2][fromCol] = '1'; //marks second square with a "1"

            // capture diagonally to the left
            if (fromRow - 1 >= 0 &&
                fromCol - 1 >= 0 &&
                board[fromRow + 1][fromCol - 1] != nullptr &&
                board[fromRow + 1][fromCol - 1]->color != board[fromRow][fromCol]->color)
                movesBoard[fromRow + 1][fromCol - 1] = 'X';

            // capture diagonally to the right
            if (fromRow - 1 >= 0 &&
                fromCol + 1 < 8 &&
                board[fromRow + 1][fromCol + 1] != nullptr &&
                board[fromRow + 1][fromCol + 1]->color != board[fromRow][fromCol]->color)
                movesBoard[fromRow + 1][fromCol + 1] = 'X';
        }
        //this prints the char movesBoard with the valid moves
        std::cout << '\n';
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                cout << movesBoard[i][j] << "  ";
            }
            cout << std::endl;
        }
    }
};

class Board {
    public:
        Piece* board[8][8] = {nullptr}; // this sets each of the 64 squares of the chess board to empty

        Board() {
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
        // this displays the board checking each square for a piece and printing the symbol of said piece
        void displayBoard(){
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
        //this moves a piece from one square to another, deleting the piece in the destination square if it is occupied
        void movePiece( int fromRow, int fromCol, int toRow, int toCol) {
            Piece* piece = board[fromRow][fromCol];

            // capturing, if destination has a piece.
            if (board[toRow][toCol] != nullptr) {
                delete board[toRow][toCol];
            }

            board[toRow][toCol] = piece;
            board[fromRow][fromCol] = nullptr;
        }
        //this displays the valid moves of a piece calling the method on said piece
        void displayMoves(int row, int col) {
            if (board[row][col] != nullptr)
                board[row][col]->displayMoves(board, row, col);
            else
                std::cout << "There is not piece here\n";
        }
    };

int main() {
    Board board;

    cout << "Rook moves";
    cout << '\n';
    board.movePiece(7, 0, 3, 4);
    board.displayMoves(3, 4);
    board.movePiece(3, 4, 7, 0);
    cout << "\n";

    cout << "Knight moves";
    board.movePiece(7, 1, 3, 4);
    board.displayMoves(3, 4);
    board.movePiece(3, 4, 7, 1);
    cout << "\n";

    cout << "Bishop moves";
    board.movePiece(7, 2, 3, 4);
    board.displayMoves(3, 4);
    board.movePiece(3, 4, 7, 2);
    cout << "\n";

    cout << "Queen moves";
    board.movePiece(7, 3, 3, 4);
    board.displayMoves(3, 4);
    board.movePiece(3, 4, 7, 3);
    cout << "\n";

    cout << "King moves";
    board.movePiece(7, 4, 3, 4);
    board.displayMoves(3, 4);
    board.movePiece(3, 4, 7, 4);
    cout << "\n";

    cout << "White Pawn moves";
    board.movePiece(1, 2, 5, 2);
    board.movePiece(1, 4, 5, 4);
    cout << "\n";
    board.displayBoard();
    board.displayMoves(6, 3);
    board.movePiece(5, 4, 1, 4);
    board.movePiece(5, 2, 1, 2);
    cout << "\n";

    cout << "Black Pawn moves";
    cout << "\n";
    board.movePiece(6, 2, 2, 2);
    board.movePiece(6, 4, 2, 4);
    board.displayBoard();
    board.displayMoves(1, 3);
    cout << "\n";
}

/*
To do:

-Add safety checks to the code: Handle invalid user input.

- Check if the king is in check by emulating all other pieces' moves
  and verifying if the square where the king is located has an "X".

- Checkmate detection: check if the king is in check and has no valid
  moves to escape.

- Stalemate: check if the king is not in check but has no valid moves
  to escape.

- Pawn promotion: if the destination square is the last row (7 for black,
  0 for white), promote the pawn to the desired piece.

- Castling: check if the king and rook have not moved (add a boolean value
  to the Piece class that changes after their first move), check if the
  squares between them are empty, ensure the king is not in check, and
  verify that the squares the king moves through are not under attack.

- En passant: check if the opposing pawn moved two spaces in the last move,
  verify that the capturing pawn is on the correct row (4 for white, 3 for black),
  check if the adjacent square has the correct pawn, and validate that the square
  behind the moved pawn is empty.

- Draw detection:
  • Not enough material to checkmate (e.g., king vs king, king vs king + bishop,
    king vs king + knight, king vs king + two knights).
  • Threefold repetition: same board position repeated three times.
  • Fifty-move rule: no pawn movement or capture in the last 50 full moves.

- Add a function to check if a move is valid:
  • This function will check if the destination square has a "1" (valid move).
  • If the destination square has an "X", it will capture the piece.
*/

/*THIS IS THE CODE OUTPUT
 *
Rook moves
  +---+---+---+---+---+---+---+---+
1 | r | n | b | q | k | b | n | r |
  +---+---+---+---+---+---+---+---+
2 | p | p | p | p | X | p | p | p |
  +---+---+---+---+---+---+---+---+
3 |   |   |   |   | 1 |   |   |   |
  +---+---+---+---+---+---+---+---+
4 | 1 | 1 | 1 | 1 | R | 1 | 1 | 1 |
  +---+---+---+---+---+---+---+---+
5 |   |   |   |   | 1 |   |   |   |
  +---+---+---+---+---+---+---+---+
6 |   |   |   |   | 1 |   |   |   |
  +---+---+---+---+---+---+---+---+
7 | P | P | P | P | P | P | P | P |
  +---+---+---+---+---+---+---+---+
8 |   | N | B | Q | K | B | N | R |
  +---+---+---+---+---+---+---+---+
    a   b   c   d   e   f   g   h

Knight moves
r  n  b  q  k  b  n  r
p  p  p  X  p  X  p  p
.  .  1  .  .  .  1  .
.  .  .  .  N  .  .  .
.  .  1  .  .  .  1  .
.  .  .  1  .  1  .  .
P  P  P  P  P  P  P  P
R  .  B  Q  K  B  N  R

Bishop moves
r  n  b  q  k  b  n  r
p  p  X  p  p  p  X  p
.  .  .  1  .  1  .  .
.  .  .  .  B  .  .  .
.  .  .  1  .  1  .  .
.  .  1  .  .  .  1  .
P  P  P  P  P  P  P  P
R  N  .  Q  K  B  N  R

Queen moves
r  n  b  q  k  b  n  r
p  p  X  p  X  p  X  p
.  .  .  1  1  1  .  .
1  1  1  1  Q  1  1  1
.  .  .  1  1  1  .  .
.  .  1  .  1  .  1  .
P  P  P  P  P  P  P  P
R  N  B  .  K  B  N  R

King moves
r  n  b  q  k  b  n  r
p  p  p  p  p  p  p  p
.  .  .  1  1  1  .  .
.  .  .  1  K  1  .  .
.  .  .  1  1  1  .  .
.  .  .  .  .  .  .  .
P  P  P  P  P  P  P  P
R  N  B  Q  .  B  N  R

White Pawn moves
r  n  b  q  k  b  n  r
p  p  .  p  .  p  p  p
.  .  .  .  .  .  .  .
.  .  .  .  .  .  .  .
.  .  .  .  .  .  .  .
.  .  p  .  p  .  .  .
P  P  P  P  P  P  P  P
R  N  B  Q  K  B  N  R

r  n  b  q  k  b  n  r
p  p  .  p  .  p  p  p
.  .  .  .  .  .  .  .
.  .  .  .  .  .  .  .
.  .  .  1  .  .  .  .
.  .  X  1  X  .  .  .
P  P  P  P  P  P  P  P
R  N  B  Q  K  B  N  R

Black Pawn moves
r  n  b  q  k  b  n  r
p  p  p  p  p  p  p  p
.  .  P  .  P  .  .  .
.  .  .  .  .  .  .  .
.  .  .  .  .  .  .  .
.  .  .  .  .  .  .  .
P  P  .  P  .  P  P  P
R  N  B  Q  K  B  N  R

r  n  b  q  k  b  n  r
p  p  p  p  p  p  p  p
.  .  X  1  X  .  .  .
.  .  .  1  .  .  .  .
.  .  .  .  .  .  .  .
.  .  .  .  .  .  .  .
P  P  .  P  .  P  P  P
R  N  B  Q  K  B  N  R
