//
// Created by crypt on 6/15/2016.
//
#include <iostream>
#include <memory>
#include <thread>
#include "Table.h"
#include "Philosopher.h"

using namespace std;
namespace exercise15_3 {
    void main() {
        unsigned seats = 20;
        vector<shared_ptr<Philosopher>> philosophers;
        shared_ptr<Table> table = Table::create(seats);
        for (unsigned i = 0; i < seats; ++i) {

            philosophers.push_back(Philosopher::create(table));
        }
        for (unsigned i = 0; i < seats; ++i) {
            shared_ptr<Philosopher> p = philosophers.at(i);
            std::thread thread1(
                    [p] {
                        p->dine();
                    });
            thread1.detach();
        }
    }


}