//
// Created by Francesco Fiduccia on 24/09/16.
//
#include <string>
#include <unordered_map>
#include <iostream>
#include <vector>
#include <sstream>


using namespace std;
namespace exercise1_9 {

    bool isSubstring(string &first, string &second) {
        unsigned long pos = first.find(second);
        return (pos >= 0) && (pos < second.length());
    }

    bool isStringRotation(string &first, string &second) {
        if (first.length() != second.length()) {
            return false;
        }

        string concatenation = second + second;
        return isSubstring(concatenation, first);
    }

    void printResult(string &first, string &second) {
        cout << "\t(isStringRotation '" << first << "' '" << second << "') -> "
             << isStringRotation(first, second) << endl;
    }

    void main() {
        vector<string> texts = {"pippp", "ipppp", "ppppi", "pppip", "piaaappp", "iaaappp", "aaapppi", "aapppia"};
        //
        cout << "isStringRotation( string, string )" << endl;
        for (int i = 0; i < texts.size(); i++) {
            for (int j = i; j < texts.size(); j++) {
                printResult(texts[i], texts[j]);
            }
        }
        cout << endl;
    }
}