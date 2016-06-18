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
        unsigned PHILOSOPHERS = 20;
        vector<shared_ptr<Philosopher>> philosophers;
        shared_ptr<Table> table = Table::create(PHILOSOPHERS);
        vector<std::thread *> threads;
        for (unsigned i = 0; i < PHILOSOPHERS; ++i) {
            philosophers.push_back(Philosopher::create(table));
        }
        cout << "Created " << philosophers.size() << " philosophers" << endl;
        for (unsigned i = 0; i < PHILOSOPHERS; ++i) {


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
            if (thread0->joinable()) {
                thread0->join();
                cout << "Thread["  << thread0->get_id() << "] joined" << endl;


        }
            delete thread0;
        }
/**/
    }


}