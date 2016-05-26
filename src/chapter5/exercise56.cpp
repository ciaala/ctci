//
// Created by crypt on 5/25/2016.
//
#include <iostream>
#include <iomanip>

using namespace std;
namespace ex56 {
    bool getBit(int n, int p) {
        return ((n & (1 << p)) > 0);
    }

    void run_EX56(int a, int b) {
        int count = 0;
        for (int i = 0; i < 32; i++) {
            if (getBit(a, i) != getBit(b, i)) count++;
        }
        cout << a << " @ " << b << ": " << count << endl;
    }
}
using namespace ex56;

int main_EX56(int argc, const char **argv) {
    run_EX56(29, 15);
}

