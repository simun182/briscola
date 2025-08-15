#include "GameState.h"
#include "cards.h"
#include <vector>
#include <bits/stdc++.h>

GameState::GameState ()
{
    ThrowingFirst = 1;
}

void GameState::NewGame ()
{
    deck = Deck ();
    deck.Shuffle ();
    adut_card = deck.DrawCard ();

    for (int i = 0; i < 3; i ++)
    {
        player_one_hand.push_back (deck.DrawCard ());
        player_two_hand.push_back (deck.DrawCard ());
    }
}

bool GameState::IsGameOver ()
{
    return (deck.Size () == 0 && player_one_hand.size () == 0 && player_two_hand.size () == 0);
}

std::vector<Card> GameState::GetPlayerOneHand() const
{
    return player_one_hand;
}

std::vector<Card> GameState::GetPlayerTwoHand() const
{
    return player_two_hand;
}

void GameState::RoundThrow (Card player_one, Card player_two)
{
    player_one_throw = player_one;
    player_two_throw = player_two;
    player_one_hand.erase (find (player_one_hand.begin (), player_one_hand.end (), player_one_throw));
    player_two_hand.erase (find (player_two_hand.begin (), player_two_hand.end (), player_two_throw));
}

int GameState::WhoWonRound ()
{
    Card Compare;
    if (player_one_throw.type == adut_card.type && player_two_throw.type != adut_card.type)
    {
        return 1;
    }
    if (player_one_throw.type != adut_card.type && player_two_throw.type == adut_card.type)
    {
        return 2;
    }
    if (player_one_throw.type != player_two_throw.type)
    {
        return ThrowingFirst;
    }
    if (player_one_throw.GetPower() > player_one_throw.GetPower())
    {
        return 1;
    }
    return 2;
}

void GameState::GetPoints ()
{
    if (WhoWonRound () == 1)
    {
        player_one_points += player_one_throw.GetPoints ();
        player_one_points += player_two_throw.GetPoints ();
        ThrowingFirst = 1;
    } else 
    {
        player_two_points += player_one_throw.GetPoints ();
        player_two_points += player_two_throw.GetPoints ();
        ThrowingFirst = 2;
    }
}

void GameState::Print () 
{
    deck.Print();
    std::cout << std::endl;
    std::cout << "Briscola: " << adut_card << std::endl;
    std::cout << "Player 1 hand: ";
    for (const auto card : player_one_hand) 
    {
        std::cout << card << ' ';
    }
    std::cout << "\nPlayer 2 hand: ";
    for (const auto card : player_two_hand) 
    {
        std::cout << card << ' ';
    }
    std::cout << std::endl;
}
