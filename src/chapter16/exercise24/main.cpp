//
// Created by crypt on 6/20/16.
//

#include <iostream>
#include <ctime>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

namespace exercise16_24 {

    template<unsigned size>
    vector<pair<int, int>> findAllPairsWithSum(int (&array)[size], int num) {
        // sort
        unordered_map<int, int> cache;
        unordered_map<int, int> result;
        for (int i = 0; i < size; i++) {

            int elm = array[i];
            int candidate = num - elm;
            if (cache.count(candidate) > 0 && cache[candidate] > 0) {
                cache[candidate] -= 1;
                if (elm > candidate)
                    result.emplace(elm, candidate);
                else
                    result.emplace(candidate, elm);
            } else {
                cache[elm] += 1;
            }
        }
        return vector<pair<int, int>>(result.begin(), result.end());
    }

    void main() {
        int const size = 200;
        int array[size] = {0};
        for (int i = 0; i < size; i++) {
            array[i] = -100 + (rand() % 200)+1;
        }
        auto result = findAllPairsWithSum<size>(array, 49);
        int i=0;
        sort(result.begin(), result.end(),
             [](const auto &a, const auto &b) {
                 return a.first < b.first;
             });
        for_each(result.begin(), result.end(),
                 [&i](auto item) {

                     cout << i << ": " << item.first << ", " << item.second << endl;
                     i += 1;
                 });

    }

}
