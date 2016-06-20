//
// Created by crypt on 6/20/16.
//

#include <iostream>
#include <ctime>
#include <math.h>
#include <climits>

using namespace std;

namespace exercise16_7 {

/*
 * This solution is incomplete because
 * it miss to check for the overflow condition
 */
    int getMaxIncorrect(int n1, int n2) {
        //int d21 = n2 - n1;
        int d12 = n1 - n2;



        unsigned mask32Bit = 1 << 31;
        unsigned m12 = (d12 & mask32Bit);
        //unsigned m21 = (d21 & mask32Bit);
        int s12 = (!m12) * -1;
        int s21 = (!!m12) * -1;
        int result = (n1 & s12) + (n2 & s21);
    }

    double getMaxVigano(int n1, int n2) {
        return ((n1 + n2) / 2.0) + (abs(n1 - n2) / 2.0);
    }

    /**
     * flips a 0 to 1 and 1 to 0
     */
    int flip(int bit) {
        return (1 ^ bit);
    }

    /**
     * return 1 if positive 0 if negative
     */
    int sign(int a) {
        return flip(a >> 31) & 0x1;
    }

    int getMaxNaive(int a, int b) {
        int k = sign(a - b);
        int q = flip(k);
        return a * k + b * q;
    }

    int getMax(int a, int b) {
        int c = a - b; // will overflow when a>0 and b < 0
        //
        int sa = sign(a); // if a >= 0, then 1 else 0
        int sb = sign(b); // if b >= 0, then 1 else 0
        int sc = sign(c); // depends on whatever or not a-b overflow

        /* Goal: define a value k which is 1 a>b and 0 a<b
           if a = b it doesn't matter what value k is */

        // if a and b have different sign, then k = sign(a)
        int use_sign_of_a = sa ^sb;

        // if a and b have the same sign, then k = sign(a-b)
        int use_sign_of_c = flip(sa ^ sb);

        //
        // use sa if a and b have different sign ( protection by overflow )
        // --> implies (sc * use_sign_of_c) = 0
        // --> proof use_sign_of_c
        // or use sign of sc if same sign
        //
        int k = use_sign_of_a * sa + use_sign_of_c * sc;

        int q = flip(k); // opposite of k

        return a * k + b * q;
    }

    bool testGetMax(int n1, int n2) {
        int r = n1 > n2 ? n1 : n2;
        int result = getMax(n1, n2);
        if (r != result) {
            cout << "failed (" << n1 << ", " << n2 << "): " << getMax(n1, n2) << endl;
        }
    }

    void main() {
        testGetMax(-2, -2);
        testGetMax(-2, -1);
        testGetMax(-2, 0);
        testGetMax(-2, 1);
        testGetMax(-2, 2);

        testGetMax(2, -2);
        testGetMax(2, -1);
        testGetMax(2, 0);
        testGetMax(2, 1);
        testGetMax(2, 2);

        testGetMax(INT_MAX - 2, -15);
    }

}