#ifndef BITBOARD_HPP
#define BITBOARD_HPP

#include <cinttypes>
#include <iostream>

namespace jester
{
    typedef uint64_t U64;

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

    // Standard 64-bit bitboard
    class bitboard final
    {
    public:
        explicit bitboard();
        explicit bitboard(jester::U64 board);

        [[nodiscard]] jester::U64 get_board() const;

        [[nodiscard]] static jester::U64 to_bit64(jester::Square square);
        [[nodiscard]] static jester::Square to_square(jester::U64 bit64);

        jester::bitboard operator&(jester::bitboard bitboard) const;
        jester::bitboard operator|(jester::bitboard bitboard) const;
        jester::bitboard operator^(jester::bitboard bitboard) const;

        [[nodiscard]] int get_bit(jester::Square square) const;
        void flip_bit(jester::Square square);

        void print(std::ostream& os = std::cout) const;
        friend std::ostream& operator<<(std::ostream& os, jester::bitboard const& bitboard);

    private:
        jester::U64 board_;
    };

    // Preset Bitboards
    // NOTE: Based on Little-Endian Rank-File Mapping
    jester::U64 constexpr starting_white = 0x000000000000FFFF;
    jester::U64 constexpr starting_black = 0xFFFF000000000000;
    jester::U64 constexpr starting_pawns = 0x00FF00000000FF00;
    jester::U64 constexpr starting_knights = 0x4200000000000042;
    jester::U64 constexpr starting_bishops = 0x2400000000000024;
    jester::U64 constexpr starting_rooks = 0x8100000000000081;
    jester::U64 constexpr starting_queens = 0x0800000000000008;
    jester::U64 constexpr starting_kings = 0x1000000000000010;

    jester::U64 constexpr light_squares = 0x55AA55AA55AA55AA;
    jester::U64 constexpr dark_squares = 0xAA55AA55AA55AA55;
}

#endif
