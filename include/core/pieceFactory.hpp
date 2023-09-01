#ifndef PIECEFACTORY_HPP
#define PIECEFACTORY_HPP

#include <memory>
#include "./piece.hpp"
#include "./pieces/pawn.hpp"

class PieceFactory {
public:
    ~PieceFactory();
    std::unique_ptr<Piece> create_piece(char pawnChar, int row, int col);
    static PieceFactory& get_instance();
private:
    PieceFactory();
};

#endif // PIECEFACTORY_HPP