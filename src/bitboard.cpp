#include "bitboard.hpp"

#include <complex>

using namespace jester;

std::ostream& jester::operator<<(std::ostream& os, Square const& square)
{
    std::string const square_strings[64] = {
        "A1", "B1", "C1", "D1", "E1", "F1", "G1", "H1",
        "A2", "B2", "C2", "D2", "E2", "F2", "G2", "H2",
        "A3", "B3", "C3", "D3", "E3", "F3", "G3", "H3",
        "A4", "B4", "C4", "D4", "E4", "F4", "G4", "H4",
        "A5", "B5", "C5", "D5", "E5", "F5", "G5", "H5",
        "A6", "B6", "C6", "D6", "E6", "F6", "G6", "H6",
        "A7", "B7", "C7", "D7", "E7", "F7", "G7", "H7",
        "A8", "B8", "C8", "D8", "E8", "F8", "G8", "H8",
    };

    os << square_strings[square];
    return os;
}

u64 jester::to_u64(Square const square)
{
    return 1ULL << square;
}

Square jester::to_square(u64 const bit64)
{
    return static_cast<Square>(std::log(bit64) / std::log(2));
}

bitboard::bitboard()
    : board(0ULL)
{
}

bitboard::bitboard(u64 const board)
    : board(board)
{
}

u64 bitboard::get_board() const
{
    return this->board;
}

bitboard bitboard::operator&(bitboard const bitboard) const
{
    return jester::bitboard(this->get_board() & bitboard.get_board());
}

bitboard bitboard::operator|(bitboard const bitboard) const
{
    return jester::bitboard(this->get_board() | bitboard.get_board());
}

bitboard bitboard::operator^(bitboard const bitboard) const
{
    return jester::bitboard(this->get_board() ^ bitboard.get_board());
}

int bitboard::get_bit(Square const square) const
{
    return this->board & to_u64(square) ? 1 : 0;
}

void bitboard::flip_bit(Square const square)
{
    this->board ^= to_u64(square);
}

void bitboard::print(std::ostream& os) const
{
    os << "        Bitboard         " << std::endl;
    os << "=========================" << std::endl;

    for (int rank = 0; rank < 8; rank++)
    {
        for (int file = 0; file < 8; file++)
        {
            auto const square = static_cast<Square>((8 * rank + file) ^ 56);

            if (!file)
            {
                os << 8 - rank << " ";
            }

            os << " " << this->get_bit(square) << " ";
        }

        os << std::endl;
    }

    os << "   a  b  c  d  e  f  g  h" << std::endl;
}

std::ostream& jester::operator<<(std::ostream& os, bitboard const& bitboard)
{
    bitboard.print(os);
    return os;
}
