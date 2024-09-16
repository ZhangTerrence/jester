#include "bitboard.hpp"

#include <iostream>

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
