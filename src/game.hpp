#ifndef GAME_HPP
#define GAME_HPP

#include "board.hpp"

namespace jester
{
    class game
    {
    public:
        explicit game();

        [[nodiscard]] int get_player() const;
        [[nodiscard]] jester::board get_board() const;

        void change_player();

    private:
        int player;
        jester::board board;
    };
}

#endif
