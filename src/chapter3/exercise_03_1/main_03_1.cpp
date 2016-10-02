#include <iostream>
#include <stack>

using namespace std;
namespace exercise3_1 {

    template<typename T, unsigned arraySizeKilobytes = 4, unsigned stacks = 3>
    class MultipleStackInArray {
        T array[arraySizeKilobytes * 1024];
        unsigned arrayIndex[stacks];
        unsigned slice;
    public:
        MultipleStackInArray() {
            this->slice = (arraySizeKilobytes * 1024) / stacks;
            for (unsigned index = 0; index < stacks; index++) {
                unsigned startPosition = this->slice * index;
                arrayIndex[index] = startPosition;
            }
        }

        T peek(unsigned stack) {
            if (stack < stacks) {
                return array[arrayIndex[stack] - 1];
            } else {
                cerr << "Stack " << stack << ", peek out of slice " << arrayIndex[stack] << endl;
            }
        }

        void pop(unsigned stack) {
            if (arrayIndex[stack] > (stack * slice)) {
                arrayIndex[stack] = arrayIndex[stack] - 1;
            } else {
                cerr << "Stack " << stack << ", pop out of slice " << arrayIndex[stack] << endl;
            }
        }

        void push(unsigned stack, T value) {
            if (arrayIndex[stack] < (((stack + 1) * slice) + 1)) {
                array[arrayIndex[stack]] = value;
                arrayIndex[stack] = arrayIndex[stack] + 1;
            } else {
                cerr << "Stack " << stack << ", push out of slice " << arrayIndex[stack] << endl;
            }
        }
    };

#define STACK_FILL 1365

    void main_03_1() {

        cout << "chapter3 - exercise 01 - START" << endl;
        MultipleStackInArray<unsigned> stacks = MultipleStackInArray<unsigned>();
        for (unsigned s = 0; s < 3; s++) {
            for (unsigned j = 0; j < STACK_FILL; j++) {
                stacks.push(s, (s + 1) * j);
            }
        }
        for (unsigned s = 0; s < 3; s++) {
            for (unsigned j = STACK_FILL; j != 0; j--) {
                unsigned stacked = stacks.peek(s);
                unsigned value = (s + 1) * (j - 1);
                if (stacked != value) {
                    cout << "( " << s << ", " << j << " ) ";
                    cout << (stacked == value ? "OK" : "NO");
                    cout << " " << value;
                    cout << (stacked == value ? " == " : " != ") << stacked << endl;
                }
                stacks.pop(s);
            }
        }
        cout << "chapter3 - exercise 01 - END" << endl;
        cout << endl;
    }
}