//
// Created by crypt on 6/13/2016.
//

#ifndef CTCI_PHILOSOPHER_H
#define CTCI_PHILOSOPHER_H

#include "Table.h"

namespace exercise15_3 {
    class Philosopher {
        weak_ptr<Table> table;
        static unsigned Counter;
        unsigned id;
        shared_ptr<Seat> seat;
        bool hasDined;

    public:
        void run();

        Philosopher(weak_ptr<Table> table);

        ~Philosopher();

        static unique_ptr<Philosopher> create(weak_ptr<Table> table);

        void dine();

        friend ostream &operator<<(ostream &out, Philosopher &philosopher);

    };


}
#endif //CTCI_PHILOSOPHER_H
