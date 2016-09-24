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


    string isZeroOneEditAway(string &first, string &second) {
        bool isInsert = false;
        bool isRemove = false;
        bool isReplace = false;
        bool differentMoreOperations = false;
        unsigned long diffPosition = 0;
        unsigned long scan = 0;
        while (scan < first.length()) {
            if (first[scan] != second[scan]) {
                diffPosition = scan;
                unsigned long remaining = first.length() - scan - 1;
                unsigned long firstScan = scan;
                unsigned long secondScan = scan;
                if (first.length() < second.length()) {
                    isRemove = true;
                    secondScan++;
                } else if (first.length() > second.length()) {
                    isInsert = true;
                    firstScan++;
                } else {
                    isReplace = true;
                    firstScan++;
                    secondScan++;
                }
                differentMoreOperations = first.compare(firstScan, remaining, second, secondScan, remaining) != 0;
                scan = first.length();
            } else {
                scan++;
            }

        }
        stringstream result;
        if (!differentMoreOperations) {
            if (isInsert) {
                result << "INSERT at " << diffPosition << " '" << first[diffPosition] << "'";
            } else if (isRemove) {
                result << "REMOVE at " << diffPosition << " '" << second[diffPosition] << "'";
            } else if (isReplace) {
                result << "REPLACE at " << diffPosition << " '" <<
                       first[diffPosition] << "' -> '" << second[diffPosition] << "'";
            } else {
                result << "EQUALS";
            }
        } else {
            result << "DIFF";
        }
        return result.str();
    }

    void printResult(string &first, string &second) {
        cout << "(isZeroOneEditAway '" << first << "' '" << second << "') -> "
             << isZeroOneEditAway(first, second)  << endl;
    }

    void main() {
        vector<string> texts = {"pippo", "noidelmar", "fika", "vika", "icika", "cika" , "ivika", "geronimo", "maredinol"};
        //
        cout << "isZeroOneEditAway( string, string )" << endl;
        for (int i = 0; i < texts.size(); i++) {
            for (int j = i; j < texts.size(); j++) {
                printResult(texts[i], texts[j]);
            }
        }
        cout << endl;
    }
}