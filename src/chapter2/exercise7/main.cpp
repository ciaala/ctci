#include <list>
#include <iostream>
#include "library/LinkedList.h"

using namespace std;
using namespace library;
namespace exercise2_7 {

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

        LinkedListNode<unsigned> first(3);
        first.setNext(new LinkedListNode<unsigned>(5));
        first.getNext()->setPrev(new LinkedListNode<unsigned>(7));
        first.getNext()->setNext(new LinkedListNode<unsigned>(9));
        IntersectionChecker<unsigned> checker = IntersectionChecker<unsigned>();
        checker.run(first);
    }
}