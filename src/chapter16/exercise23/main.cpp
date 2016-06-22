//
// Created by crypt on 6/20/16.
//

#include <iostream>
#include <ctime>
#include <climits>

using namespace std;

namespace exercise16_23 {

    int rand5() {
        return rand() % 5;
    }

    //
    // SLOW but works
    // Exact distribution is verified but it is not proven
    //
    int workingRand7() {
        return (rand5() + rand5() + rand5() + rand5() + rand5() + rand5() + rand5()) % 7;
    }

    //
    // faster rand7
    // create in base 5 a representation of numbers between 0-24 with the exact same distribution
    //
    int rand7() {
        int value = INT_MAX;
        while (value > 20) {
            value = 5 * rand5() + rand5();
        }
        return value % 7;
    }

    void main() {
        //srand(time(NULL));
        int rand_i = 7;
        unsigned count[rand_i] = {0};
        unsigned rep = (1 << 26);
        if (rand_i == 7) {
            for (unsigned i = 0; i < rep; i++) {
                count[rand7()] += 1;
            }
        } else {
            for (unsigned i = 0; i < rep; i++) {
                count[rand5()] += 1;
            }
        }
        for (int i = 0; i < rand_i; i++) {
            double p = count[i];
            p /= rep;
            cout << i << ": " << p << endl;
        }

    }

}
