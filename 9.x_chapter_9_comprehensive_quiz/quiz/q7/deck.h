#ifndef DECK_H
#define DECK_H

#include <array>
#include <cstddef> // std::size_t

#include "card.h"

// Don't want to pollute the global namespace, so the following deck info
// is put in its own namespace
namespace DeckInfo
{
	constexpr int num_cards_in_deck_t{ static_cast<int>(CardRank::max_ranks) * static_cast<int>(CardSuit::max_suits) };
	using deck_t = std::array<Card, num_cards_in_deck_t>;
	using deck_index_t = std::size_t;
}

// Prototypes
DeckInfo::deck_t createDeck();
void printDeck(const DeckInfo::deck_t& deck);
void shuffleDeck(DeckInfo::deck_t& deck);

#endif // DECK_H
