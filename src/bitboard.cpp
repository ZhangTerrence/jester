#include "bitboard.hpp"

#include <complex>

jester::bitboard::bitboard() : board_(0ULL)
{
}

jester::bitboard::bitboard(U64 const board) : board_(board)
{
}

jester::U64 jester::bitboard::get_board() const
{
    return this->board_;
}

jester::U64 jester::bitboard::to_bitboard(Square const square)
{
    return 1ULL << square;
}

jester::Square jester::bitboard::to_square(bitboard const bitboard)
{
    return static_cast<Square>(std::log(bitboard.get_board()) / std::log(2));
}

jester::bitboard jester::operator&(bitboard const x, bitboard const y)
{
    return bitboard(x.get_board() & y.get_board());
}

jester::bitboard jester::operator|(bitboard const x, bitboard const y)
{
    return bitboard(x.get_board() | y.get_board());
}

jester::bitboard jester::operator^(bitboard const x, bitboard const y)
{
    return bitboard(x.get_board() ^ y.get_board());
}

jester::U64 jester::bitboard::get_bit(Square const square) const
{
    return this->board_ & to_bitboard(square);
}

jester::U64 jester::bitboard::operator[](Square const square) const
{
    return this->get_bit(square);
}

jester::U64& jester::bitboard::set_bit(Square const square)
{
    return this->board_ |= to_bitboard(square);
}

jester::U64& jester::bitboard::operator[](Square const square)
{
    return this->set_bit(square);
}

void jester::bitboard::flip_bit(Square const square)
{
    this->board_ ^= to_bitboard(square);
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

            os << " " << (this->get_bit(static_cast<Square>(square)) ? 1 : 0) << " ";
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
