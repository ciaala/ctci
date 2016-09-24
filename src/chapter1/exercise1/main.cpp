//
// Created by Francesco Fiduccia on 24/09/16.
//
#include <string>
#include <unordered_map>
#include <iostream>

using namespace std;
namespace exercise1_1 {

    bool checkCharmap(unsigned long long (&charmap)[4], char c) {
        int index = c / 64;
        int offset = c - (4 * index);
        return (charmap[index] & (1 << offset)) > 0;
    }

    void setTrueCharmap(unsigned long long (&charmap)[4], char c) {
        int index = c / 64;
        int offset = c - (4 * index);
        charmap[index] = (charmap[index] | (1 << offset));
    }

    bool hasUniqueCharactersBitmap(string &value) {
        if (value.length() < 2) {
            return true;
        }
        unsigned long long charmap[4] = {0};
        bool hasNoRepetition = true;
        for (auto it = value.cbegin();
             it != value.cend() &&
             hasNoRepetition;
             it++) {
            if (!checkCharmap(charmap, *it)) {
                setTrueCharmap(charmap, *it);
            } else {
                hasNoRepetition = false;
            }
        }
        return hasNoRepetition;
    }

    bool hasUniqueCharacters(string &value) {
        if (value.length() < 2) {
            return true;
        }
        unordered_map<char, bool> chars;
        bool hasNoRepetition = true;
        for (auto it = value.cbegin();
             it != value.cend() &&
             hasNoRepetition;
             it++) {
            if (!chars.count(*it)) {
                chars.emplace(*it, true);
            } else {
                hasNoRepetition = false;
            }
        }
        return hasNoRepetition;
    }


    void printResult(string &value) {
        cout << value << ": " << (hasUniqueCharacters(value) ? "true" : "false") << ", "
             << (hasUniqueCharactersBitmap(value) ? "true" : "false") << endl;

    }

    void main() {
        string pippo = "pippo";
        string noidelmar = "noidelmar";
        string vika = "vika";
        string geronimo = "geronimo";
        //
        cout << "hasUniqueCharacters( string )" << endl;
        printResult(pippo);
        printResult(vika);
        printResult(noidelmar);
        printResult(geronimo);
        cout << endl;
    }
}