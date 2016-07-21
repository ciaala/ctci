//
// Created by crypt on 19/07/16.
//

#ifndef CTCI_TRINE_H
#define CTCI_TRINE_H

#include <unordered_map>
#include <memory>
#include <string>
using namespace std;

class Trine {
private:
    unordered_map<char, shared_ptr<Trine>> descendants;
    string word;
    char c;
public:

    Trine(char c) : c(c) { }

    Trine(char c, string &word) : c(c), word(word) { }

    void addWord(string word, unsigned int position) {
        char c = word.at(position);
        descendants.emplace(c, make_shared<Trine>(c));
    }
/*
    shared_ptr<Trine> getFirst() {

        // TODO sorted
        if (this->word.length() > 0 )
        {
            return this;
        };
        return descendants.at('c');
    }
    */
};


#endif //CTCI_TRINE_H
