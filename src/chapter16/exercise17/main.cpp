//
// Created by crypt on 6/20/16.
//

#include <iostream>
#include <ctime>

using namespace std;

namespace exercise16_17 {

    template<int size>
    int getMaxSum(int a[size]) {
        int maxSum = 0;
        int sum = 0;
        for (int i = 0; i < size; i++) {
            sum += a[i];
            if (maxSum < sum) {
                maxSum = sum;
            } else if (sum < 0) {
                sum = 0;
            }
        }
        return maxSum;hjk
    }

    void main() {
        int array[] = {1, 4, -6, 5, -4, 5, 3, -4, 4, -1, 2, -9, 2};
        cout << getMaxSum<13>(array) << endl;

    }

}
