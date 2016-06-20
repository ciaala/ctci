//
// Created by crypt on 6/20/16.
//

#include <iostream>
#include <ctime>
#include <climits>

using namespace std;

namespace exercise16_9 {

    class Mint {
        const int value;

        static int negative(int a) {
            int newSign = a > 0 ? -1 : 1;
            int result = 0;
            while (a != 0) {
                result += newSign;
                a += newSign;
            }
            return result;
        }

    public:
        Mint(int value) : value(value) {

        }

        Mint operator+(Mint &other) {
            int result = this->value + other.value;
            return result;
        }

        Mint operator*(Mint &other) {
            int result = 0;
            for (int i = other.value; i > 0; i--) {
                result += value;
            }
            return result;
        }

        Mint operator-(Mint &other) {
            int operand = Mint::negative(other.value);
            int result = this->value + operand;
            return result;
        }

        Mint operator/(Mint &other) {
            int result = 0;
            int temp = other.value;
            while (temp < value) {
                temp += other.value;
                result += 1;
            }
            return result;
        }

        friend ostream &operator<<(ostream &ost, const Mint &mint) {
            ost << mint.value << "m ";
            return ost;
        }

    };

    void main() {
        Mint m5 = Mint(5);
        Mint m4 = Mint(4);

        cout << "+: " << m5 + m4 << endl;
        cout << "-: " << m5 - m4 << endl;
        cout << "/: " << m5 / m4 << endl;
        cout << "*: " << m5 * m4 << endl;
    }

}