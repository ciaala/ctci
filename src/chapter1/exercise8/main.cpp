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
        if (sizeX)
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
            if (rowsToClean[j] ) {
                for (int i=0; i < sizeX; i++) {
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
        printMatrix, cout, matrix);
        cleanRowColumn(matrix);
        printMatrix(cout, matrix);

    }

    void main() {
        vector<string> texts = {"pippo", "noidelmar", "fika", "vika", "icika", "cika", "ivika", "geronimo",
                                "maredinol"};
        //
        cout << "cleanRowColumn( matrix )" << endl;
        for (int i = 0; i < texts.size(); i++) {
            for (int j = i; j < texts.size(); j++) {
                printResult(texts[i], texts[j]);
            }
        }
        cout << endl;
    }
}