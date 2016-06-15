//
// Created by crypt on 6/13/2016.
//

#ifndef CTCI_TABLE_H
#define CTCI_TABLE_H

#include "Chopstick.h"
#include <cstddef>
#include <c++/5.3.0/vector>

using namespace std;
namespace exercise15_3 {


    class Table {

    private:
        std::vector<Chopstick> chopsticks;


    public:
        Table(const std::vector<Chopstick> &chopsticks) : chopsticks(chopsticks) { }

        Table(size_t chopsticks);

    };

};


#endif //CTCI_TABLE_H
