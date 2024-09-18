#ifndef BOARD_HPP
#define BOARD_HPP

#include "bitboard.hpp"
#include "pieces.hpp"

namespace jester
{
    class board final
    {
    public:
        board();

        void print(std::ostream& os = std::cout) const;
        friend std::ostream& operator<<(std::ostream& os, board const& board);

    private:
        pieces pieces_;
    };
}

#endif
