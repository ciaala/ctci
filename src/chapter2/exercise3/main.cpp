

#include <list>
#include <unordered_set>
#include <iostream>
#include "library/ListDecorator.h"

using namespace std;
namespace exercise2_3 {

    template<typename T>
    class DeleteMiddleNode : public ListDecorator<T> {
\
    public:
        DeleteMiddleNode() : ListDecorator<T>("DeleteMiddleNode") {

        }

        virtual void execute(list<T> &container) {

            auto middle_node = container.cbegin();
            for (auto it = container.cbegin();
                 it != container.cend();
                 it++, it++, middle_node++) {

            }
            container.erase(middle_node);
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
        DeleteMiddleNode<int> runner;

        runner.run(intList);

    }
}