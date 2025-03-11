//
// Created by cedri on 2/25/2025.
//


//Code below written by Alessandro Perea on 3/11/2025
#include <iostream>
#include <array>
#include <optional> // this for std::optional and std::nullopt

// Define the PieceColor enum
enum class PieceColor {
    White,
    Black,
    None
};

// Define the Piece class
class Piece {
public:
    // A constructor to initialize the piece with a color and type
    Piece(PieceColor color, const std::string& type)
        : pcolor_identifier(color), type(type) {}

    // Getter for the piece color
    PieceColor getPColor() const {
        return pcolor_identifier;
    }

    // Getter for the piece type
    std::string getType() const {
        return type;
    }

    // Function to display piece information
    void display() const {
        std::string colorStr = (pcolor_identifier == PieceColor::White) ? "White" : "Black";
        std::cout << "Piece: " << type << " (" << colorStr << ")" << std::endl;
    }

private:
    // Private data members
    PieceColor pcolor_identifier; // Color of the piece
    std::string type; // Type of the piece (for example "Pawn" or "Rook")
};

// Defining the Chessboard class
class Chessboard {
public:
    // Constructor to initialize the chessboard
    Chessboard() {
        // Loop through the board and initialize all squares as empty
        for (int i = 0; i < 8; ++i) {
            for (int j = 0; j < 8; ++j) {
                board[i][j] = std::nullopt; // std::nullopt represents an empty square
            }
        }

        // Placing a white pawn at position (0, 0)
        board[0][0] = Piece(PieceColor::White, "Pawn");
    }

    // Function to display the chessboard
    void display() const {
        for (int i = 0; i < 8; ++i) {
            for (int j = 0; j < 8; ++j) {
                if (board[i][j].has_value()) { // Check if the square has a piece
                    board[i][j]->display(); // Displaying the piece
                } else {
                    std::cout << "Empty square at (" << i << ", " << j << ")" << std::endl;
                }
            }
        }
    }

private:
    // 8x8 chessboard using std::array and std::optional
    std::array<std::array<std::optional<Piece>, 8>, 8> board;
};

// Main function
int main() {
    Chessboard board; // Creating da chessboard
    board.display(); // Displaying da chessboard
    return 0;
}
