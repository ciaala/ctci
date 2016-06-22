//
// Created by crypt on 6/20/16.
//

#include <iostream>
#include <ctime>
#include <unordered_map>

using namespace std;

namespace exercise16_21 {

    template<unsigned size>
    int sumArray(int (&array)[size], unordered_map<int, int> *array_2_cache = nullptr) {
        int sum = 0;
        for (int i = 0; i < size; i++) {
            sum += array[i];
            if (array_2_cache) {
                array_2_cache->insert({array[i], i});
            }
        }
        return sum;
    }


    template<unsigned size>
    std::pair<int, int> getCoupleToSwap(int (&array1)[size], int (&array2)[size]) {
        int sum_1 = sumArray(array1);
        unordered_map<int, int> array_2_cache;
        int sum_2 = sumArray(array2, &array_2_cache);
        if (((sum_1 + sum_2) % 2) == 0) {
            int final_sum = (sum_1 + sum_2) / 2;
            for (int i = 0; i < size; i++) {
                int elm_1 = array1[i];
                int elm_2 = (sum_2 + elm_1) - final_sum;
                if (array_2_cache.count(elm_2) > 0)
                    return {elm_1, elm_2};
            }

        }
        return std::pair<int, int>();
    }

    void main() {
        int array1[] = {4, 1, 2, 1, 3, 2};
        int array2[] = {3, 6, 3, 3, 1, 1};
        auto pab = getCoupleToSwap<6>(array1, array2);
        cout << pab.first << "," << pab.second << endl;
    }

}
