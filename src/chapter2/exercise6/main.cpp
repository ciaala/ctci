#include <list>
#include <iostream>
#include "library/ListDecorator.h"

using namespace std;
namespace exercise2_6 {

    template<typename T>
    class PalindromeChecker : public ListDecorator<T> {
    private:
        bool result;
    public:
        PalindromeChecker() : ListDecorator<T>("PalindromeChecker") {}

        virtual void execute(list<T> &container) {

            auto front = container.cbegin();
            auto back = container.crbegin();
            int halfLength = container.size()/2;
            while ((*front == *back) && halfLength >= 0) {
                front++;
                back++;
                halfLength--;
            }
            result = halfLength <= 0;
        }

        virtual void run(list<T> &container) {
            cout << "(" << this->name << " ";
            this->printList(cout, container);
            cout << ")" << endl;
            this->execute(container);
            cout << " -> ";
            cout << this->result << endl;
        }
    };

    void main() {
        PalindromeChecker<unsigned> runner;
        list<unsigned> list1;
        list1.emplace_back(1);
        list1.emplace_back(2);
        list1.emplace_back(3);
        list1.emplace_back(1);
        list1.emplace_back(4);
        list1.emplace_back(2);
        list1.emplace_back(1);
        list1.emplace_back(3);
        list1.emplace_back(5);
        list1.emplace_back(1);


        runner.run(list1);
        list<unsigned> list2;
        list2.emplace_back(1);
        list2.emplace_back(2);
        list2.emplace_back(3);
        list2.emplace_back(1);
        list2.emplace_back(4);
        list2.emplace_back(1);
        list2.emplace_back(3);
        list2.emplace_back(2);
        list2.emplace_back(1);
        runner.run(list2);
    }
}