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


/////////// 5.3
int findBitToTurn(int value) {
    int i = 0;
    int cur_count = 0;
    int cur_p = -1;
    int max_count = -1;
    int max_p = -1;
    while ( value != 0) {
        int r = value & 1;
        cout << r;
        if ( r == 1 ) {
            cur_count ++;
            if ( cur_count > max_count ) {
                max_count = cur_count;
                max_p = cur_p;
            }
        } else {
            if (max_p == -1) {
                max_p = i;
                cur_count++;
                max_count = cur_count;
                cur_p = i;
            } else {
                cur_count = i - cur_p;
                cur_p = i;
            }
        }
        i++;
        value = value>> 1;
    }
    cout << endl;
    cout << "max_p : " << max_p << endl;
    cout << "max_count : " << max_count << endl;
}

void run_EX53() {
    findBitToTurn(38);
    findBitToTurn(39);
    findBitToTurn(243);
    findBitToTurn(1743);
    findBitToTurn(1775);
}

int main(int argc, const char** argv) {
   // run_EX52();
    run_EX53();
}
