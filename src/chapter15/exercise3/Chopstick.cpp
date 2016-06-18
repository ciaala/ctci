//
// Created by crypt on 6/13/2016.
//

#include "Chopstick.h"

namespace exercise15_3 {
    unsigned Chopstick::Counter = 0;

    Chopstick::Chopstick() {
        this->id = Counter++;

    }

    bool Chopstick::acquire() {

        unique_lock<std::mutex> lock0(this->mutex0, defer_lock);

        return lock0.try_lock();
    }

    void Chopstick::release() {
        unique_lock<std::mutex> lock0(this->mutex0, defer_lock);
        if (lock0.owns_lock()) {
            lock0.unlock();
        }
    }
}

