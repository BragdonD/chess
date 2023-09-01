#include <stdexcept>
#include "core/piece.hpp"

Piece::Piece(Color _color, int _row, int _col) :
m_color(_color), m_row(_row), m_col(_col)
{}

Piece::~Piece() {}

bool Piece::set_row(int row) {
    if (row >= 0 && row < 8) {
        this->m_row = row;
        return true;
    }
    return false;
}

bool Piece::set_col(int col) {
    if (col >= 0 && col < 8) {
        this->m_col = col;
        return true;
    }
    return false;
}

bool Piece::moove(int col, int row) { 
    return false;
}

char Piece::get_char() {
    return ' ';
}

bool Piece::is_valid_moove(int col, int row) {
    return false;
}