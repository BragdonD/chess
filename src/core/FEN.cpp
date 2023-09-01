#include <vector>
#include <sstream>
#include <string>
#include <stdexcept>
#include "core/board.hpp"
#include "core/FEN.hpp"

FEN::FEN(str _record) {
    this->m_raw_record = _record;
    this->parse_raw_record();
}

str& FEN::get_pieces_placement() {
    return m_pieces_placement;
}

void FEN::parse_raw_record() {
   std::vector<str> record_parts;

    if (this->m_raw_record.size() == 0 || !is_valid()) {
        throw std::invalid_argument("invalide FEN");
    }

    str buffer;
    std::istringstream iss(m_raw_record);
    while (getline(iss, buffer, ' ')) {
        record_parts.push_back(buffer);
    }

    if (record_parts.size() != 6) {
        throw std::runtime_error("Error while extracting FEN parts");
    }

    this->m_pieces_placement = record_parts[0];
    this->m_active_color = record_parts[1];
    this->m_castling_availability = record_parts[2];
    this->m_enpassant = record_parts[3];
    this->m_halfmove = record_parts[4];
    this->m_fullmove = record_parts[5]; 
}

bool FEN::is_valid() {
    int part = 0;
    for (unsigned int i = 0; i < m_raw_record.size(); i++) {
        if (m_raw_record[i] == ' ') {
            part ++;
        }
    }

    return part == 5;
}

FEN::~FEN() {

}

std::ostream& operator<<(std::ostream& os, const FEN& fen) {
    os << "Raw: " << fen.m_raw_record << "\n";
    os << "Pieces Placement: " << fen.m_pieces_placement << "\n";
    os << "Active Color: " << fen.m_active_color << "\n";
    os << "Castling Availability: " << fen.m_castling_availability << "\n";
    os << "Enpassant: " << fen.m_enpassant << "\n";
    os << "HalfMove: " << fen.m_halfmove << "\n";
    os << "FullMove: " << fen.m_fullmove << "\n";
    return os;
}