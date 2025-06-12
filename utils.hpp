#pragma once
#include <string>
#include <cctype>

inline bool algebraicToCoords(const std::string& pos, int& row, int& col) {
    if (pos.length() != 2) {
        return false; // Invalid position format
    }
    char file = tolower(pos[0]);
    char rank = pos[1];

    if (file < 'a' || file > 'h' || rank < '1' || rank > '8') {
        return false; // Out of bounds
    }

    col = file - 'a'; // Convert 'a'-'h' to 0-7
    row = rank - '1'; // Convert '1'-'8' to 0-7
    return true;
}