//
// Created by crypt on 24/06/16.
//

#include <iostream>
#include <array>
#include <algorithm>
#include <unordered_map>

using namespace std;
namespace exercise17_5 {
#define myassert(a, b) __myassert(#a, a, b)

    template<typename T>
    void __myassert(const string &expr, T a, T b) {
        if (a != b) {
            cout << "expected: " << expr << "==" << b << ", but found " << a << endl;
        } /*else {
            cout << "good:    " << a << "==" << b;
        }*/
    }

    template<const int size>
    void find(array<bool, size> &sequence) {
        array<unsigned, size> zeroes;
        array<unsigned, size> ones;
        unordered_map<int, int> diff;

        unsigned countedZeroes = 0;
        unsigned countedOnes = 0;
        int max_length = 0;
        int max_start = 0;
        for (int i = 0; i < size; i++) {
            if (sequence[i]) {
                countedOnes++;
            } else {
                countedZeroes++;
            }
            zeroes[i] = countedZeroes;
            ones[i] = countedOnes;
            int _diff = countedOnes - countedZeroes;
            if (diff.count(_diff) > 0) {
                int length = i - diff[_diff];
                if (max_length < length) {
                    max_length = length;
                    max_start = diff[_diff];
                }
            } else {
                diff.emplace(_diff, i);
            }
        }
        cout << "counted: '0' " << countedZeroes << ", '1' " << countedOnes << endl;

        for (int i = 0; i < size; i++) {
            cout << zeroes[i] << "|";

        }
        cout << endl;
        for (int i = 0; i < size; i++) {
            cout << ones[i] << "|";
        }
        cout << endl;

        cout << "start: " << max_start +1 << ", length: " << max_length << endl;
    }


    void main() {
        const int size = 30;
        array<bool, size> sequence = {0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1};
        /*array<bool, size> sequence;
        cout << sizeof(bool) << endl;
        for (auto &item: sequence) {
            item = (bool) (random() % 2);
            cout << item;

        }
        cout << endl;
        */
        for (bool &item : sequence) {
            cout << item;
        }
        cout << endl;

        find<size>(sequence);
    }

}