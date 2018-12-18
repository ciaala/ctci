#include <iostream>
#include <unordered_map>

using namespace std;

namespace exercise_08_01 {

    class CountStairHopes {

    public:
        CountStairHopes(unsigned int maxHops = 3) : maxHops(maxHops) {}

    private:
        unsigned countStairHopes(unsigned length) {
            if (length == 0) {
                return 1;
            } else {
                unsigned int sum = 0;
                for (unsigned i = maxHops; i > 0; i--) {
                    unsigned int currentLength = length - i;
                    if (cache.count(currentLength) > 0) {
                        sum += cache[currentLength];
                    } else {
                        countStairHopes(i);

                    }
                    return sum;
                }
            }

            unordered_map<unsigned, unsigned> cache;
            unsigned int maxHops;
        };


        void main() {
            for (unsigned k = 0; k < 1000l; k++) {
                countStairHopes(k
                );

            }
        }
    };
}