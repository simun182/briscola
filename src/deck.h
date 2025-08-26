#pragma once
#include "cards.h"
#include <queue>

class Deck
{
public:
    Deck ();
    void Shuffle ();
    void Print ();
    Card DrawCard ();
    int Size ();
private:
    void Clear();
    std::queue <Card> full_deck;
};