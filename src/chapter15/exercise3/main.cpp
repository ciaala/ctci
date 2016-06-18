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
        unsigned PHILOSOPERS = 20;
        vector<shared_ptr<Philosopher>> philosophers;
        shared_ptr<Table> table = Table::create(PHILOSOPERS);
        vector<std::thread *> threads;
        for (unsigned i = 0; i < PHILOSOPERS; ++i) {
            philosophers.push_back(Philosopher::create(table));
        }
        cout << "Created " << philosophers.size() << " philosophers" << endl;
        for (unsigned i = 0; i < PHILOSOPERS; ++i) {


            std::thread *thread0 = new thread(
                    [i, &philosophers] {
                        shared_ptr<Philosopher> p = philosophers.at(i);
                        p->dine();
                        // ->dine();
                    });

            threads.push_back(thread0);
        }
/*
        for (auto thread0 : threads) {
            thread0->detach();
        }
        */
        for (auto thread0 : threads) {
            if (thread0->joinable())
                thread0->join();
            delete thread0;
        }
/**/
    }


}