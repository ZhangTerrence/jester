#include "src/board.hpp"

#include <iostream>

// Driver code
int main()
{
    jester::board const board;
    auto x = board.pieces.get_all_pieces();
    std::cout << x << std::endl;
    std::cout << (x.get_board() & (1ULL << jester::Square::a1)) << std::endl;
    x.flip_bit(jester::a1);
    std::cout << x << std::endl;
    std::cout << x.get_bit(jester::a1) << std::endl;
    return 0;
}
