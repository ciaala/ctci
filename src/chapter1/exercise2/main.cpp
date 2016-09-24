//
// Created by Francesco Fiduccia on 24/09/16.
//
#include <string>
#include <unordered_map>
#include <iostream>
#include <vector>

using namespace std;
namespace exercise1_2 {

    bool isPermutation(string &first, string &second) {
        if (first.length() != second.length()) {
            return false;
        }
        int charCounts[256] = {};
        for (auto it = first.cbegin();
             it != first.cend();
             it++) {
            charCounts[*it] += 1;
        }
        bool isValid = true;
        for (auto it = second.cbegin();
             it != second.cend() && isValid;
             it++) {
            charCounts[*it] -= 1;
            isValid = charCounts[*it] >= 0;
        }
        return isValid;
    }

    void printResult(string &first, string &second) {
        cout << "(permutation '" << first << "' '" << second << "') -> "
             << (isPermutation(first, second) ? "true" : "false") << endl;
    }

    void main() {
        vector<string> texts = {"pippo", "noidelmar", "fika", "vika", "cika", "geronimo", "maredinol"};
        //
        cout << "isPermutation( string, string )" << endl;
        for (int i = 0; i < texts.size(); i++) {
            for (int j = i; j < texts.size(); j++) {
                printResult(texts[i], texts[j]);
            }
        }
        cout << endl;
    }
}