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
        std::cout << "Piece: " << " (" << colorStr << ") at (" << row << ", " << col << ")" << std::endl;
    }

    private:
        // Private data members
        PieceColor pcolor_identifier; // Color of the piece
        int row; // Row (rank) of the piece's position
        int col; // Column (file) of the piece's position
};


// Main function
int main() {
    return 0;
}

//Added new position variables and their respective retrun functions