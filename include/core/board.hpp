#ifndef BOARD_HPP
#define BOARD_HPP

#include <array>
#include <memory>
#include <string>
#include "./piece.hpp"
#include "./FEN.hpp"

typedef std::string str;

class Board {
public:
    ~Board();
    static Board& get_instance();
    void load_from_FEN(FEN& fen);
    std::unique_ptr<Piece>& get_piece(int row, int col);
    bool insert_piece(std::unique_ptr<Piece> piece, int row, int col);
    friend std::ostream& operator<<(std::ostream& os, Board& board);
private:
    Board();
    std::array<std::unique_ptr<Piece>, 8 * 8> m_tiles;
};

#endif // BOARD_HPP