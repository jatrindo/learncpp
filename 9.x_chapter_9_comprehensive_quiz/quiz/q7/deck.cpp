#include <iostream>
#include <algorithm> // std::shuffle
#include <random> // std::mt19937
#include <ctime> // std::time

#include "deck.h"

DeckInfo::deck_t createDeck()
{
	DeckInfo::deck_t deck{};

	DeckInfo::deck_index_t card_index{ 0 };
	int num_ranks{ static_cast<int>(CardRank::max_ranks) };
	int num_suites{ static_cast<int>(CardSuit::max_suits) };

	for (int suit{ 0 }; suit < num_suites; ++suit)
	{
		for (int rank{ 0 }; rank < num_ranks; ++rank)
		{
			deck[card_index].suit = static_cast<CardSuit>(suit);
			deck[card_index].rank = static_cast<CardRank>(rank);
			++card_index;
		}
	}

	return deck;
}

void printDeck(const DeckInfo::deck_t& deck)
{
	for (const auto& card: deck)
	{
		printCard(card);
		std::cout << ' ';
	}
	std::cout << '\n';
}

void shuffleDeck(DeckInfo::deck_t& deck)
{
	// Initialize (once, via 'static') PRNG
	static std::mt19937 shuffle_mersenne{
		static_cast<std::mt19937::result_type>(std::time(nullptr))
	};

	// Shuffle
	std::shuffle(deck.begin(), deck.end(), shuffle_mersenne);
}
