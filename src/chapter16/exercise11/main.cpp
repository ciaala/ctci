//
// Created by crypt on 6/20/16.
//

#include <iostream>
#include <ctime>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

namespace exercise16_11 {

    vector<int> *getAllLength(int k, int longer, int shorter) {
        unordered_set<int> lengths;
        for (int i = k; i > 0; i--) {
            int length = (i * longer) + (k - i) * shorter;
            lengths.insert(length);
        }
        return new vector<int>(lengths.begin(), lengths.end());
    }

    void main() {

        vector<int> *lengths = getAllLength(20, 29, 12);
        for_each(lengths->begin(), lengths->end(), [](int &n) { cout << n << ", "; });
        cout << endl;
        delete lengths;

    }

}
