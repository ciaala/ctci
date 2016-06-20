//
// Created by crypt on 6/20/16.
//

#include <iostream>
#include <ctime>

using namespace std;

namespace exercise16_10 {
    class Person {

    public:
        void reset() {
            this->born = (rand() % 100);
            this->death = this->born + (rand() % 150);
        }

        int born;
        int death;
    };


    class Demographic {
        int born[300] = {0};
        int death[300] = {0};
        int living[300] = {0};
    public :
        Demographic() {

        }

        void track(Person &person) {
            this->born[person.born ]++;
            this->death[person.death +1]++;
        }

        int getMostPopulatedYear() {
            int mostPopulated = 0;
            for (int i = 0; i < 300; i++) {
                living[i] = i > 0 ? living[i - 1] : 0;
                living[i] += (born[i] - death[i]);
                mostPopulated = living[mostPopulated] < living[i] ? i : mostPopulated;
            }
            return mostPopulated + 1900;
        }

        int getLiving(int year) {
            return living[year - 1900];
        }
    };


    void main() {
        unsigned N = 2000000000;
        Demographic demo;
        Person p;
        for (unsigned i = 0; i < N; i++) {
            p.reset();
            demo.track(p);
        }
        int year = demo.getMostPopulatedYear();
        cout << year << ": " << demo.getLiving(year) << endl;

    }

}
