//
// Created by crypt on 6/20/16.
//

#include <iostream>
#include <ctime>

using namespace std;

namespace exercise16_5 {

    unsigned countTrailingZeroesInFactorial(unsigned number) {
        unsigned counter = 0;
        for (unsigned i = 5; i < number; i += 5) {
            unsigned test = i;
            while (test % 5 == 0) {
                test /= 5;
                counter++;
            }
        }
        return counter;
    }

    void main() {
        srand((unsigned) std::time(0));
        unsigned N = (unsigned) rand();
        unsigned zeroes = countTrailingZeroesInFactorial(N);
        cout << N << "! will have " << zeroes << " trailing zeros" << endl;
    }

}