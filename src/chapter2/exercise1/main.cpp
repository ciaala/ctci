

#include <list>
#include <unordered_set>
#include <iostream>
#include "library/ListDecorator.h"

using namespace std;
namespace exercise2_1 {

    template<typename T>
    class RemoveDuplicate : public ListDecorator<T> {

    public:
        RemoveDuplicate() : ListDecorator<T>("removeDuplicate") {}

        virtual void execute(list<T> &container) {
            unordered_set<T> elementSet;
            for (auto it = container.begin();
                 it != container.end();
                 it++) {
                if (elementSet.count(*it) == 0) {
                    elementSet.insert(*it);
                } else {
                    container.erase(it);
                }
            }
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
        RemoveDuplicate<int> runner;

        runner.run(intList);

    }
}