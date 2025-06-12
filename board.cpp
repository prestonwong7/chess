#include "board.hpp"
#include "pieces/pawn.hpp"
#include "pieces/rook.hpp"
#include "utils.hpp"
#include <iostream>

Board::Board() {
}

void Board::setup() {
    // Initialize the board with pawns
    for (int i = 0; i < 8; ++i) {
        squares[1][i] = std::make_unique<Pawn>(Color::WHITE);
        squares[6][i] = std::make_unique<Pawn>(Color::BLACK);
    }

    // Initialize the rooks
    squares[0][0] = std::make_unique<Rook>(Color::WHITE);
    squares[0][7] = std::make_unique<Rook>(Color::WHITE);
    squares[7][0] = std::make_unique<Rook>(Color::BLACK);
    squares[7][7] = std::make_unique<Rook>(Color::BLACK);
}

bool Board::move(const std::string& from, const std::string& to) {
    int startX, startY, endX, endY;

    if (!inBounds(startX, startY) || !inBounds(endX, endY)) {
        return false; // Out of bounds
    }

    auto& piece = squares[startY][startX];
    if (!piece) {
        return false; // No piece at the starting position
    }

    if (piece->isLegalMove(startX, startY, endX, endY, squares)) {
        squares[endY][endX] = std::move(piece);
        squares[startY][startX].reset(); // Remove the piece from the starting position
        return true;
    }
    
    return false; // Illegal move
}

void Board::print() const {
    for (int i = 0; i < 8; ++i) {
        std::cout << 8 - i << " "; // Print row numbers
        for (int j = 0; j < 8; ++j) {
            if (squares[i][j]) {
                std::cout << squares[i][j]->symbol() << " ";
            } else {
                std::cout << ". ";
            }
            std::cout << "\n";
        }
        std::cout << "  a b c d e f g h\n"; // Print column letters
    }
}