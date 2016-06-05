//
// Created by crypt on 6/5/2016.
//

#ifndef CTCI_SORTEDMERGE_H
#define CTCI_SORTEDMERGE_H

#include <cstddef>

namespace exercise10_1 {

    class SortedMerge {
    public:
        template<size_t capacity_a, size_t size_b>
        static void sortedMerge(int(&a)[capacity_a], int size_a, int(&b)[size_b]);
    };

    void main();

}
#endif //CTCI_SORTEDMERGE_H
