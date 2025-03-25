//
// Created by cedri on 2/25/2025.
//

//Code below written by Alessandro Perea on 3/11/2025, modified by Cedric on 2/25/2025
#include <iostream>
#include "Piece.h"

using namespace std;

// Private data members
char color; // Color of the piece
int moveSet[8][8];


Piece::Piece(){
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            moveSet[i][j] = 0;
        }
    }
}

char Piece::getColor() const {    // Getter for the piece color
    return color;
}

void Piece::display() const {     // Function to display piece information
    string colorStr = (color == 'w') ? "White" : "Black";
    cout << "Piece: " << " (" << colorStr << ")" << endl;

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            cout << moveSet[i][j] << " | ";
        }
        cout << endl;
    }
}

