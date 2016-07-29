//
// Created by crypt on 23/07/16.
//

#ifndef CTCI_DOCUMENTRESPACEALGORITHM_H
#define CTCI_DOCUMENTRESPACEALGORITHM_H

#include <string>
#include <vector>
using namespace std;
namespace exercise17_13 {
/**
 * DocumentRespaceAlgorithm
 */

    class DocumentRespaceAlgorithm {

        const vector <string> &dictionary;

        //static const string SNONE;
        bool debug;

    private:
        string getNext(string word) {

        }
/*
        void buildSolution(DocumentRespaceSolution *solution, unsigned long position = 0) {
            solution->freeSpace = 0;

            while (position < solution->document.length()) {
                //if (solution->words) {

                if (solution->words.count(position) > 0) {
                    proposedLength = (unsigned) solution->words.at(position).length() + 1;
                }
                string nextWord;
                for (unsigned int length = proposedLength;
                     length < diff && length < solution->document.length();
                     length++) {
                    nextWord = lookForWord(solution, position, length);
                    if (nextWord.length() > 0) {
                        cout << position << ": " << nextWord << endl;
                        solution->words[position] = nextWord;
                        position += nextWord.length();
                        break;
                    }
                    // }
                }
                if (nextWord.length() == 0) {
                    position += 1;
                    solution->freeSpace += 1;
                }
            }
        }

*/
    public:

        DocumentRespaceAlgorithm(const vector <string> &dictionary) :
                dictionary(dictionary), debug(true){

        }


        string respace(const string &document);

        bool isDebug() const {
            return debug;
        }

        void setDebug(bool debug) {
            this->debug = debug;
        }

    };


}


#endif //CTCI_DOCUMENTRESPACEALGORITHM_H
