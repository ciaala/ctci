//
// Created by crypt on 5/25/2016.
//
#include <iostream>
#include <iomanip>

void testLowerest(int n);

using namespace std;

bool getBit(int n, int position) {
    return (n & (1 << position)) != 0;
}

int clearBit(int n, int position) {
    return (n & ~(1 << position));
}

int setBit(int n, int position) {
    return (n | (1 << position));
}

/////////// 5.4
void printBinaryInt(int n) {
    cout << "n: " << n << endl;
    for (int i = 31; i >= 0; i--) {
        //cout << setw(2) << i << ": " << getBit(n, i) << endl;
        cout << getBit(n, i);
    }
    cout << endl;
}

int countOneBits(int n) {
    int count = 0;
    for (int i = 0; i < 32; i++) {
        if (getBit(n, i)) count++;
    }
    return count;
}

int nearestLowestNumberWithSameOneBits(int n) {
    int i = 0, count_one = 0, count_zero = 0;
    int r = n;
    while (getBit(n, i)) {
        i++;
        count_one++;
    }
    while (getBit(n, i) == 0) {
        i++;
        count_zero++;
    }
    if ( i < 32) {
        r = clearBit(r, i--);
        r = setBit(r, i--);
        while (count_one > 0) {
            count_one--;
            r = setBit(r, i--);
        }
        count_zero--;
        while (count_zero > 0) {
            count_zero--;
            r = clearBit(r, i--);
        }
    }
    return r;
}


int nearestHighestNumberWithSameOneBits(int n) {
    int i = 0, count_one = 0, count_zero = 0;
    int r = n;

    while (getBit(n, i) == 0) {
        i++;
        count_zero++;
    }
    while (getBit(n, i)) {
        i++;
        count_one++;
    }
    if ( i < 32) {

        r = setBit(r, i--);
        r = clearBit(r, i--);

        while (count_zero > 0) {
            count_zero--;
            r = clearBit(r, i--);
        }
        count_one--;
        while (count_one > 0) {
            count_one--;
            r = setBit(r, i--);
        }
    }
    return r;
}


void testHighest(int n) {
    int test = n;

    int r = nearestHighestNumberWithSameOneBits(test);
    if (countOneBits(test) != countOneBits(r)) {

        cout << "Unable to get the same number of bits" << endl;
    }
    printBinaryInt(test);
    printBinaryInt(r);
}

void testLowerest(int n) {
    int test = n;

    int r = nearestLowestNumberWithSameOneBits(test);
    if (countOneBits(test) != countOneBits(r)) {

        cout << "Unable to get the same number of bits"<< endl;
    }
    printBinaryInt(test);
    printBinaryInt(r);
}

void run_EX54(int n) {
    cout << "testLowerest" << endl;
    testLowerest(n);
    cout << "testHighest" << endl;
    testHighest(n);

}


int main_EX54(int argc, const char **argv) {
    run_EX54(94);
}

