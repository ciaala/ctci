//
// Created by crypt on 6/16/2016.
//

#include "Seat.h"

namespace exercise15_3 {
    Seat::Seat(shared_ptr<Chopstick> left, shared_ptr<Chopstick> right) :
            left(left),
            right(right) {
    }

    weak_ptr<Chopstick> Seat::getLeftChopstick() {
        return this->left;
    }

    weak_ptr<Chopstick> Seat::getRightChopstick() {
        return this->right;
    }


}