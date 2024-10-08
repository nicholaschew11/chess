#include "Knight.h"
#include "../Board.h"

Knight::Knight(Colour colour) : Piece{colour} {}

Knight::Knight(const Knight& other) : Piece{other} {}

std::shared_ptr<Piece> Knight::clone() const {
    return std::make_shared<Knight>(*this);
}

const char Knight::getType() const { 
    return 'n'; 
}

bool Knight::isValidMove(const Board& board, int startRow, int startCol, int endRow, int endCol) const {
    if (startRow == endRow && startCol == endCol) {
        return false;
    }

    int rowDiff = abs(startRow - endRow);
    int colDiff = abs(startCol - endCol);
    // knight can hop over any piece, only need to check the correct move sequence and that it does not land on a piece of same colour
    if ((rowDiff == 2 && colDiff == 1) || (rowDiff == 1 && colDiff == 2)) {
        // check there is not a piece of same colour at the end position
        const std::shared_ptr<Piece> targetPiece = board.getTile(endRow, endCol)->getPiece();
        if (targetPiece && targetPiece->getColour() == getColour()) {
            return false;
        }
        return true;
    }
    return false;
}
