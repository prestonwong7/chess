#include "pawn.hpp"

Pawn::Pawn(Color color) : Piece(color) {}

bool Pawn::isLegalMove(int startX, int startY, int endX, int endY, const std::unique_ptr<Piece> board[8][8]) const {
    int direction = (getColor() == Color::WHITE) ? 1 : -1; // White moves up, Black moves down
    int startRow = (getColor() == Color::WHITE) ? 1 : 6; // Starting row for pawns
    // Check if the move is within bounds
    if (endX < 0 || endX >= 8 || endY < 0 || endY >= 8) {
        return false; // Out of bounds
    }

    // Move forward by one square
    if (startX == endX && endY == startY + direction && !board[endY][endX]) {
        return true;
    }

    // Move forward by two squares from the starting position
    if (startX == endX && endY == startY + 2 * direction && startY == startRow && !board[endY][endX] && !board[startY + direction][startX]) {
        return true;
    }

    // Capture diagonally
    if (abs(startX - endX) == 1 && endY == startY + direction && board[endY][endX] && board[endY][endX]->getColor() != getColor()) {
        return true;
    }

    return false; // Illegal move
}

char Pawn::symbol() const {
    return (getColor() == Color::WHITE) ? 'P' : 'p'; // Uppercase for white, lowercase for black
}