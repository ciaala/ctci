//
// Created by crypt on 6/20/16.
//

#include <iostream>
#include <ctime>
#include <sstream>

using namespace std;

namespace exercise16_8 {


    string units[] = {"billion", "million", "thousand",""};
    string digit[] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine",
                      "ten", "eleven", "twelve",
                      "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
    string dec[] = {"twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};


    void printEnglish(ostream &ost, int n) {
        int t;
        if (n > 100) {
            t = n / 100;
            n %= 100;
            ost << digit[t] << " hundred" << (t > 1 ? "s " : " ");
            if (n > 0 ) {
                ost << "and ";
            }
        }

        if (n > 20) {
            t = n / 10;
            int r = n % 10;
            ost << dec[t-2] << " " << digit[r];
        } else {
            ost << digit[n];
        }

    }

    string printNumberInEnglish(int n) {
        ostringstream sout;
        int d = 1000000000;
        int t = n;
        unsigned i = 0;
        do {
            int q = t / d;
            if (q > 0) {
                printEnglish(sout, q);
                sout << " " << units[i] << (q > 1 ? "s, " : ", ");
            }

            int r = n % d;
            t = r;
            d /= 1000;
            cout << sout.str() << endl;
            i++;
        } while (t > 1);
        return sout.str();
    }

    void main() {
        int n = rand();
        cout << "English form of " << n << endl;

        cout << printNumberInEnglish(n) << endl;
    }

}