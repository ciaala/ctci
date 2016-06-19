//
// Created by Francesco Fiduccia on 18/06/16.
//
#include <iostream>
#include <thread>
#include <sstream>
#include <stack>
#include <mutex>

namespace exercise15_7 {
    using namespace std;

    template<class T>
    class SharedStack {
    private:
        stack<T> stack1;
        mutex m;
    public:
        T pop() {

            m.lock();
            while (stack1.size() < 1) {
                m.unlock();
                this_thread::yield();
                m.lock();
            }
            T t = stack1.top();
            stack1.pop();
            m.unlock();
            return t;
        }

        void push(T t) {
            m.lock();
            stack1.push(t);
            m.unlock();
        }
    };

    class FBThread {


    private:
        bool shouldDivide3;
        bool shouldDivide5;
        unsigned last;
        shared_ptr<SharedStack<unsigned>> sharedStack;
        thread t;

        void task() {
            unsigned i = 0;
            do {
                i = this->sharedStack->pop();

                bool divide3 = (i % 3 == 0);
                bool divide5 = (i % 5 == 0);

                if ((shouldDivide3 == divide3) && (shouldDivide5 == divide5)) {
                    cout << getMessage(i) << endl;
                    i++;
                }
                sharedStack->push(i);
                this_thread::yield();
            } while (i < this->last);
        }

        string getMessage(unsigned i) {

            if (shouldDivide3 && !shouldDivide5) {
                return "Fizz";
            } else if (shouldDivide3 && shouldDivide5) {
                return "FizzBuzz";
            } else if (!shouldDivide3 && shouldDivide5) {
                return "Buzz";
            } else {
                ostringstream oss;
                oss << i;
                return oss.str();
            }
        }

    public:

        FBThread(shared_ptr<SharedStack<unsigned>> sharedStack, unsigned last, bool divide3, bool divide5) :
                sharedStack(sharedStack),
                last(last),
                shouldDivide3(divide3),
                shouldDivide5(divide5),
                t([this] { this->task(); }) {

        }

        void join() {
            if (t.joinable()) t.join();
            cout << "Joined thread: " << this_thread::get_id() << endl;
        }
    };

    void multiThread(unsigned n) {
        shared_ptr <SharedStack<unsigned>> sharedStack = make_shared<SharedStack<unsigned>>  ();
        sharedStack->push(1);
        unsigned last = n;
        FBThread t3(sharedStack, last, true, false);
        FBThread t5(sharedStack, last, false, true);
        FBThread t15(sharedStack, last, true, true);
        FBThread tn(sharedStack, last, false, false);

        t3.join();
        t5.join();
        t15.join();
        tn.join();
    }

    void singleThread(unsigned n) {
        for (unsigned i = 0; i < n; i++) {
            if ((i % 15) == 0) {
                cout << "FizzBuzz" << endl;
            } else if ((i % 3) == 0) {
                cout << "Fizz" << endl;
            } else if ((i % 5) == 0) {
                cout << "Buzz" << endl;
            } else {
                cout << i << endl;
            }
        }
    }

    void main() {
        unsigned N = 1 << 22;
        //singleThread(N);
        multiThread(N);
    }

}
