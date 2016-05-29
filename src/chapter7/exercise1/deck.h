//
// Created by crypt on 5/29/2016.
//

#ifndef CTCI_DECK_H
#define CTCI_DECK_H

#include <vector>
#include "Card.h"

class Deck {
    vector<Card> discarded;
    vector<Card> inGame;
    vector<Card> deck;

private:
    void shuffle(vector<Card> &cards);

public :
    void shuffleInGame();

    void restart();

    void top();

    Card pick();

    void discard();

};


#endif //CTCI_DECK_H
