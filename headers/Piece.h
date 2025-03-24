//
// Created by cedri on 3/23/2025.
//
#ifndef HEADER_H
#define HEADER_H

#include "iostream"

using namespace std;

class Piece {

public:
    char color;
    int moveSet[8][8];
    Piece();
    char getColor() const;
    void display() const;

};



#endif //HEADER_H
