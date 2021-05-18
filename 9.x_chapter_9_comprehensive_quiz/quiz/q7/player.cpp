#include "player.h"
#include "hand.h"
#include "deck.h"

namespace Player
{
	void drawCardFromDeck(player_t& player, deck_t& deck)
	{
		// Draw card from deck and put into player's hand
		Hand::addCard(Deck::drawCard(deck), player.hand);
	}
}
