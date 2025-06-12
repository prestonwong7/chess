#pragma once
#include <memory>
#include <vector>
#include <string>
#include "piece.hpp"

class Board {
    public:
       Board();
       void setup();
       bool move(const std::string& from, const std::string& to);
       void print() const;
    private:
        std::unique_ptr<Piece> squares[8][8];
        bool inBounds(int x, int y) const;
};