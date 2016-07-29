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
        const vector<string> dictionary = {"i", "love", "maccheroni", "pasta", "pastaasciutta", "pazza", "pizza",
                                           "more"};
        //string document = "ilovepastasciuttamorethanpizza";
        string document = "iai";
        DocumentRespaceAlgorithm algorithm(dictionary);
        string result = algorithm.respace(document);
        cout << result << endl;
        //const vector<string> solutions;
        //   cout << recursiveSolve(document,dictionary,                               solutions);
    }
}


