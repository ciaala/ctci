//
// Created by crypt on 24/06/16.
//
#include <cassert>
#include <iostream>

using namespace std;
namespace exercise17_1 {
#define myassert(a, b) __myassert(#a, a, b)

    template<typename T>
    void __myassert(const string &expr, T a, T b) {
        if (a != b) {
            cout << "expected: " << expr << "==" << b << ", but found " << a << endl;
        } /*else {
            cout << "good:    " << a << "==" << b;
        }*/
    }

    int sum(int a, int b) {
        int extra = b;
        int result = a;

        do {
            int tmp = result & extra;
            result = result ^ extra;

            extra = tmp << 1;
        } while (extra > 0);
        return result;
    }

    void main() {
        myassert(sum(10, -1), 9);
        myassert(sum(210, 215), 425);
        myassert(sum(-211, -215), -426);
        myassert(sum(-210, -215), -425);
        myassert(sum(-210, 215), 5);
        myassert(sum(-210, 214), 4);
        myassert(sum(212, -213), -1);

    }

}