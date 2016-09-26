//
// Created by Francesco Fiduccia on 24/09/16.
//
#include <string>
#include <iostream>


using namespace std;
namespace exercise1_7 {

    template<int sizeX, int sizeY>
    bool rotate(int (&matrix)[sizeX][sizeY], int direction) {
        if (sizeX < 2 || sizeY < 2 || sizeX != sizeY) {
            return false;
        }

        int size = sizeX - 1;
        for (int r = 0; r < size ; r++) {
            for (int o = r; o < size - r ; o++) {
                int v = matrix[r][o];
                // |1 2|
                // |3 4|
                if (direction == 1) {

                    // Vertical to horizontal

                    // 3 -> 1
                    // matrix[0][0] = matrix[1][0];
                    matrix[r][o] = matrix[size - o][r];

                    // 4 -> 3
                    // matrix[1][0] = matrix[1][1];
                    matrix[size - o][r] = matrix[size - r][size - o];
                    // 2 -> 4
                    // matrix[1][1] = matrix[0][1];
                    matrix[size - r][size - o] = matrix[o][size - r];
                    // 1 -> 2
                    matrix[o][size - r] = v;
                    /*
                    matrix[xSection + x][xSection + y] = matrix[xSection - y][x];

                    matrix[xSection - y][xSection + x] = matrix[xSection - x][xSection - y];
                    matrix[xSection - x][xSection - y] = matrix[xSection + y][xSection - x];
                    matrix[xSection + y][xSection - x] = v;
                     */
                } else if (direction == -1) {
                    /* // 1 <- 4
                     matrix[x][y] = matrix[y][-x];
                     // 4 <- 3
                     matrix[y][-x] = matrix[-x][-y];
                     // 3 <- 2
                     matrix[-x][-y] = matrix[-y][x];
                     // 2 <- 1
                     matrix[-y][x] = v;
                     */
                }
            }
        }
        return true;
    }

    template<int sizeX, int sizeY>
    void printMatrix(ostream &out, int (&matrix)[sizeX][sizeY]) {

        for (int x = 0; x < sizeX; x++) {
            for (int y = 0; y < sizeY; y++) {
                out.width(3);
                out << matrix[x][y];
            }
            out << endl;
        }
        out << endl;
    }

    template<int sizeX, int sizeY>
    void printResult(int (&matrix)[sizeX][sizeY]) {
        cout << "(rotate 'M[";
        cout << sizeX << "][" << sizeY << "]) -> " << endl;
        printMatrix(cout, matrix);
        rotate(matrix, 1);
        printMatrix(cout, matrix);
    }

    void main() {
        int matrix2x2[2][2] = {{1, 2},
                               {3, 4}};
        int matrix3x3[3][3] = {{0, 1, 2},
                               {3, 4, 5},
                               {6, 7, 8}};
        int matrix1[5][5] = {{0, 1, 2, 3, 4},
                             {5, 6, 7, 8, 9},
                             {10, 11, 12, 13, 14},
                             {15, 16, 17, 18, 19},
                             {20, 21, 22, 23, 24},

        };
        //int matrix[10][10] = {0};
        int matrix2[6][6] = {{0,  1,  2,  3,  4,  -5},
                             {5,  6,  7,  8,  9,  -10},
                             {10, 11, 12, 13, 14, -15},
                             {15, 16, 17, 18, 19, -20},
                             {20, 21, 22, 23, 24, -25},
                             {25, 26, 27, 28, 29, -30},

        };
        //
        cout << "rotate( int matrix[][])" << endl;
        /*for (int i = 0; i < texts.size(); i++) {
            for (int j = i; j < texts.size(); j++) {
            //    run(texts[i], texts[j]);
            }
        }
         */
        printResult(matrix2x2);
        printResult(matrix3x3);
        printResult(matrix1);
        printResult(matrix2);
        cout << endl;
    }
}