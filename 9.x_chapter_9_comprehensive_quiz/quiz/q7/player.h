#ifndef PLAYER_H
#define PLAYER_H

#include <string>

#include "hand.h"
#include "deck.h"

struct player_t
{
	std::string name{};
	hand_t hand{};
};

namespace Player
{
	// Have the player draw a card from the specified deck
	void drawCardFromDeck(player_t& player, deck_t& deck);
}
#endif // PLAYER_H
