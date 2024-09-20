#ifndef PIECES_HPP
#define PIECES_HPP

#include "bitboard.hpp"

namespace jester
{
    jester::U64 constexpr starting_bitboards[8] = {
        jester::starting_white,
        jester::starting_black,
        jester::starting_pawns,
        jester::starting_knights,
        jester::starting_bishops,
        jester::starting_rooks,
        jester::starting_queens,
        jester::starting_kings,
    };

    enum Piece : unsigned int
    {
        White,
        Black,
        Pawn,
        Knight,
        Bishop,
        Rook,
        Queen,
        King
    };

    class pieces final
    {
    public:
        pieces();

        jester::bitboard operator[](unsigned int index) const;
        jester::bitboard& operator[](unsigned int index);

        [[nodiscard]] jester::bitboard get_all_pieces() const;
        [[nodiscard]] jester::bitboard get_white_pieces() const;
        [[nodiscard]] jester::bitboard get_black_pieces() const;
        [[nodiscard]] jester::bitboard get_white_pawns() const;
        [[nodiscard]] jester::bitboard get_white_knights() const;
        [[nodiscard]] jester::bitboard get_white_bishops() const;
        [[nodiscard]] jester::bitboard get_white_rooks() const;
        [[nodiscard]] jester::bitboard get_white_queen() const;
        [[nodiscard]] jester::bitboard get_white_king() const;
        [[nodiscard]] jester::bitboard get_black_pawns() const;
        [[nodiscard]] jester::bitboard get_black_knights() const;
        [[nodiscard]] jester::bitboard get_black_bishops() const;
        [[nodiscard]] jester::bitboard get_black_rooks() const;
        [[nodiscard]] jester::bitboard get_black_queen() const;
        [[nodiscard]] jester::bitboard get_black_king() const;

    private:
        jester::bitboard piece_bitboards_[8];
    };
}

#endif
