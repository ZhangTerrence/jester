#include "board.hpp"

jester::board::board() : pieces_(pieces())
{
}

void jester::board::print(std::ostream& os) const
{
    return this->pieces_.get_all_pieces().print(os);
}

std::ostream& jester::operator<<(std::ostream& os, board const& board)
{
    board.print(os);
    return os;
}
