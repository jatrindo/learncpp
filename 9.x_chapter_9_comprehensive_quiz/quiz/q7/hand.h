#ifndef HAND_H 
#define HAND_H

#include <vector>
#include <cstdint> // for std::size_t

#include "card.h"

struct hand_t
{
	//std::vector<card_t> cards{};
	std::size_t num_cards{ 0 }; // acts as index where next card should go
	int value{ 0 }; // sum of the cards held in hand
};

namespace Hand
{
	// Adds a card to the given player's hand, updating its contents and sum
	void addCard(card_t card, hand_t& hand);
	int getHandValue(hand_t& hand);
}
#endif // HAND_H
