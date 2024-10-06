#include "src/game.hpp"

#include <iostream>

// Driver code
int main()
{
    jester::game const game;
    std::cout << game.get_board() << std::endl;
    return 0;
}
