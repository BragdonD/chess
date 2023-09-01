#include <memory>
#include "core/piece.hpp"
#include "core/pieces/pawn.hpp"
#include "core/pieceFactory.hpp"

PieceFactory::PieceFactory() {

}

PieceFactory::~PieceFactory() {

}

std::unique_ptr<Piece> PieceFactory::create_piece(char pawnChar, int row, int col) {
    Color color = Color::White;
    if (pawnChar < 'A') {
        color = Color::Black;
    }
    if(pawnChar == 'p' || pawnChar == 'P') {
        return std::make_unique<Pawn>(Pawn(color, row, col));
    }
    return nullptr;
}

PieceFactory& PieceFactory::get_instance() {
    static PieceFactory piece_factory;
    return piece_factory;
}

    