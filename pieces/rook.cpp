#include "rook.hpp"

Rook::Rook(Color color) : Piece(color) {}

bool Rook::isLegalMove(int startX, int startY, int endX, int endY, const std::unique_ptr<Piece> board[8][8]) const {
    // Check if the move is within bounds
    if (endX < 0 || endX >= 8 || endY < 0 || endY >= 8) {
        return false; // Out of bounds
    }

    // Rooks can move horizontally or vertically any number of squares
    if (startX == endX) { // Vertical move
        int step = (endY > startY) ? 1 : -1;
        for (int y = startY + step; y != endY; y += step) {
            if (board[y][startX]) {
                return false; // Blocked by another piece
            }
        }
        return true;
    } else if (startY == endY) { // Horizontal move
        int step = (endX > startX) ? 1 : -1;
        for (int x = startX + step; x != endX; x += step) {
            if (board[startY][x]) {
                return false; // Blocked by another piece
            }
        }
        return true;
    }

    return false; // Illegal move
}

char Rook::symbol() const {
    return (getColor() == Color::WHITE) ? 'R' : 'r'; // Uppercase for white, lowercase for black
}