#ifndef FEN_HPP
#define FEN_HPP

#include <string>

/**
 * Notes to myself:
 * - A half-move, also known as a ply, represents one player's move. In chess, two half-moves make up a full move, one by each player.
 */

typedef std::string str;
class FEN
{
public:
    FEN(str _record);
    str& get_pieces_placement();
    void parse_raw_record();
    bool is_valid();
    friend std::ostream& operator<<(std::ostream& os, const FEN& fen);
    ~FEN();
    
private:
    str m_raw_record;
    str m_pieces_placement;
    str m_active_color;
    str m_castling_availability;
    str m_enpassant;
    str m_halfmove;
    str m_fullmove;
};

#endif // FEN_HPP
