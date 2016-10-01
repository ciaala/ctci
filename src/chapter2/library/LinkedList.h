//
// Created by Francesco Fiduccia on 27/09/16.
//

#ifndef CTCI_LINKEDLIST_H
#define CTCI_LINKEDLIST_H

namespace library {
    template<typename T>
    class LinkedListNode<T> {
    private:
        LinkedListNode *next, *prev;
    public:
        LinkedListNode(LinkedListNode<T> *next,
                       LinkedListNode<T> *prev)
                : next(next), prev(prev) {

        }

        LinkedListNode() : next(nullptr), prev(nullptr) {

        }

        void setNext(LinkedListNode<T> *next) {
            if (this->next != nullptr) {
                this->next->prev = next;
            }
            next->next = this->next;
            next->prev = this;
            this->next = next;
        }

        void setPrev(LinkedListNode<T> *prev) {
            if (this->prev != nullptr) {
                this->prev->next = prev;
            }
            prev->prev = this->prev;
            prev->next = this;
            this->prev = prev;
        }

    };

}


#endif //CTCI_LINKEDLIST_H
