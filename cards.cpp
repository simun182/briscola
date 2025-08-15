#include "cards.h"

Card::Card () {}

Card::Card (char type, int value) : type{type}, value{value} {

}

int Card::GetPoints ()
{
    switch (value)
    {
        case 1: return 11;
        case 3: return 10;
        case 13: return 4;
        case 12: return 3;
        case 11: return 2;
        default: return 0;
    }
}

int Card::GetPower ()
{
    switch (value)
    {
        case 1: return 10;
        case 2: return 1;
        case 3: return 9;
        case 4: return 2;
        case 5: return 3;
        case 6: return 4;
        case 7: return 5;
        case 11: return 6;
        case 12: return 7;
        case 13: return 8;
        default: return 0;
    }
}

bool Card::operator==(const Card& card) const 
{
    return type == card.type && value == card.value;
}

std::ostream& operator<<(std::ostream& os, const Card& card) {
    return os << card.type << card.value;
}