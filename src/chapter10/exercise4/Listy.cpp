//
// Created by crypt on 6/6/2016.
//

#include <memory>
#include <cstdlib>
#include "Listy.h"

using namespace std;

int Listy::getElementAt(size_t index) {
    if (index > this->capacity) {
        return -1;
    } else {
        this->array[index];
    }
}

Listy::Listy(size_t _capacity) :
        capacity(_capacity),
        array(make_unique<int[]>(_capacity)) {

    int v = 0;
    for (size_t i = 0; i < _capacity; i++) {
        v += (rand() % 4);
        array[i] = v;
    }
    //
}
