#include "hand.h"

namespace Hand
{
	void addCard(card_t card, hand_t& hand)
	{
		// Forgot that we didn't need to track the acutal cards
		// The below wouldn't work because resizing the vector would
		// fill it with cards somehow|
		//// If adding one more card would be larger than what the vector could
		//// hold, resize the vector to fit
		//if (hand.num_cards + 1 >= hand.cards.size())
		//{
		//	// We'll double to save calls to resize
		//	hand.cards.resize((hand.num_cards + 1) * 2);
		//}

		//// Add the card to the hand
		//hand.cards[hand.num_cards] = card;
		++hand.num_cards;

		// Update the hand sum
		hand.value += Card::getCardValue(card);
	}

	int getHandValue(hand_t& hand)
	{
		return hand.value;
	}
}
