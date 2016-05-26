//
// Created by crypt on 5/25/2016.
//
#include <iostream>
#include <iomanip>

using namespace std;

extern void printBinaryInt(int n);

namespace ex57 {

    void run(int a) {
        int mask = 0b01010101010101010101010101010101;
        int r = ((a << 1) & mask << 1) | ((a >> 1) & (mask));
        printBinaryInt(a);
        printBinaryInt(r);
    }
}
using namespace ex57;

int main_EX57(int argc, const char **argv) {
    run(29);
}

