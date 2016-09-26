

#include <list>
#include <unordered_set>
#include <iostream>
#include "library/ListDecorator.h"

using namespace std;
namespace exercise2_1 {

    template<typename T>
    class ReturnKthLast : public ListDecorator<T> {

    public:
        ReturnKthLast() : ListDecorator<T>("returnKthLast") {}

        virtual void execute(list<T> &container) {

        }

    };

    void main() {
        list<int> intList;
        intList.emplace_back(1);
        intList.emplace_back(2);
        intList.emplace_back(3);
        intList.emplace_back(1);
        intList.emplace_back(4);
        intList.emplace_back(1);
        intList.emplace_back(3);
        intList.emplace_back(5);
        ReturnKthLast<int> runner;

        runner.run(intList);

    }
}