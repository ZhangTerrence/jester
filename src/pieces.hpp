#ifndef PIECES_HPP
#define PIECES_HPP

#include "bitboard.hpp"

namespace jester
{
    U64 constexpr starting_bitboards[8] = {
        starting_white,
        starting_black,
        starting_pawns,
        starting_knights,
        starting_bishops,
        starting_rooks,
        starting_queens,
        starting_kings,
    };

    class pieces final
    {
    public:
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

        pieces();

        bitboard operator[](unsigned int index) const;
        bitboard& operator[](unsigned int index);

        [[nodiscard]] bitboard get_all_pieces() const;
        [[nodiscard]] bitboard get_white_pieces() const;
        [[nodiscard]] bitboard get_black_pieces() const;
        [[nodiscard]] bitboard get_white_pawns() const;
        [[nodiscard]] bitboard get_white_knights() const;
        [[nodiscard]] bitboard get_white_bishops() const;
        [[nodiscard]] bitboard get_white_rooks() const;
        [[nodiscard]] bitboard get_white_queen() const;
        [[nodiscard]] bitboard get_white_king() const;
        [[nodiscard]] bitboard get_black_pawns() const;
        [[nodiscard]] bitboard get_black_knights() const;
        [[nodiscard]] bitboard get_black_bishops() const;
        [[nodiscard]] bitboard get_black_rooks() const;
        [[nodiscard]] bitboard get_black_queen() const;
        [[nodiscard]] bitboard get_black_king() const;

    private:
        bitboard piece_bitboards_[8];
    };
}

#endif
