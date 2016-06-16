//
// Created by crypt on 6/13/2016.
//

#include "Philosopher.h"
#include <iostream>

using namespace exercise15_3;
using namespace std;
unsigned Philosopher::Counter = 0;


Philosopher::Philosopher(weak_ptr<Table> table) : table(table) {
    this->id = Philosopher::Counter++;
    cout << "Create Philosoper[" << this->id << "]" << endl;
}

unique_ptr<Philosopher> Philosopher::create(weak_ptr<Table> table) {
    return make_unique<Philosopher>(table);
}

void Philosopher::dine() {
    cout << "Philosoper[" << this->id << "]" << endl;
}

Philosopher::~Philosopher() {
    cout << "Destroy Philosoper[" << this->id << "]" << endl;
}


