//
// Created by Francesco Fiduccia on 27/09/16.
//

#ifndef CTCI_LINKEDLIST_H
#define CTCI_LINKEDLIST_H

#include <iostream>
#include <string>

using namespace std;

namespace library {
    template<typename T>
    class LinkedListNode {
    private:
        LinkedListNode *next, *prev;
    public:
        LinkedListNode(LinkedListNode<T> *next,
                       LinkedListNode<T> *prev)
                : next(next), prev(prev) {

        }

        LinkedListNode() : next(nullptr), prev(nullptr) {

        }

        bool hasNext() {
            return this->next != nullptr;
        }

        LinkedListNode<T> *getNext() {
            return this->next;
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

        unsigned size() {
            unsigned int
            return;
        }
    };

    template<typename T>
    class LinkedListRunner {
    protected:
        string name;
    public:
        LinkedListRunner(string name) : name(name) {}

        virtual void execute(LinkedListNode<T> &container) = 0;

        virtual void printList(ostream &out, LinkedListNode<T> &container) {
            out << "(";
            while (container.hasNext()) {
                out << container.getNext();
                if (container.hasNext()) {
                    out << ", ";
                }
            }
            out << ")[" << container.size() << "]";
        }

        virtual void run(LinkedListNode<T> &container) {
            cout << "(" << this->name << " ";
            this->printList(cout, container);
            cout << ")" << endl;
            this->execute(container);

            cout << " -> ";
            this->printList(cout, container);
            cout << endl;
        }

    };
}

#endif //CTCI_LINKEDLIST_H
