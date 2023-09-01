#include <iostream>
#include <memory>
#include <stdexcept>
#include "core/board.hpp"
#include "core/FEN.hpp"
#include "core/pieceFactory.hpp"

Board::Board()
{
}

Board::~Board()
{
}

Board &Board::get_instance()
{
    static Board board;
    return board;
}

void Board::load_from_FEN(FEN &fen)
{
    if (!fen.is_valid())
    {
        throw std::invalid_argument("Can not instanciate the board with wrong FEN");
    }
    int row = 0;
    int col = -1; // To avoid repeating col++
    std::string &pieces_placement = fen.get_pieces_placement();
    PieceFactory &piece_factory = PieceFactory::get_instance();
    for (unsigned int i = 0; i < pieces_placement.size(); i++)
    {
        col++;
        if (pieces_placement[i] > '0' && pieces_placement[i] < '9')
        { // Number -> Space
            for (unsigned int j = 0; j < pieces_placement[i] - '0'; j++)
            {
                insert_piece(nullptr, row, col);
            }
        }
        else if (pieces_placement[i] == '/') // New Row
        {
            col = -1;
            row++;
        }
        else // A Piece
        {
            insert_piece(piece_factory.create_piece(pieces_placement[i], row, col), row, col);
        }
    }
}

std::unique_ptr<Piece>& Board::get_piece(int row, int col) {
    return this->m_tiles[row * 8 + col];
}

bool Board::insert_piece(std::unique_ptr<Piece> piece, int row, int col) {
    if (row < 8 && row >= 0 && col < 8 && col >= 0) {
        m_tiles[row * 8 + col] = std::move(piece);
        if (piece != nullptr) {
            piece->set_col(col);
            piece->set_row(row);
        }
        return true;
    }
    return false;
}

std::ostream& operator<<(std::ostream& os, Board& board) {
    for (unsigned int i = 0; i < 8; i++) {
        for (unsigned int j = 0; j < 8; j++) {
            const std::unique_ptr<Piece>& tile = board.get_piece(i, j);
            if (!tile) { // Empty
                os << ".";
            } else {
                os << tile->get_char();
            }
            os << " ";
        }
        os << "\n";
    }
    return os;
}