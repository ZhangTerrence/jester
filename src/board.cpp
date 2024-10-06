#include "board.hpp"

using namespace jester;

board::board()
    : pieces(jester::pieces())
{
}

void board::print(std::ostream& os) const
{
    return this->pieces.get_all_pieces().print(os);
}

std::ostream& jester::operator<<(std::ostream& os, board const& board)
{
    board.print(os);
    return os;
}
