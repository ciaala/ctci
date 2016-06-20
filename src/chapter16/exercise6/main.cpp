//
// Created by crypt on 6/20/16.
//

#include <iostream>
#include <ctime>
#include <memory>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

namespace exercise16_6 {


    unique_ptr<vector<int>>

    randomArray(int size) {
        //unique_ptr<int[]> array = make_unique<int[]>();

        vector<int> *v = new vector<int>();

        for (int i = 0; i < size; i++) {
            v->push_back((int) rand());
        }
        unique_ptr<vector<int>> array;
        array.reset(v);
        return array;
    }

    void main() {
        const int SIZE = 100;
        unique_ptr<vector<int>> array1 = randomArray(SIZE);
        unique_ptr<vector<int>> array2 = randomArray(SIZE);
//        const int SIZE = 5;
//        vector<int> *array1 = new vector<int>({1, 3, 15, 11, 2});
//        vector<int> *array2 = new vector<int>({23, 127, 235, 19, 8});
        sort(array1->begin(), array1->end());
        sort(array2->begin(), array2->end());

        int j = 0;
        int diff = INT_MAX;
        int couple1 = INT_MAX;
        int couple2 = INT_MAX;
        for (int i = 0; i < SIZE; i++) {
            while (array1->at(i) > array2->at(j) && j < SIZE) {
                j++;
            }
            int diff_m = abs(array1->at(i) - array2->at(j));
            int diff_l = j > 0 ? abs(array1->at(i) - array2->at(j - 1)) : INT_MAX;
            if ((diff_m < diff_l) && (diff_m < diff)) {
                diff = diff_m;
                couple1 = array1->at(i);
                couple2 = array2->at(j);
            } else if (diff_l < diff) {
                diff = diff_l;
                couple1 = array1->at(i);
                couple2 = array2->at(j - 1);
            }
        }
        for_each(array1->begin(), array1->end(), [](int &n) { cout << n << ", "; });
        cout << endl;
        for_each(array2->begin(), array2->end(), [](int &n) { cout << n << ", "; });
        cout << endl;
        cout << "(" << couple1 << ", " << couple2 << ")" << endl;
    }
}


