//
// Created by crypt on 6/19/16.
//

#include <iostream>
#include <functional>

using namespace std;
namespace exercise16_4 {
    enum BoardCell {
        empty = 0,
        cross = 1,
        circle = 2
    };

    template<int boardSize>
    class BoardIterator {

        unsigned indexX;
        unsigned indexY;
        int incrementX;
        int incrementY;
        BoardCell (&board)[boardSize][boardSize];
    public:
        BoardIterator(BoardCell (&board)[boardSize][boardSize],
                      int incrementX,
                      int incrementY) :
                board(board),

                incrementX(incrementX), incrementY(incrementY) {

        }

        BoardCell getNext() {
            BoardCell value;
            if (indexX < boardSize && indexY < boardSize) {
                value = board[indexX][indexY];
                indexX += incrementX;
                indexY += incrementY;
            } else {
                value = BoardCell::empty;
            }
            return value;
        }

        bool isEnd() {
            return (indexX >= boardSize) || (indexY >= boardSize) ;
        }

        void
        reset(unsigned x, unsigned y) {
            this->indexX = x;
            this->indexY = y;
        }
    };

    template<int boardSize>
    BoardCell
    checkSequence(BoardIterator<boardSize> &iterator) {
        BoardCell first = iterator.getNext();
        if (first != BoardCell::empty) {
            while (!iterator.isEnd()) {
                if (iterator.getNext() != first) {
                    return BoardCell::empty;
                }
            }
        }
        return first;
    }


    template<int boardSize>
    BoardCell hasWon(BoardCell (&board)[boardSize][boardSize]) {
        BoardIterator<boardSize> column = BoardIterator<boardSize>(board, 0, 1);
        BoardIterator<boardSize> row = BoardIterator<boardSize>(board, 1, 0);
        BoardIterator<boardSize> diagonal = BoardIterator<boardSize>(board, 1, 1);
        BoardIterator<boardSize> reverseDiagonal = BoardIterator<boardSize>(board, -1, 1);

        for (unsigned i = 0; i < boardSize; i++) {
            column.reset(i, 0);
            row.reset(0, i);
            BoardCell columnCell = checkSequence(column);
            BoardCell rowCell = checkSequence(row);
            if (columnCell != BoardCell::empty) {
                return columnCell;
            } else if (rowCell != BoardCell::empty) {
                return rowCell;
            }
        }
        diagonal.reset(0, 0);
        BoardCell diagonalCell = checkSequence(diagonal);
        if (diagonalCell != BoardCell::empty) {
            return diagonalCell;
        }
        reverseDiagonal.reset(boardSize-1, 0);
        BoardCell reverseCell = checkSequence(reverseDiagonal);
        if (reverseCell != BoardCell::empty) {
            return reverseCell;
        }

    }

    void main() {
        const unsigned N = 3;
        BoardCell board[N][N] = {BoardCell::empty};
/*
        board[0][1] = BoardCell::cross;
        board[1][1] = BoardCell::cross;
        board[2][1] = BoardCell::cross;
/**/

        board[2][0] = BoardCell::circle;
        board[1][1] = BoardCell::circle;
        board[0][2] = BoardCell::circle;
       /* */
        string symbol;
        auto winExpr = [&symbol] { cout << symbol << "'s player" << " has won" << endl; };
        auto drawExpr = [&symbol] { cout << "No one has won." << endl; };;

        switch (hasWon(board)) {
            case BoardCell::empty:
                drawExpr();
                break;
            case BoardCell::cross:
                symbol = "Cross";
                winExpr();
                break;
            case BoardCell::circle:
                symbol = "Circle";
                winExpr();
                break;
        }

    }
}
