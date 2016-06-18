//
// Created by crypt on 6/16/2016.
//

#include "Seat.h"

namespace exercise15_3 {
    Seat::Seat(shared_ptr<Chopstick> _left, shared_ptr<Chopstick> _right) :
            left(_left),
            right(_right) {
    }

    shared_ptr<Chopstick> Seat::getLeftChopstick() {
        return this->left;
    }

    shared_ptr<Chopstick> Seat::getRightChopstick() {
        return this->right;
    }


}