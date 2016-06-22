//
// Created by crypt on 6/20/16.
//

#include <iostream>
#include <ctime>
#include <sstream>

using namespace std;

namespace exercise16_22 {

    enum Direction {
        left,
        right
    };

    struct Point {
        Point(int x, int y) : x(x), y(y) { }

        int x;
        int y;
    };

    template<unsigned boardSize>
    class Ant {
        bool (&board)[boardSize][boardSize];
        Point position;
        int incrementX = 1;
        int incrementY = 0;

        void rotate() {
            if (incrementY != 0) {
                incrementX = -incrementY;
                incrementY = 0;
            } else if (incrementX != 0) {
                incrementY = incrementX;
                incrementX = 0;
            }
        }

        void flip() {
            board[position.x][position.y] = !board[position.x][position.y];
        }


    public:
        Ant(bool (&board)[boardSize][boardSize]) :
                board(board),
                position({boardSize / 2, boardSize / 2}) {

        }

        void proceed() {
            position.x += incrementX;
            position.y += incrementY;
            if (board[position.x][position.y]) {
                flip();
                rotate();
            } else {
                flip();
                rotate();
                rotate();
                rotate();
            }

        }

        bool isAt(int x, int y) {
            return position.x == x && position.y == y;
        }
    };


    template<unsigned boardSize>
    void setupBoard(bool (&board)[boardSize][boardSize]) {
        bool cellValue = true;
        for (int i = 0; i < boardSize; i++) {
            for (int j = 0; j < boardSize; j++) {
                board[i][j] = cellValue;
                //        cellValue = !cellValue;
            }
            //    cellValue = !cellValue;
        }
    }


    template<unsigned boardSize>
    void
    printBoard(bool (&board)[boardSize][boardSize], Ant<boardSize> *a = nullptr) {

        ostringstream ost;
        for (int i = 0; i < boardSize + 2; i++) {
            ost << "_";
        }
        ost << endl;
        for (int i = 0; i < boardSize; i++) {
            ost << '|';
            for (int j = 0; j < boardSize; j++) {
                if (a != nullptr && a->isAt(i, j)) {
                    ost << "A";
                    continue;
                } else {
                    bool value = board[i][j];
                    ost << (value ? ' ' : '*');
                }
            }
            ost << '|' << endl;
        }
        for (int i = 0; i < boardSize + 2; i++) {
            ost << "-";
        }
        ost << endl;
        cout << ost.str() << endl;
    }


    void printKMoves(int k) {
        const int size = 40;
        bool board[size][size];
        setupBoard<size>(board);
        //printBoard<size>(board);

        Ant<size> a(board);
        for (int i = k; i > 0; i--) {
            a.proceed();
        }
        printBoard<size>(board, &a);


    }

    void main() {
        printKMoves(800);
    }

}
