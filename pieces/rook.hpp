#pragma once
#include "../piece.hpp"

class Rook : public Piece {
    public:
        Rook(Color color);
        bool isLegalMove(int startX, int startY, int endX, int endY, const std::unique_ptr<Piece> board[8][8]) const override;
        char symbol() const override;
};