//
// Created by Francesco Fiduccia on 24/09/16.
//
#include <string>
#include <unordered_map>
#include <iostream>
#include <vector>
#include <sstream>


using namespace std;
namespace exercise1_6 {

    string compress(string &original) {
        if (original.length() == 0) {
            return original;
        }
        ostringstream result;
        char prev = original.front();
        unsigned count = 1;
        auto it = original.cbegin();
        it++;
        while (it != original.end()) {
            if (*it == prev) {
                count++;
            } else {
                result << count << prev;
                prev = *it;
                count = 1;
            }
            it++;
        }
        result << count << prev;
        result.flush();
        result.seekp(0, ios::end);
        if (original.length() < result.tellp()) {
            return original;
        } else {
            return result.str();
        }
    }

    void printResult(string &input) {
        cout << "(compress '" << input << "') -> '"
             << compress(input) << "'" << endl;
    }

    void main() {
        vector<string> texts = {"", "pippo", "noidelmar", "ggdd", "aaabbb", "abcddd", "acccc"};
        //
        cout << "isZeroOneEditAway( string, string )" << endl;
        for (int i = 0; i < texts.size(); i++) {
            printResult(texts[i]);
        }
        cout << endl;
    }

}