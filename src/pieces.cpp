#include "pieces.hpp"

jester::pieces::pieces()
{
    for (int i = 0; i < 8; i++)
    {
        this->piece_bitboards_[i] = bitboard(starting_bitboards[i]);
    }
}

jester::bitboard jester::pieces::operator[](unsigned int const index) const
{
    return this->piece_bitboards_[index];
}

jester::bitboard& jester::pieces::operator[](unsigned int const index)
{
    return this->piece_bitboards_[index];
}

jester::bitboard jester::pieces::get_all_pieces() const
{
    return this->piece_bitboards_[White] | this->piece_bitboards_[Black];
}

jester::bitboard jester::pieces::get_white_pieces() const
{
    return this->piece_bitboards_[White];
}

jester::bitboard jester::pieces::get_black_pieces() const
{
    return this->piece_bitboards_[Black];
}

jester::bitboard jester::pieces::get_white_pawns() const
{
    return this->piece_bitboards_[White] & this->piece_bitboards_[Pawn];
}

jester::bitboard jester::pieces::get_white_knights() const
{
    return this->piece_bitboards_[White] & this->piece_bitboards_[Knight];
}

jester::bitboard jester::pieces::get_white_bishops() const
{
    return this->piece_bitboards_[White] & this->piece_bitboards_[Bishop];
}

jester::bitboard jester::pieces::get_white_rooks() const
{
    return this->piece_bitboards_[White] & this->piece_bitboards_[Rook];
}

jester::bitboard jester::pieces::get_white_queen() const
{
    return this->piece_bitboards_[White] & this->piece_bitboards_[Queen];
}

jester::bitboard jester::pieces::get_white_king() const
{
    return this->piece_bitboards_[White] & this->piece_bitboards_[King];
}

jester::bitboard jester::pieces::get_black_pawns() const
{
    return this->piece_bitboards_[Black] & this->piece_bitboards_[Pawn];
}

jester::bitboard jester::pieces::get_black_knights() const
{
    return this->piece_bitboards_[Black] & this->piece_bitboards_[Knight];
}

jester::bitboard jester::pieces::get_black_bishops() const
{
    return this->piece_bitboards_[Black] & this->piece_bitboards_[Bishop];
}

jester::bitboard jester::pieces::get_black_rooks() const
{
    return this->piece_bitboards_[Black] & this->piece_bitboards_[Rook];
}

jester::bitboard jester::pieces::get_black_queen() const
{
    return this->piece_bitboards_[Black] & this->piece_bitboards_[Queen];
}

jester::bitboard jester::pieces::get_black_king() const
{
    return this->piece_bitboards_[Black] & this->piece_bitboards_[King];
}
