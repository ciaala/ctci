//
// Created by crypt on 6/13/2016.
//

#include "Philosopher.h"
#include <iostream>
#include <sstream>
#include <thread>

using namespace std;

namespace exercise15_3 {
    unsigned Philosopher::Counter = 0;


    Philosopher::Philosopher(weak_ptr<Table> table) :
            table(table),
            hasDined(false) {
        this->id = Philosopher::Counter++;
        cout << "Create Philosoper[" << this->id << "]" << endl;
        this->seat = table.lock()->getFreeSeat();
    }

    unique_ptr<Philosopher> Philosopher::create(weak_ptr<Table> table) {
        return make_unique<Philosopher>(table);
    }

    void Philosopher::dine() {
        cout << "Trying to dine " << *this << endl;

        while (!hasDined) {
            shared_ptr<Chopstick> left = this->seat->getLeftChopstick();
            if (left != nullptr && left->acquire()) {
                cout << *this << " has got the left " << *left << endl;
                shared_ptr<Chopstick> right = this->seat->getRightChopstick();
                if (right != nullptr && right->acquire()) {
                    cout << *this << " has got the right " << *right<< endl;
                    cout << "Philosopher[" << this->id << "] dined" << endl;
                    this->hasDined = true;
                    right->release();
                }
                left->release();
            }
            this_thread::yield();
            this_thread::sleep_for(1s);
        }

    }

    Philosopher::~Philosopher() {
        cout << "Destroy Philosoper[" << this->id << "]" << endl;
    }


    ostream &operator<<(ostream &out, Philosopher &philosopher) {
        ostringstream oust;
        oust << "Philosopher[" << philosopher.id << "]";
        return out << oust.str();
    }

}