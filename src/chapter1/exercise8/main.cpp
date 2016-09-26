//
// Created by Francesco Fiduccia on 24/09/16.
//
#include <string>
#include <unordered_map>
#include <iostream>
#include <vector>
#include <sstream>


using namespace std;
namespace exercise1_8 {

    template<int sizeX, int sizeY>
    void cleanRowColumn(int (&matrix)[sizeX][sizeY]) {
        if (sizeX == 0 && sizeY == 0) {
            return;
        }
        bool columnsToClean[sizeX] = {false};
        bool rowsToClean[sizeY] = {false};
        for (int i = 0; i < sizeX; i++) {
            for (int j = 0; j < sizeY; j++) {
                if (matrix[i][j] == 0) {
                    columnsToClean[i] = true;
                    rowsToClean[j] = true;
                }
            }
        }

        for (int i = 0; i < sizeX; i++) {
            if (columnsToClean[i]) {
                for (int j = 0; j < sizeY; j++) {
                    matrix[i][j] = 0;
                }
            }
        }
        for (int j = 0; j < sizeY; j++) {
            if (rowsToClean[j]) {
                for (int i = 0; i < sizeX; i++) {
                    matrix[i][j] = 0;
                }
            }
        }
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
        cout << "(cleanRowColumn '";
        cout << sizeX << "][" << sizeY << "]) -> " << endl;
        printMatrix(cout, matrix);
        cleanRowColumn(matrix);
        printMatrix(cout, matrix);

    }

    void main() {
        int matrix2x2[2][2] = {{1, 2},
                               {3, 4}};
        int matrix3x3[3][3] = {{0, 1, 2},
                               {3, 4, 5},
                               {6, 7, 8}};
        int matrix1[5][5] = {{0,  1,  2,  3,  4},
                             {5,  6,  7,  8,  9},
                             {10, 11, 0, 13, 14},
                             {15, 16, 17, 0, 19},
                             {20, 21, 22, 23, 24},
        };
        //
        cout << "cleanRowColumn( matrix )" << endl;
        printResult(matrix2x2);
        printResult(matrix3x3);
        printResult(matrix1);
        cout << endl;
    }
}