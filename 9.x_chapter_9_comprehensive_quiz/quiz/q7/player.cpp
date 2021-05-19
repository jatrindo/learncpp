#include "player.h"
#include "hand.h"
#include "deck.h"

namespace Player
{
	card_t drawCardFromDeck(player_t& player, deck_t& deck)
	{
		// Draw card from deck and put into player's hand
		card_t card{ Deck::drawCard(deck) };
		Hand::addCard(card, player.hand);
		return card;
	}
}
