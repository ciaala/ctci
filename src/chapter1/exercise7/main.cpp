//
// Created by Francesco Fiduccia on 24/09/16.
//
#include <string>
#include <unordered_map>
#include <iostream>
#include <vector>
#include <sstream>


using namespace std;
namespace exercise1_7 {

    template<int x, int y>
    void rotate(int (&matrix)[x][y]) {
        if (x < 2 || y < 2) {
            return;
        }

        //for (int x/2);
    }

    template<int x, int y>
    void printResult(int (&matrix)[x][y]) {
        cout << "(rotate 'M[" << x << "][" << y << "]) -> "
             << "done!" << endl;
    }

    void main() {

        //
        cout << "rotate( int matrix[][])" << endl;
        /*for (int i = 0; i < texts.size(); i++) {
            for (int j = i; j < texts.size(); j++) {
            //    printResult(texts[i], texts[j]);
            }
        }
         */
        cout << endl;
    }
}