#include "board.hpp"

jester::board::board() : pieces(jester::pieces())
{
}

void jester::board::print(std::ostream& os) const
{
    return this->pieces.get_all_pieces().print(os);
}

std::ostream& jester::operator<<(std::ostream& os, jester::board const& board)
{
    board.print(os);
    return os;
}