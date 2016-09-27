#include <list>
#include <iostream>
#include "library/ListDecorator.h"

using namespace std;
namespace exercise2_5 {

    template<typename T>
    class SumDigitList : public ListDecorator<T> {
    private:
        list<T> result;
        list<T> first;
    public:
        SumDigitList(list<T> &first) : ListDecorator<T>("SumDigitList") {
            this->first = first;
        }

        virtual void execute(list<T> &second) {

            auto it1 = first.begin();
            auto it2 = second.begin();
            unsigned extra = 0;
            while (it1 != first.end() || it2 != second.end()) {
                unsigned sum = extra;
                sum += it1 != first.end() ? *it1++ : 0;
                sum += it2 != first.end() ? *it2++ : 0;
                extra = sum / 10;
                unsigned value = sum % 10;
                result.push_back(value);
            }
            if (extra > 0 ) {
                result.push_back(extra);
            }
        }

        virtual void run(list<T> &second) {
            cout << "(" << this->name << " " << endl << "\t";
            this->printList(cout, first);
            cout << endl << "\t";
            this->printList(cout, second);
            this->execute(second);
            cout << ")" << endl << " -> ";
            this->printList(cout, result);
            cout << endl;
        }
    };

    void main() {
        list<unsigned> intList1;
        intList1.emplace_back(1);
        intList1.emplace_back(2);
        intList1.emplace_back(3);
        intList1.emplace_back(1);
        intList1.emplace_back(4);
        intList1.emplace_back(2);
        intList1.emplace_back(1);
        intList1.emplace_back(3);
        intList1.emplace_back(5);
        intList1.emplace_back(1);


        list<unsigned> intList2;
        intList2.emplace_back(4);
        intList2.emplace_back(2);
        intList2.emplace_back(3);
        intList2.emplace_back(2);
        intList2.emplace_back(4);
        intList2.emplace_back(2);
        intList2.emplace_back(4);
        intList2.emplace_back(3);
        intList2.emplace_back(5);
        intList2.emplace_back(8);
        SumDigitList<unsigned> runner(intList1);

        runner.run(intList2);

    }
}