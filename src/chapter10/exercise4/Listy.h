//
// Created by crypt on 6/6/2016.
//

#ifndef CTCI_LISTY_H
#define CTCI_LISTY_H

#include <memory>

#include <cstddef>

using namespace std;

class Listy {
private:
    size_t capacity;
    unique_ptr<int[]> array;
public:
    Listy(size_t capacity);

    int getElementAt(size_t index);
};


#endif //CTCI_LISTY_H
