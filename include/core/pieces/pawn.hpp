#ifndef PAWN_HPP
#define PAWN_HPP

#include "../piece.hpp"

class Pawn: public Piece {
public:
    Pawn(Color _color, int _row, int _col);
    ~Pawn();
    bool moove(int col, int row);
    char get_char();
private:
    bool is_valid_moove(int col, int row);
};

#endif // PAWN_HPP