//
// Created by crypt on 23/07/16.
//

#ifndef CTCI_DOCUMENTRESPACESOLUTION_H
#define CTCI_DOCUMENTRESPACESOLUTION_H

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;
namespace exercise17_13 {
/**
    * DocumentRespaceSolution
    */
    class DocumentRespaceSolution {
    private:
        unordered_map<const string *, DocumentRespaceSolution *> children;
    private:
        const vector<string> &dictionary;
        const string &document;
        unordered_map<unsigned long, string> words;
        unsigned long position;
    public:
        unsigned long getPosition() const;

    private:
        unsigned int freeSpace;


    public:


        DocumentRespaceSolution *duplicate(const string *str = nullptr);

        DocumentRespaceSolution(const string &document, const vector<string> &dictionary);

        friend ostream &operator<<(ostream &ost, const DocumentRespaceSolution &solution);

        void branch();

        const unordered_map<const string *, DocumentRespaceSolution *> &getChildren() const;

        unsigned int getFreeSpace() const;
    };
/*
        lookForWord(unsigned long position, unsigned long length) {

            string prefix = solution->document.substr(position, length);
            for (const string &s: dictionary) {
                if (prefix.compare(0, prefix.length(), s) == 0) {
                    return s;
                }
            }
            return SNONE;
        }
        */


}

#endif //CTCI_DOCUMENTRESPACESOLUTION_H
