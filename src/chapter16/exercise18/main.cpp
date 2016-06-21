//
// Created by crypt on 6/20/16.
//

#include <iostream>
#include <ctime>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

namespace exercise16_18 {


    class Result {
    public:
        Result() : isAMatch(false) { }

        bool isAMatch;
        unordered_map<char, string> patternElements;

    };


    bool matchValuePattern(string &value, string &pattern, unsigned long mainSize, unsigned long altSize) {
        unsigned valueOffset = 0;
        unsigned firstAltOffset = 0;
        for (unsigned long i = 0; i < value.length(); i++) {
            /**
             * Initialize Alternative
             */

            if ((firstAltOffset == 0) && pattern.at(i) != pattern.at(0)) {
                firstAltOffset = valueOffset;
            }

            /**
             * check
             */
            unsigned long size = pattern.at(i) == pattern.at(0) ? mainSize : altSize;
            unsigned long offset = pattern.at(i) == pattern.at(0) ? 0 : firstAltOffset;

            if (value.compare(valueOffset, size, value, size, offset) != 0) {
                return false;
            }
            valueOffset += size;
        }
        return false;
    }


    void mmatches(string &value, string &pattern) {
    //    Result result;

        unsigned long countMain = (unsigned long) count(pattern.begin(), pattern.end(), pattern.at(0));
        unsigned long countAlternate = pattern.length() - countMain;
        unsigned long maxMainSize = value.length() / countMain;
        //?? unsigned long maxAlternateSize = value.length() / countAlternate;


        for (unsigned mainSize = 0; mainSize < maxMainSize; mainSize++) {
            unsigned long altSize = (value.length() - (mainSize * countMain)) / countAlternate;
            if ((value.length() % (mainSize * countMain) == 0) && (value.length() % (altSize * countAlternate) == 0)) {

                if (matchValuePattern(value, pattern, mainSize, altSize)) {
                    //result.patternElements.insert({pattern.at(0), pattern.substr(0, mainSize)});
                    break;
                }
            }
        }

        // return result;
    }

    void main() {
        string pattern = "aabab";
        string value = "catcatgocatgo";

       // Result result;

        //result =
                mmatches(value, pattern);
//        cout << "'" << value << "'@'" << pattern << "'" << endl;
 //       cout << "Does it match ? " << (result.isAMatch ? "true" : "false") << endl;
        /*for_each(result.patternElements.begin(), result.patternElements.end(),
                 [](auto item) { cout << item.first << ": " << item.second << endl; });
*/
    }

}
