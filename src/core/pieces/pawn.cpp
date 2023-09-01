#include "core/piece.hpp"
#include "core/pieces/pawn.hpp"

Pawn::Pawn(Color _color, int _row, int _col) : 
Piece(_color, _row, _col)
{}

Pawn::~Pawn() {}

bool Pawn::moove(int col, int row) {
    if (!this->is_valid_moove(col, row)) {
        return false;
    }
    this->m_row = row;
    this->m_col = col;
    return true;
}

char Pawn::get_char() {
    if (this->m_color == Color::White) {
        return 'P';
    } 
    return 'p';
}

bool Pawn::is_valid_moove(int col, int row) {
    return false; // TODO: Needs the Board Singleton class
}