#ifndef BITBOARD_HPP
#define BITBOARD_HPP

#include <cinttypes>
#include <complex>
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
        bitboard() : board_(0ULL)
        {
        }

        explicit bitboard(U64 const board) : board_(board)
        {
        }

        ~bitboard() = default;

        [[nodiscard]] U64 get_board() const
        {
            return this->board_;
        }

        [[nodiscard]] static U64 to_bitboard(Square const square)
        {
            return 1ULL << square;
        }

        [[nodiscard]] static Square to_square(bitboard const bitboard)
        {
            return static_cast<Square>(std::log(bitboard.get_board()) / std::log(2));
        }

        [[nodiscard]] friend bitboard operator&(bitboard const x, bitboard const y)
        {
            return bitboard(x.get_board() & y.get_board());
        }

        [[nodiscard]] friend bitboard operator|(bitboard const x, bitboard const y)
        {
            return bitboard(x.get_board() | y.get_board());
        }

        [[nodiscard]] friend bitboard operator^(bitboard const x, bitboard const y)
        {
            return bitboard(x.get_board() ^ y.get_board());
        }

        [[nodiscard]] U64 get_bit(Square const square) const
        {
            return this->board_ & to_bitboard(square);
        }

        void set_bit(Square const square)
        {
            this->board_ |= to_bitboard(square);
        }

        void flip_bit(Square const square)
        {
            this->board_ ^= to_bitboard(square);
        }

        void print(std::ostream& os = std::cout) const;

        friend std::ostream& operator<<(std::ostream& os, bitboard const& bitboard)
        {
            bitboard.print(os);
            return os;
        }

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
