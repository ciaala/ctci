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
        for (unsigned long i = 0; i < pattern.length(); i++) {
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

            if (value.compare(valueOffset, size, value, offset, size) != 0) {
                return false;
            }
            valueOffset += size;
        }
        return true;
    }


    Result mmatches(string &value, string &pattern) {
        Result result;

        unsigned long countMain = (unsigned long) count(pattern.begin(), pattern.end(), pattern.at(0));
        unsigned long countAlternate = pattern.length() - countMain;
        unsigned long maxMainSize = value.length() / countMain;

        for (unsigned mainSize = 0; mainSize <= maxMainSize; mainSize++) {
            unsigned long remainingLength = value.length() - (mainSize * countMain);
            unsigned long altSize = remainingLength / countAlternate;
            if (altSize == 0 || ((remainingLength % countAlternate) == 0)) {

                if (matchValuePattern(value, pattern, mainSize, altSize)) {
                    result.isAMatch = true;
                    result.patternElements.insert({pattern.at(0), value.substr(0, mainSize)});
                    auto indexAlt = pattern.find_first_not_of(pattern.at(0));
                    result.patternElements.insert({pattern.at(indexAlt), value.substr(indexAlt*mainSize, altSize)});
                    break;
                }
            }
        }

        return result;
    }

    void main() {
        string mpattern = "aabab";
        string mvalue = "catcatgocatgo";

        Result result = mmatches(mvalue, mpattern);
        cout << "'" << mvalue << "'@'" << mpattern << "'" << endl;
        cout << "Does it match ? " << (result.isAMatch ? "true" : "false") << endl;
        for_each(result.patternElements.begin(), result.patternElements.end(),
                 [](auto item) { cout << item.first << ": " << item.second << endl; });

    }

}
