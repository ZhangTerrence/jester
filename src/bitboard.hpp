#ifndef BITBOARD_HPP
#define BITBOARD_HPP

#include <cinttypes>
#include <iostream>

namespace jester
{
    std::string const starting_fen = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";
    std::string const starting_board_fen = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR";

    typedef uint64_t u64;

    jester::u64 constexpr all_squares = 0xFFFFFFFFFFFFFFFF;
    jester::u64 constexpr light_squares = 0x55AA55AA55AA55AA;
    jester::u64 constexpr dark_squares = 0xAA55AA55AA55AA55;

    // Little-Endian Rank-File Enumeration
    enum Square : unsigned int
    {
        a1, b1, c1, d1, e1, f1, g1, h1,
        a2, b2, c2, d2, e2, f2, g2, h2,
        a3, b3, c3, d3, e3, f3, g3, h3,
        a4, b4, c4, d4, e4, f4, g4, h4,
        a5, b5, c5, d5, e5, f5, g5, h5,
        a6, b6, c6, d6, e6, f6, g6, h6,
        a7, b7, c7, d7, e7, f7, g7, h7,
        a8, b8, c8, d8, e8, f8, g8, h8
    };

    std::ostream& operator<<(std::ostream& os, jester::Square const& square);

    enum Rank : jester::u64
    {
        Rank1 = 0x00000000000000FF,
        Rank2 = 0x000000000000FF00,
        Rank3 = 0x0000000000FF0000,
        Rank4 = 0x00000000FF000000,
        Rank5 = 0x000000FF00000000,
        Rank6 = 0x0000FF0000000000,
        Rank7 = 0x00FF000000000000,
        Rank8 = 0xFF00000000000000,
    };

    enum File : jester::u64
    {
        FileA = 0x0101010101010101,
        FileB = 0x0202020202020202,
        FileC = 0x0404040404040404,
        FileD = 0x0808080808080808,
        FileE = 0x1010101010101010,
        FileF = 0x2020202020202020,
        FileG = 0x4040404040404040,
        FileH = 0x8080808080808080
    };

    [[nodiscard]] jester::u64 to_u64(jester::Square square);
    [[nodiscard]] jester::Square to_square(jester::u64 bit64);

    class bitboard final
    {
    public:
        explicit bitboard();
        explicit bitboard(jester::u64 board);

        [[nodiscard]] jester::u64 get_board() const;

        jester::bitboard operator&(jester::bitboard bitboard) const;
        jester::bitboard operator|(jester::bitboard bitboard) const;
        jester::bitboard operator^(jester::bitboard bitboard) const;

        [[nodiscard]] int get_bit(jester::Square square) const;
        void flip_bit(jester::Square square);

        void print(std::ostream& os = std::cout) const;
        friend std::ostream& operator<<(std::ostream& os, jester::bitboard const& bitboard);

    private:
        jester::u64 board;
    };
}

#endif
