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

    // Standard 64-bit bitboard
    class bitboard final
    {
    public:
        explicit bitboard();
        explicit bitboard(U64 board);

        [[nodiscard]] U64 get_board() const;

        [[nodiscard]] static U64 to_bitboard(Square square);
        [[nodiscard]] static Square to_square(bitboard bitboard);

        [[nodiscard]] friend bitboard operator&(bitboard x, bitboard y);
        [[nodiscard]] friend bitboard operator|(bitboard x, bitboard y);
        [[nodiscard]] friend bitboard operator^(bitboard x, bitboard y);

        [[nodiscard]] U64 get_bit(Square square) const;
        [[nodiscard]] U64 operator[](Square square) const;

        U64& set_bit(Square square);
        U64& operator[](Square square);

        void flip_bit(Square square);

        void print(std::ostream& os = std::cout) const;
        friend std::ostream& operator<<(std::ostream& os, bitboard const& bitboard);

    private:
        U64 board_;
    };

    // Preset Bitboards
    // NOTE: Based on Little-Endian Rank-File Mapping
    U64 constexpr starting_white = 0x000000000000FFFF;
    U64 constexpr starting_black = 0xFFFF000000000000;
    U64 constexpr starting_pawns = 0x00FF00000000FF00;
    U64 constexpr starting_knights = 0x4200000000000042;
    U64 constexpr starting_bishops = 0x2400000000000024;
    U64 constexpr starting_rooks = 0x8100000000000081;
    U64 constexpr starting_queens = 0x0800000000000008;
    U64 constexpr starting_kings = 0x1000000000000010;

    U64 constexpr light_squares = 0x55AA55AA55AA55AA;
    U64 constexpr dark_squares = 0xAA55AA55AA55AA55;
}

#endif
