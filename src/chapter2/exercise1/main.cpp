

#include <list>
#include <unordered_set>
#include <iostream>

using namespace std;
namespace exercise2_1 {

    template<typename T>
    void removeDuplicate(list<T> &container) {
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

    template<typename T>
    void printList(ostream &out, list<T> &container) {
        for (auto it = container.cbegin();
             it != container.cend();
             it++) {
            out << *it;
            if (std::next(it, 1) != container.cend()) {
                out << ", ";
            }
        }
    }

    template<typename T>
    void printResult(list<T> &container) {
        cout << "(removeDuplicate ";
        printList(cout, container);
        cout << ")" << endl;
        removeDuplicate(container);
        cout << " -> (";
        printList(cout, container);
        cout << ")" << endl;

    }

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
        printResult(intList);

    }
}