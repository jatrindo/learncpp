#include <iostream>
#include <algorithm> // std::shuffle
#include <random> // std::mt19937
#include <ctime> // std::time

#include "deck.h"

namespace Deck
{

	deck_t createDeck()
	{
		deck_t deck{};

		std::size_t card_index{ 0 };
		int num_ranks{ static_cast<int>(CardRank::max_ranks) };
		int num_suites{ static_cast<int>(CardSuit::max_suits) };

		for (int suit{ 0 }; suit < num_suites; ++suit)
		{
			for (int rank{ 0 }; rank < num_ranks; ++rank)
			{
				deck.cards[card_index].suit = static_cast<CardSuit>(suit);
				deck.cards[card_index].rank = static_cast<CardRank>(rank);
				++card_index;
			}
		}

		return deck;
	}

	void printDeck(const deck_t& deck)
	{
		for (const auto& card: deck.cards)
		{
			printCard(card);
			std::cout << ' ';
		}
		std::cout << '\n';
	}

	void shuffleDeck(deck_t& deck)
	{
		// Initialize (once, via 'static') PRNG
		static std::mt19937 shuffle_mersenne{
			static_cast<std::mt19937::result_type>(std::time(nullptr))
		};

		// Shuffle
		std::shuffle(deck.cards.begin(), deck.cards.end(), shuffle_mersenne);
	}

	Card drawCard(deck_t& deck)
	{
		return deck.cards[deck.next_card_index++];
	}
}
