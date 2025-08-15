#pragma once

#include <iostream>

class Card
{
public:
    Card();
    Card (char type, int value);
    int GetPoints ();
    int GetPower ();

    bool operator==(const Card& card) const;

    char type;
    int value; 
};

std::ostream& operator<<(std::ostream& os, const Card& card);
