#include <list>
#include <iostream>
#include "library/LinkedList.h"

using namespace std;
using namespace library;
namespace exercise2_6 {

    template<typename T>
    class IntersectionChecker : public LinkedListRunner<T> {
    private:
        bool result;
    public:
        IntersectionChecker() : LinkedListRunner<T>("LinkedList Intersection") {}

        virtual void execute(LinkedListNode<T> &container) {

        }
    };


    void main() {

        LinkedListNode<unsigned> first;
        IntersectionChecker<unsigned> checker = IntersectionChecker<unsigned>();
        checker.run(first);
    }
}