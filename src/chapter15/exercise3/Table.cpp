//
// Created by crypt on 6/13/2016.
//

#include "Table.h"
#include <iostream>

using namespace exercise15_3;
using namespace std;

unsigned Table::Counter = 0;

Table::~Table() {
    cout << "Destroy Table[" << this->id << "]" << endl;
}

Table::Table(unsigned seats) : seats(seats), chopsticks(seats) {

    this->id = Table::Counter;
    cout << "Create Table[" << this->id << "]" << endl;
}

unique_ptr<Table> Table::create(unsigned seats) {
    return make_unique<Table>(seats);
}

