#include "pieces.hpp"

using namespace jester;

pieces::pieces()
{
    reset_pieces();
}

pieces::pieces(std::string fen)
{
}

bitboard pieces::get_all_pieces() const
{
    return this->piece_bitboards[Piece::White] | this->piece_bitboards[Piece::Black];
}

bitboard pieces::get_white_pieces() const
{
    return this->piece_bitboards[Piece::White];
}

bitboard pieces::get_black_pieces() const
{
    return this->piece_bitboards[Piece::Black];
}

bitboard pieces::get_white_pawns() const
{
    return this->piece_bitboards[Piece::White] & this->piece_bitboards[Piece::Pawn];
}

bitboard pieces::get_white_knights() const
{
    return this->piece_bitboards[Piece::White] & this->piece_bitboards[Piece::Knight];
}

bitboard pieces::get_white_bishops() const
{
    return this->piece_bitboards[Piece::White] & this->piece_bitboards[Piece::Bishop];
}

bitboard pieces::get_white_rooks() const
{
    return this->piece_bitboards[Piece::White] & this->piece_bitboards[Piece::Rook];
}

bitboard pieces::get_white_queen() const
{
    return this->piece_bitboards[Piece::White] & this->piece_bitboards[Piece::Queen];
}

bitboard pieces::get_white_king() const
{
    return this->piece_bitboards[Piece::White] & this->piece_bitboards[Piece::King];
}

bitboard pieces::get_black_pawns() const
{
    return this->piece_bitboards[Piece::Black] & this->piece_bitboards[Piece::Pawn];
}

bitboard pieces::get_black_knights() const
{
    return this->piece_bitboards[Piece::Black] & this->piece_bitboards[Piece::Knight];
}

bitboard pieces::get_black_bishops() const
{
    return this->piece_bitboards[Piece::Black] & this->piece_bitboards[Piece::Bishop];
}

bitboard pieces::get_black_rooks() const
{
    return this->piece_bitboards[Piece::Black] & this->piece_bitboards[Piece::Rook];
}

bitboard pieces::get_black_queen() const
{
    return this->piece_bitboards[Piece::Black] & this->piece_bitboards[Piece::Queen];
}

bitboard pieces::get_black_king() const
{
    return this->piece_bitboards[Piece::Black] & this->piece_bitboards[Piece::King];
}

void pieces::reset_pieces()
{
    this->piece_bitboards[Piece::White] = bitboard(Rank::Rank1 | Rank::Rank2);
    this->piece_bitboards[Piece::Black] = bitboard(Rank::Rank7 | Rank::Rank8);
    this->piece_bitboards[Piece::Pawn] = bitboard(Rank::Rank2 | Rank::Rank7);
    this->piece_bitboards[Piece::Knight] = bitboard(
        to_u64(Square::b1) | to_u64(Square::g1) | to_u64(Square::b8) | to_u64(Square::g8)
    );
    this->piece_bitboards[Piece::Bishop] = bitboard(
        to_u64(Square::c1) | to_u64(Square::f1) | to_u64(Square::c8) | to_u64(Square::f8)
    );
    this->piece_bitboards[Piece::Rook] = bitboard(
        to_u64(Square::a1) | to_u64(Square::h8) | to_u64(Square::a8) | to_u64(Square::h8)
    );
    this->piece_bitboards[Piece::Queen] = bitboard(to_u64(Square::d1) | to_u64(Square::d8));
    this->piece_bitboards[Piece::King] = bitboard(to_u64(Square::e1) | to_u64(Square::e8));
}
