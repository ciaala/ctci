//
// Created by crypt on 24/06/16.
//

#include <iostream>
#include <vector>
#include "DocumentRespaceAlgorithm.h"

using namespace std;


namespace exercise17_13 {
#define myassert(a, b) __myassert(#a, a, b)


    void main() {
        const vector<string> dictionary = {"i", "love", "maccheroni", "pasta", "pastaasciutta", "pazza", "pizza"};
        string document = "ilovepastasciuttamorethanpizza";
        DocumentRespaceAlgorithm algorithm(dictionary);
        cout << algorithm.respace(document) << endl;
        //const vector<string> solutions;
        //   cout << recursiveSolve(document,dictionary,                               solutions);
    }
}


