//
// Created by crypt on 5/25/2016.
//
#include <iostream>
#include <iomanip>
using namespace std;

void run_EX55() {

    for (int i = 0; i <= 64; i++ ) {
        cout << setw(2) << i << ": " << ((i & (i-1)) == 0) << endl;
    }
}


int main_EX55(int argc, const char **argv) {
    run_EX55();
    return 0;
}

