//
// Created by crypt on 24/06/16.
//

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;


namespace exercise17_13 {
#define myassert(a, b) __myassert(#a, a, b)

    /**
     * DocumentRespaceSolution
     */
    class DocumentRespaceSolution {

    public:
        DocumentRespaceSolution(const string &document)
                : document(document), freeSpace(0) {

        }

        const string &document;
        unordered_map<unsigned long, const string &> words;
        unsigned int freeSpace;

        friend ostream &operator<<(ostream &ost, const DocumentRespaceSolution &solution) {
            ost << "space: " << solution.freeSpace << ", document: ";
            vector<unsigned long> positions = vector<unsigned long>(solution.words.begin(), solution.words.end());

            return ost;
        }
    };

    /**
     * DocumentRespace
     */
    class DocumentRespace {
        const vector<string> &dictionary;

        static const string SNONE;
        bool debug;

    private:
        string getNext(string word) {

        }

        void buildSolution(DocumentRespaceSolution *solution, unsigned long position = 0) {
            solution->freeSpace = 0;

            while (position < solution->document.length()) {
                //if (solution->words) {
                long diff = solution->document.length() - position;
                unsigned int proposedLength = 1;
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
                        solution->words.emplace(position, nextWord);
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

        const string &lookForWord(DocumentRespaceSolution *solution, unsigned long position, unsigned long length) {

            string prefix = solution->document.substr(position, length);
            for (const string &s: dictionary) {
                if (prefix.compare(0, prefix.length(), s) == 0) {
                    return s;
                }
            }
            return SNONE;
        }

    public:

        DocumentRespace(
                const vector<string> &dictionary) :
                dictionary(dictionary) {

        }


        string respace(const string &document) {
            int spaces = INT32_MAX;
            DocumentRespaceSolution *solution = new DocumentRespaceSolution(document);
            DocumentRespaceSolution *best;
            bool solutionIsLast = false;
            while (spaces != 0 && !solutionIsLast) {

                buildSolution(solution);
                if (debug) {
                    cout << solution << endl;
                }
                if (spaces > solution->freeSpace) {
                    best = solution;
                    spaces = best->freeSpace;
                }
                solutionIsLast = solution != nullptr;
            }
            return "";
        }

        bool isDebug() const {
            return debug;
        }

        void setDebug(bool debug) {
            DocumentRespace::debug = debug;
        }

    };

    const string DocumentRespace::SNONE = "";

    void main() {
        const vector<string> dictionary = {"i", "love", "maccheroni", "pasta", "pastaasciutta", "pazza", "pizza"};
        string document = "ilovepastasciuttamorethanpizza";
        DocumentRespace sr(dictionary);
        cout << sr.respace(document);
    }

}

