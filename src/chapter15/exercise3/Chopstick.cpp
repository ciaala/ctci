//
// Created by crypt on 6/13/2016.
//

#include "Chopstick.h"
#include <ostream>
#include <sstream>

namespace exercise15_3 {
    unsigned Chopstick::Counter = 0;

    Chopstick::Chopstick() {
        this->id = Counter++;

    }

    bool Chopstick::acquire() {
        return this->mutex0.try_lock();
        /*unique_lock<std::mutex> lock0(this->mutex0, defer_lock);

        return lock0.try_lock();*/
    }

    void Chopstick::release() {
        /* unique_lock<std::mutex> lock0(this->mutex0, defer_lock);
         if (lock0.owns_lock()) {
             lock0.unlock();
         }
         */
        mutex0.unlock();
    }

    ostream &operator<<(ostream &out, Chopstick &chopstick) {
        ostringstream ost;
        ost << "Chopstick[" << chopstick.id << ']';
        return out << ost.str();
    }


}

