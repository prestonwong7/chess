#pragma once
#include <string>
#include <memory>

enum class Color {
    WHITE,
    BLACK
};

class Piece {
    public:
        Piece(Color color) : color(color) {};
        virtual ~Piece() = default;

        Color getColor() const {
            return color;
        };

        // Virtual function to be overridden by derived classes
        virtual bool isLegalMove(int startX, int startY, int endX, int endY, const std::unique_ptr<Piece> board[8][8]) const = 0;
        virtual char symbol() const = 0;

    protected:
        Color color;
};