#include <list>
#include <iostream>
#include "library/ListDecorator.h"

using namespace std;
namespace exercise2_4 {

    template<typename T>
    class PartitionList : public ListDecorator<T> {
    private:
        T partitionValue;
    public:
        PartitionList(T value) : ListDecorator<T>("PartitionList") {
            this->partitionValue = value;
        }

        virtual void execute(list<T> &container) {

            auto it = container.begin();


            while (it != container.end()) {
                //
                if (partitionValue > *it) {
                    cout << "pushing to front " << *it << " front: " << container.front() << endl ;

                    container.push_front(*it);
                    container.erase(it);
                }
                it++;

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
        intList.emplace_back(2);
        intList.emplace_back(1);
        intList.emplace_back(3);
        intList.emplace_back(5);
        intList.emplace_back(1);

        PartitionList<int> runner(3);

        runner.run(intList);

    }
}