#ifndef DECK_H
#define DECK_H

#include <array>
#include <cstddef> // std::size_t

#include "card.h"

constexpr int num_cards_in_deck_t{ static_cast<int>(CardRank::max_ranks) * static_cast<int>(CardSuit::max_suits) };

struct deck_t
{
	std::array<card_t, num_cards_in_deck_t> cards{};
	std::size_t next_card_index{ 0 };
};

namespace Deck
{

	// Creates an unshuffled deck
	deck_t createDeck();
	// Prints the deck cards in order, from beginning to end
	void printDeck(const deck_t& deck);
	// Shuffles the cards in the deck
	void shuffleDeck(deck_t& deck);
	// Draws a card from the specified deck
	card_t drawCard(deck_t& deck);
}

#endif // DECK_H
