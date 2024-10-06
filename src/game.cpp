#include "game.hpp"

using namespace jester;

game::game()
    : player(0),
      board(jester::board())
{
}

int game::get_player() const
{
    return this->player;
}

board game::get_board() const
{
    return this->board;
}

void game::change_player()
{
    this->player = !this->player;
}
