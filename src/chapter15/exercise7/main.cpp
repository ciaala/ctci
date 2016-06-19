//
// Created by Francesco Fiduccia on 18/06/16.
//
#include <iostream>

namespace exercise15_7 {
    using namespace std;
    unsigned N = 1 << 12;

    void main() {
        for (unsigned i = 0; i < N; i++) {
            if ((i % 15) == 0) {
                cout << "FizzBuzz" << endl;
            } else if ((i % 3) == 0) {
                cout << "Fizz" << endl;
            } else if ((i % 5) == 0) {
                cout << "Buzz" << endl;
            } else {
                cout << i << endl;
            }
        }
    }
}
