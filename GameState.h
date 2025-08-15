#pragma once
#include <vector>
#include "cards.h"
#include "deck.h"

class GameState 
{
public:
    GameState ();
    void NewGame ();
    bool IsGameOver ();
    int WhoWonRound (); // returns 1 if player one won, 2 if player two won
    void RoundThrow (Card player_one, Card player_two);
    std::vector<Card> GetPlayerOneHand() const;
    std::vector<Card> GetPlayerTwoHand() const;
    void GetPoints ();
    void Print();
    int ThrowingFirst;
private:
    Deck deck;
    int player_one_points;
    int player_two_points;
    Card adut_card;
    Card draw_card;
    Card player_one_throw;
    Card player_two_throw;
    std::vector <Card> player_one_hand;
    std::vector <Card> player_two_hand;
};

