//
// Created by crypt on 6/5/2016.
//

#include "SortedMerge.h"
#include <queue>
#include <iostream>

using namespace std;
namespace exercise10_1 {

    template<size_t capacity_a, size_t size_b>
    void SortedMerge::sortedMerge(int (&a)[capacity_a], int size_a, int (&b)[size_b]) {
        queue<int> queue;
        size_t i_a = 0, i_b = 0;
        while (i_b < size_b) {
            queue.emplace(a[i_a]);
            if (queue.size() > 0 && (queue.front() <= b[i_b])) {
                a[i_a] = queue.front();
                queue.pop();
            } else {
                a[i_a] = b[i_b];
                i_b++;
            }
            i_a++;
        }

        while (queue.size()) {
            a[i_a] = queue.front();
            queue.pop();
            i_a++;
        }

    }

    void main() {
        int a[] = {0, 1, 2, 3, 5, 7, 11, 13, 17, 19, 23, 31, 37, 41, 43, 47, 53, 57, 59, 999, 999, 999, 999, 999, 999,
                   999};
        int b[] = {1, 8, 9, 10, 60, 62};
        SortedMerge::sortedMerge(a, 19, b);
        for (int i = 0;
             i < 26;
             i++) {
            cout << a[i] << ' ';
        }
        cout << endl;
    }
}