#pragma once

#include <iostream>

enum class CardType {
    SPADE,
    COPPE,
    DENARI,
    BASTONI,
};


class Card
{
public:
    Card();
    Card (CardType type, int value);
    int GetPoints ();
    int GetPower ();

    bool operator==(const Card& card) const;

    CardType type;
    int value; 
};

std::ostream& operator<<(std::ostream& os, const CardType& card_type);
std::ostream& operator<<(std::ostream& os, const Card& card);
