#ifndef PIECES_HPP
#define PIECES_HPP

#include "bitboard.hpp"

namespace jester
{
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
        explicit pieces();
        explicit pieces(std::string fen);

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
        jester::bitboard piece_bitboards[8];

        void reset_pieces();
    };
}

#endif
