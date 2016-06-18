//
// Created by crypt on 6/13/2016.
//

#include "Table.h"
#include <iostream>


using namespace std;
namespace exercise15_3 {
    unsigned Table::Counter = 0;

    Table::~Table() {
        cout << "Destroy Table[" << this->id << "]" << endl;

    }

    Table::Table(unsigned seats) {

        this->id = Table::Counter;
        cout << "Create Table[" << this->id << "]" << endl;
        for (unsigned i = 0; i < seats; ++i) {
            chopsticks.push_back(make_shared<Chopstick>());
        }

        shared_ptr<Chopstick> left;
        shared_ptr<Chopstick> right = chopsticks[0];

        for (unsigned i = 0; i < seats; ++i) {
            left = right;
            right = chopsticks[(i + 1) % seats];
            this->seats.push_back(make_shared<Seat>(left, right));
            //this->seats.emplace_back(left, right);

        }
        this->free_seats_iterator = this->seats.begin();
    }

    unique_ptr<Table> Table::create(unsigned seats) {
        return make_unique<Table>(seats);

    }

    shared_ptr<Seat> Table::getFreeSeat() {
        if (this->free_seats_iterator != this->seats.end())
            return *(this->free_seats_iterator++);
        else
            throw std::out_of_range("There are no more seats");
    }
}