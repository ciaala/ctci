//
// Created by Francesco Fiduccia on 18/06/16.
//
#include <iostream>
#include <memory>
#include <thread>


using namespace std;
namespace exercise15_5 {
    class Foo {

    private:
        mutex m;
        unsigned fooLevel;

        void isReady(unsigned level) {
            while (fooLevel < level) {
                this_thread::yield();
            }
            cout << "Reached Level: " << level << endl;
        }

        void increaseLevel() {
            m.lock();
            fooLevel++;
            m.unlock();
        }

    public:
        Foo() : fooLevel(1) {

        };


        void first() {
            isReady(1);
            cout << "first" << endl;
            increaseLevel();
        };

        void second() {
            isReady(2);
            cout << "second" << endl;
            increaseLevel();
        };

        void third() {
            isReady(3);
            cout << "third" << endl;
            increaseLevel();
        };

    };


    void main() {
        Foo foo;

        thread t1([&foo] { foo.first(); });
        thread t2([&foo] { foo.second(); });
        thread t3([&foo] { foo.third(); });

        t1.join();
        t2.join();
        t3.join();
    }
}