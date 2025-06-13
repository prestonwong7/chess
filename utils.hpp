#pragma once
#include <string>
#include <cctype>
#include <iostream>

inline bool algebraicToCoords(const std::string& pos, int& row, int& col) {
    if (pos.length() != 2) {
        return false; // Invalid position format
    }
    char file = tolower(pos[0]);
    char rank = pos[1];

    if (file < 'a' || file > 'h' || rank < '1' || rank > '8') {
        return false; // Out of bounds
    }

    col = file - 'a'; // 'a' - 'a' is 0, 'b' - 'a' is 1, ..., 'h' - 'a' is 7
    row = 8 - (rank - '0'); // '1' = row 7, '2' = row 6, ..., '8' = row 0
    std::cout << "Converted " << pos << " to coordinates: (" << row << ", " << col << ")\n";
    return true;
}