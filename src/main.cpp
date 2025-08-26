#include <raylib.h>
#include "cards.h"
#include "deck.h"
#include <ctime>
#include "GameState.h"
#include <iostream>

int main () 
{
    srand(time(0));

    GameState state;
    state.NewGame();
    state.Print();
    state.RoundThrow(state.GetPlayerOneHand()[0], state.GetPlayerTwoHand()[0]);
    state.Print();
}