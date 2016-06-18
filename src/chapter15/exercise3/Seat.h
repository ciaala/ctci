//
// Created by crypt on 6/16/2016.
//

#ifndef CTCI_SEAT_H
#define CTCI_SEAT_H

#include <memory>
#include "Chopstick.h"

using namespace std;

namespace exercise15_3 {
    class Seat {
    private:
        shared_ptr<Chopstick> left;
        shared_ptr<Chopstick> right;
    public:
        Seat(shared_ptr<Chopstick> left, shared_ptr<Chopstick> right);

        shared_ptr<Chopstick> getLeftChopstick();

        shared_ptr<Chopstick> getRightChopstick();

    };
}

#endif //CTCI_SEAT_H
