//
// Created by crypt on 6/13/2016.
//

#ifndef CTCI_TABLE_H
#define CTCI_TABLE_H

#include "Chopstick.h"
#include <cstddef>
#include <memory>
#include <vector>

using namespace std;

namespace exercise15_3 {


    class Table {

    private:
        std::vector<Chopstick> chopsticks;
        unsigned seats;
        unsigned id;
        static unsigned Counter;

    public:
        Table(unsigned seats);

        ~Table();

        static unique_ptr<Table> create(unsigned seats);
    };

};


#endif //CTCI_TABLE_H
