#include "deck.h"
#include <random>
#include <vector>
#include <iostream>

Deck::Deck ()
{
    Clear();
    
    for (const char type : {'B', 'C', 'D', 'S'})
    {
        int value[] = {1, 2, 3, 4, 5, 6, 7, 11, 12, 13};
        for (int v : value)
        {
            full_deck.push ({type, v});
        }
    }
}

void Deck::Shuffle ()
{
    std::vector<Card> cards;
    while (!full_deck.empty()) {
        cards.push_back(full_deck.front());
        full_deck.pop();
    }

    for (size_t i = 0; i < cards.size (); i ++)
    {
        size_t j = rand () % cards.size ();
        std::swap (cards [i], cards [j]);
    }

    for (auto card : cards) {
        full_deck.push(card);
    }
}

void Deck::Print ()
{
    std::vector<Card> cards;
    while (!full_deck.empty()) {
        cards.push_back(full_deck.front());
        full_deck.pop();
    }

    std::cout << cards.size() << " cards: ";
    for (auto card : cards)
    {
        std::cout << card << '|';
    }

    for (auto card : cards) {
        full_deck.push(card);
    }
}

Card Deck::DrawCard ()
{
    Card card = full_deck.front();
    full_deck.pop();
    return card;
}

int Deck::Size ()
{   
    return full_deck.size ();
}

void Deck::Clear ()
{   
    while (full_deck.size () != 0) 
    {
        full_deck.pop ();
    }
}