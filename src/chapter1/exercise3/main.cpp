//
// Created by Francesco Fiduccia on 24/09/16.
//
#include <string>
#include <unordered_map>
#include <iostream>
#include <vector>

using namespace std;
namespace exercise1_3 {

    string &urlify(pair<string, int> &input) {
        string & value = input.first;
        int length = input.second;

        for (int index = value.size() - 1,
                     scan = length - 1;
             index >= 0 && scan >= 0;
             index--, scan--) {

            if (value[scan] == ' ') {
                value[index] = '0';
                value[--index] = '2';
                value[--index] = '%';
            } else {
                value[index] = value[scan];
            }
        }
        return value;
    }

    void printResult(pair<string, int> &input) {
        cout << "(urlify '" << input.first << "' '" << input.second << "' ) -> "
             << urlify(input) << endl;
    }

    void main() {
        vector<pair<string, int>> texts = {{"pippo",                              5},
                                           {"mar al salam    ",                   12},
                                           {"google is coming    ",               16},
                                           {"you know nothing john snow        ", 26}};
        //
        cout << "urlify( string )" << endl;
        for (unsigned i = 0; i < texts.size(); i++) {
            printResult(texts[i]);
        }
        cout << endl;
    }
}