//
// Created by crypt on 6/13/2016.
//

#ifndef CTCI_CHOPSTICK_H
#define CTCI_CHOPSTICK_H

#include <mutex>

using namespace std;
namespace exercise15_3 {


    class Chopstick {
        static unsigned Counter;
        std::mutex mutex0;
        unsigned id;
    public :
        Chopstick();

        bool acquire();

        void release();
        friend ostream &operator<<(ostream &out, Chopstick& chopstick);

    };

};


#endif //CTCI_CHOPSTICK_H
