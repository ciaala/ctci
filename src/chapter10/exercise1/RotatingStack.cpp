//
// Created by crypt on 6/5/2016.
//

#include "RotatingStack.h"

int RotatingStack::popPush(int value) {

    int r = this->array[this->popIndex];


    this->array[this->popIndex] = value;
    if (this->popIndex == this->end) {
        this->popIndex = 0;
    } else {
        this->popIndex++;
    }

    return r;
}
