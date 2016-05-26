//
// Created by crypt on 5/26/2016.
//

#include <iostream>
#include <iomanip>
#include <c++/5.3.0/bitset>

using namespace std;

extern void printBinaryInt(int n);

namespace ex58 {
    int getBytePosition(int width, int x, int y) {
        return (x / 8) + ((width / 8) * y);
    }


    template<int size>
    void drawLine(unsigned char (&screen)[size], int width, int x1, int x2, int y) {
        int startByte = getBytePosition(width, x1, y);
        int startBit = x1 % 8;
        int endByte = getBytePosition(width, x2, y);
        int endBit = x2 % 8;


        //if (startBit != 0)
            screen[startByte] = (unsigned char) (-1 ^ ~((1 << (8 - startBit)) - 1));
        //(1 << (startBit )) - 1;

        if (endBit != 0)  screen[endByte ] = (unsigned char) (~((1 << (8-endBit)) - 1));

        for (int i = startByte+1 ; i < endByte; i++) {
            screen[i] = 0xFF;
        }

        for (int j = 0; j < (size/(width/8)); j++) {
            cout << setw(9) << j << " ";
            for (int i = 0; i < (width/8); i++) {
                cout << std::bitset<8>(screen[j*(width/8)+i]) << " ";
            }
            cout << endl;
            flush(cout);
            flush(cout);
        }
    }
}
using namespace ex58;

int main_EX58(int argc, const char **argv) {

    unsigned char screen[10 * 16] = {0};
    drawLine(screen, 80, 28, 71, 7);

}