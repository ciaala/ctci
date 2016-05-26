//
// Created by crypt on 5/25/2016.
//
#include <iostream>
using namespace std;
///////////////// 5.2
/**
 * Print a real number, less than 1, in binary format
 */
void printDouble_EX52(double d) {
    char r[35] = {0};
    r[0] = '0';
    r[1] = '.';
    int i = 2;
    while (i <34 && d != 0) {
        d *= 2;
        if ( d >= 1) {
            d--;
            r[i] = '1';
        } else {
            r[i] = '0';
        }
        i++;
    }
    if ( i == 34 ) {
        cout << "ERROR !" << endl;
    } else {
        cout << r << endl;
    }
}

void run_EX52() {
    printDouble_EX52(0.5);
    printDouble_EX52(0.25);
    printDouble_EX52(0.125);
    printDouble_EX52(0.625);
    printDouble_EX52(0.875);
    printDouble_EX52(0.0625);
    printDouble_EX52(((double) rand()) / RAND_MAX);
}

int main_EX52(int argc, const char** argv) {
    // run_EX52();

}

