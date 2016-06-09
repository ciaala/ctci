//
// Created by crypt on 6/6/2016.
//

#include <cstdlib>
#include "Listy.h"
#include <iostream>

size_t searchSortedNoSize(Listy &listy, int e) {
    int inc = 0;
    int index = 0;
    do {
        int v = listy.getElementAt(index + (1 << inc));
        if (v < e) {
            index += 1 << (inc - 1);
            inc = 0;
        }
    } while (e != listy.getElementAt(index) && listy.getElementAt(index) != -1);

    if (e == listy.getElementAt(index)) {
        return index;
    }
    return -1;
}


namespace exercise10_4 {
    void main() {
        Listy listy(1024);
        int e = listy.getElementAt(31);
        for (size_t i = 0; i < 32; i++) {
            cout << listy.getElementAt(i) << endl;
        }
        cout << "looking for " << e << endl;

        size_t index = searchSortedNoSize(listy, e);

        cout << "Found at index: " << index << "." << endl;
    }
}
