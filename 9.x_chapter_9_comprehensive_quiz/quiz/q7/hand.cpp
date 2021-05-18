#include "hand.h"

namespace Hand
{
	void addCard(Card card, hand_t& hand)
	{
		// If adding one more card would be larger than what the vector could
		// hold, resize the vector to fit
		if (hand.num_cards + 1 >= hand.cards.size())
		{
			// We'll double to save calls to resize
			hand.cards.resize((hand.num_cards + 1) * 2);
		}

		// Add the card to the hand
		hand.cards[hand.num_cards] = card;
		++hand.num_cards;
	}
}
