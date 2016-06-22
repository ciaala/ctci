//
// Created by crypt on 6/20/16.
//

#include <iostream>
#include <ctime>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

namespace exercise16_19 {

    template<unsigned size>
    class PondFinder {
        unordered_map<int, int> cellPond;
        unordered_map<int, vector<int>> pondCells;
        unsigned (&matrix)[size][size];

    public:
        PondFinder(unsigned (&matrix)[size][size]) : matrix(matrix) {

        }

        /**
         * Potentially it merge ponds
         */
        int findTopAdjacentPond(int cellIndex) {
            if (cellIndex >= size) {
                int topIndex = cellIndex - size;
                if (cellPond.count(topIndex)) {
                    return cellPond[topIndex];
                } else {

                    bool isLefTopPond = ((topIndex % size) > 0) ? (cellPond.count(topIndex - 1) > 0) : false;
                    bool isRightTopPond = (((topIndex + 1) % size) != 0) ? (cellPond.count(topIndex + 1) > 0) : false;

                    if (isLefTopPond && isRightTopPond) {
                        return mergePonds(cellPond[topIndex + 1], cellPond[topIndex - 1]);
                    } else if (isLefTopPond) {
                        return cellPond[topIndex - 1];
                    } else if (isRightTopPond) {
                        return cellPond[topIndex + 1];
                    }
                }
            }
            return -1;
        }

        int mergePonds(int current_pond, int top_pond) {
            // The older wins
            // But it should be best for performance to use the bigger pond
            int result = current_pond > top_pond ? top_pond : current_pond;
            int removed = (result == top_pond) ? current_pond : top_pond;
            vector<int> data = pondCells[removed];

            for_each(data.begin(),
                     data.end(),
                     [&](auto item) {
                         cellPond[item] = result;
                         pondCells[result].push_back(item);
                     }
            );
            pondCells.erase(removed);
            return result;
        }

        vector<unsigned long>

        getPondsSize() {

            vector<unsigned long> results;
            int current_pond = -1;
            int pondCounter = 1;
            for (unsigned i = 0; i < size; i++) {
                for (unsigned j = 0; j < size; j++) {
                    if (matrix[i][j] == 0) {
                        int index = i * size + j;
                        int top_pond = findTopAdjacentPond(index);
                        if (current_pond > 0 && top_pond > 0) {
                            if (current_pond != top_pond) {
                                current_pond = mergePonds(current_pond, top_pond);
                            }
                            // same value continue
                        } else if (current_pond > 0 && top_pond < 0) {
                            pondCells.insert({current_pond, {index}});
                        } else if (current_pond < 0 && top_pond > 0) {
                            current_pond = top_pond;
                        } else {
                            current_pond = pondCounter++;
                        }
                        cellPond[index] = current_pond;
                        if (pondCells.count(current_pond) > 0) {
                            pondCells[current_pond].push_back(index);
                        } else {
                            pondCells.insert({current_pond, {index}});
                        }
                    } else {
                        current_pond = -1;
                    }
                }
                current_pond = -1;
            }
            for_each(pondCells.begin(), pondCells.end(),
                     [&](auto item) {
                         results.push_back(item.second.size());
                     });

            /*
             * PRINT THE map cell to pond
             *
            cout << endl;
            for_each(cellPond.cbegin(), cellPond.cend(),
                     [&](auto item) {
                         cout << item.first << " " << item.second << endl;
                         //results.push_back(cellPond.count(item.first));
                     });
            cout << endl;
            */
            return results;
        }
    };

    void main() {
        const int size = 5;
        unsigned matrix[size][size] = {
                {0, 2, 1, 0, 1},
                {0, 1, 0, 1, 0},
                {1, 1, 0, 1, 1},
                {0, 1, 0, 1, 2},
                {1, 0, 1, 1, 0}
        };

        PondFinder<size> pf(matrix);
        cout << "Pond sizes: ";
        for (auto elm :pf.getPondsSize()) {
            cout << elm << ", ";
        }
        cout << endl;
    }

}
