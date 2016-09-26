//
// Created by Francesco Fiduccia on 26/09/16.
//


#ifndef CTCI_LISTDECORATOR_H
#define CTCI_LISTDECORATOR_H

#include <list>
#include <iostream>
#include <string>


using namespace std;

template<typename T>
class ListDecorator {
private :
    string name;

public:
    ListDecorator(string name) : name(name) {}

    virtual void execute(list<T> &container) = 0;

    void printList(ostream &out, list<T> &container) {
        for (auto it = container.cbegin();
             it != container.cend();
             it++) {
            out << *it;
            if (std::next(it, 1) != container.cend()) {
                out << ", ";
            }
        }
    }

    void run(list<T> &container) {
        cout << "(" << this->name << " ";
        printList(cout, container);
        cout << ")" << endl;
        execute(container);
        cout << " -> (";
        printList(cout, container);
        cout << ")" << endl;
    }


};


#endif //CTCI_LISTDECORATOR_H
