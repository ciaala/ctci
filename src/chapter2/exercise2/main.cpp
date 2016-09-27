

#include <list>
#include <unordered_set>
#include <iostream>
#include "library/ListDecorator.h"

using namespace std;
namespace exercise2_2 {

    template<typename T>
    class ReturnKthLast : public ListDecorator<T> {
    private:
        int kth_last;
    public:
        ReturnKthLast(int kth_last) : ListDecorator<T>("returnKthLast") {
            this->kth_last = kth_last;
        }

        virtual void execute(list<T> &container) {
            int count = 0;
            auto kth_it = container.cend();
            for (auto it = container.cbegin();
                 it != container.cend();
                 it++) {

                if (count <= this->kth_last) {
                    count++;

                    kth_it = container.cbegin();
                } else {
                    kth_it++;
                }
            }
            T d = *kth_it;
            container.clear();
            container.push_back(d);
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
        ReturnKthLast<int> runner(2);

        runner.run(intList);

    }
}