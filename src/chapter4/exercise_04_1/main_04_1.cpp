#include <iostream>

#include "../library/AVLTree.h"

using namespace std;
namespace exercise_04_1 {


    void main_04_1() {
        cout << "chapter 04 - exercise 01 - START" << endl;
        AVLTree<unsigned> tree;
        for (unsigned i = 0; i < 32; i++) {
            tree.addValue(i);
            cout << tree << endl << endl;
        }

    }


};