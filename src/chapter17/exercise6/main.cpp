//
// Created by crypt on 24/06/16.
//

#include <iostream>
#include <array>
#include <algorithm>
#include <unordered_map>

using namespace std;
namespace exercise17_6 {
#define myassert(a, b) __myassert(#a, a, b)

    template<typename T>
    void __myassert(const string &expr, T a, T b) {
        if (a != b) {
            cout << "expected: " << expr << "==" << b << ", but found " << a << endl;
        } /*else {
            cout << "good:    " << a << "==" << b;
        }*/
    }

    int constructiveCount2(int n, int decimalFigure) {
        int count = 0;
        int d = 10;
        int exp_time = 1;
        int x = n;
        while (x > 0) {
            int r = x % d;

            count += r * (exp_time / 10);
            if (r > decimalFigure)
                count += exp_time;
            else if (r == decimalFigure)
                count += (n % exp_time) + 1;

            exp_time = (exp_time+1) * 10;
            cout << x << ": " << count << endl;
            x /= d;
        }
        return count;
    }

    int count2(int x) {
        int count = 0;
        for (int i = 0; i <= x; i++) {
            int d = 10;
            int q = i;
            do {
                if (q % d == 2) count++;
                q = q / d;
            } while (q > 0);
        }
        return count;
    }

    void main() {
        int input = 2222222;
        cout << input << ":" << constructiveCount2(input, 2) << endl;
        cout << input << ":" << count2(input) << endl;
    }

}