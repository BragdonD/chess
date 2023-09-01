#ifndef PIECE_HPP
#define PIECE_HPP

enum Color {
    White,
    Black
};

class Piece {
public:
    Piece(Color _color, int _row, int _col);
    virtual ~Piece();
    bool set_row(int row);
    bool set_col(int col);
    virtual bool moove(int col, int row);
    virtual char get_char();
protected:
    Color m_color;
    int m_row;
    int m_col;
    virtual bool is_valid_moove(int col, int row);
};

#endif // PIECE_HPP