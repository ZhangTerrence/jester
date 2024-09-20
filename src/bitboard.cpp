#include "bitboard.hpp"

#include <complex>

std::ostream& jester::operator<<(std::ostream& os, jester::Square const& square)
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

jester::bitboard::bitboard() : board_(0ULL)
{
}

jester::bitboard::bitboard(jester::U64 const board) : board_(board)
{
}

jester::U64 jester::bitboard::get_board() const
{
    return this->board_;
}

jester::U64 jester::bitboard::to_bit64(jester::Square const square)
{
    return 1ULL << square;
}

jester::Square jester::bitboard::to_square(jester::U64 const bit64)
{
    return static_cast<jester::Square>(std::log(bit64) / std::log(2));
}

jester::bitboard jester::bitboard::operator&(jester::bitboard const bitboard) const
{
    return jester::bitboard(this->get_board() & bitboard.get_board());
}

jester::bitboard jester::bitboard::operator|(jester::bitboard const bitboard) const
{
    return jester::bitboard(this->get_board() | bitboard.get_board());
}

jester::bitboard jester::bitboard::operator^(jester::bitboard const bitboard) const
{
    return jester::bitboard(this->get_board() ^ bitboard.get_board());
}

int jester::bitboard::get_bit(jester::Square const square) const
{
    return this->board_ & jester::bitboard::to_bit64(square) ? 1 : 0;
}

void jester::bitboard::flip_bit(jester::Square const square)
{
    this->board_ ^= jester::bitboard::to_bit64(square);
}

void jester::bitboard::print(std::ostream& os) const
{
    os << "        Bitboard         " << std::endl;
    os << "=========================" << std::endl;

    for (int rank = 0; rank < 8; rank++)
    {
        for (int file = 0; file < 8; file++)
        {
            int const square = (8 * rank + file) ^ 56;

            if (!file)
            {
                os << 8 - rank << " ";
            }

            os << " " << this->get_bit(static_cast<jester::Square>(square)) << " ";
        }

        os << std::endl;
    }

    os << "   a  b  c  d  e  f  g  h" << std::endl;
}

std::ostream& jester::operator<<(std::ostream& os, jester::bitboard const& bitboard)
{
    bitboard.print(os);
    return os;
}
