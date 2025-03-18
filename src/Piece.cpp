//
// Created by cedri on 2/25/2025.
//


//Code below written by Alessandro Perea on 3/11/2025
#include <iostream>
#include <array>
#include <optional>

// Define the PieceColor enum
enum class PieceColor {
    White,
    Black,
    None
};

// Define the Piece class
class Piece {

    // Getter for the piece color
    PieceColor getPColor() const {
        return pcolor_identifier;
    }

    // Getter for the piece type
    std::string getType() const {
        return type;
    }

    // Getter for the piece's row (rank)
    int getRow() const {
        return row;
    }

    // Getter for the piece's column (file)
    int getCol() const {
        return col;
    }

    // Setter for the piece's position
    void setPosition(int newRow, int newCol) {
        row = newRow;
        col = newCol;
    }

    // Function to display piece information
    void display() const {
        std::string colorStr = (pcolor_identifier == PieceColor::White) ? "White" : "Black";
        std::cout << "Piece: " << type << " (" << colorStr << ") at (" << row << ", " << col << ")" << std::endl;
    }

private:
    // Private data members
    PieceColor pcolor_identifier; // Color of the piece
    std::string type; // Type of chess piece (for example "Pawn" or "Rook")
    int row; // Row (rank) of the piece's position
    int col; // Column (file) of the piece's position
};

        // Place a white pawn at position (0, 0)
        board[0][0] = Piece(PieceColor::White, "Pawn", 0, 0);


    // Function to move da piece
    bool movePiece(int fromRow, int fromCol, int toRow, int toCol) {
        // Check if the source square has a piece
        if (!board[fromRow][fromCol].has_value()) {
            std::cout << "No piece at (" << fromRow << ", " << fromCol << ")" << std::endl;
            return false;
        }

        // Check if the destination square is empty
        if (board[toRow][toCol].has_value()) {
            std::cout << "Destination square (" << toRow << ", " << toCol << ") is occupied" << std::endl;
            return false;
        }

        // Move the piece
        board[toRow][toCol] = std::move(board[fromRow][fromCol]);
        board[fromRow][fromCol] = std::nullopt;

        // Update the piece's position
        board[toRow][toCol]->setPosition(toRow, toCol);

        std::cout << "Moved piece from (" << fromRow << ", " << fromCol << ") to (" << toRow << ", " << toCol << ")" << std::endl;
        return true;
    }


// Main function
int main() {
    Chessboard board; // Creating da chessboard
    board.display(); // Displaying the chessboard

    // Moving the white pawn from (0, 0) to (1, 0)
    board.movePiece(0, 0, 1, 0);

   

    return 0;
}

//Added new position variables and their respective retrun functions