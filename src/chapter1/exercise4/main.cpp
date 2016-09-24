//
// Created by Francesco Fiduccia on 24/09/16.
//
#include <string>
#include <unordered_map>
#include <iostream>
#include <vector>

using namespace std;
namespace exercise1_4 {

    bool isPalindromePermutation(string &value) {
        if (value.length() < 2) {
            return true;
        }
        bool oddChars[256] = {false};
        int countOdd = 0;
        for (auto it = value.cbegin();
             it != value.cend();
             it++) {
            if (oddChars[*it]) {
                oddChars[*it] = false;
                countOdd -= 1;
            } else {
                oddChars[*it] = true;
                countOdd += 1;
            }
        }
        bool isEvenPermutation = (countOdd == 0 && (value.length() % 2 == 0));
        bool isOddPermutation = (countOdd == 1 && (value.length() % 2 == 1));
        return isEvenPermutation || isOddPermutation;
    }

    void printResult(string &value) {
        cout << "(isPalindromePermutation '" << value << "') -> "
             << (isPalindromePermutation(value) ? "true" : "false") << endl;
    }

    void main() {
        vector<string> texts = {"pippo", "noidelmar", "fika", "vika", "cika", "geronimo", "maredinol", "salemales", "p", "pp",
                                "in girum imus nocte et consumimur igni", "a man a canal a plan panama"};
        //
        cout << "isPalindromePermutation( string )" << endl;
        for (int i = 0; i < texts.size(); i++) {
            printResult(texts[i]);
        }
        cout << endl;
    }
}