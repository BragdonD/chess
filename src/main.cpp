#include <iostream>
#include "core/FEN.hpp"
#include "core/board.hpp"

int main(int, char**){
    FEN fen("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1");
    Board& board = Board::get_instance();
    board.load_from_FEN(fen);
    std::cout << board << std::endl;
    return 0;
}
