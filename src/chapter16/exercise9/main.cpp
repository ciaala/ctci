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

        static int naiveNegative(int a) {
            int newSign = a > 0 ? -1 : 1;
            int result = 0;
            while (a != 0) {
                result += newSign;
                a += newSign;
            }
            return result;
        }

        static int negative(int a) {
            int newSign = a > 0 ? -1 : 1;
            int result = 0;
            int delta = newSign;
            int counter = 0;
            while (a != 0) {
                result += delta;
                a += delta;
                delta += delta;
                bool signChange = (a + delta) > 0 != (a > 0);
                if (a + delta != 0 && signChange) {
                    delta = newSign;
                }
                counter++;
            }
            return result;
        }

        static int abs(int v) {
            if (v < 0) {
                return negative(v);
            } else {
                return v;
            }
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
            int signDifferent = (other.value > 0 != this->value > 0);
            int operand2;
            if (signDifferent)
                operand2 = negative(other.value);
            else
                operand2 = other.value;
            for (int i = operand2; i > 0; i--) {
                result += value;
            }
            if (signDifferent)
                return negative(result);
            else
                return result;
        }

        Mint operator-(Mint &other) {
            int operand = Mint::negative(other.value);
            int result = this->value + operand;
            return result;
        }

        Mint operator/(Mint &other) {
            int result = 0;

            int signDifferent(other.value > 0 != this->value > 0);
            int operand2 = abs(other.value);
            int operand1 = abs(this->value);
            int temp = operand2;

            while (temp < operand1) {
                temp += operand2;
                result += 1;
            }
            if (signDifferent)
                return negative(result);
            else
                return result;
        }

        friend ostream &operator<<(ostream &ost, const Mint &mint) {
            ost << mint.value << "m ";
            return ost;
        }

    };

    void main() {
        Mint m5 = Mint(50000);
        Mint m4 = Mint(-20000);

        cout << "+: " << m5 + m4 << endl;
        cout << "-: " << m5 - m4 << endl;
        cout << "/: " << m5 / m4 << endl;
        cout << "*: " << m5 * m4 << endl;
    }

}