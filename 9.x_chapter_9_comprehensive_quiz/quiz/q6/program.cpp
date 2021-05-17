/*
 * Let's pretend we're writing a card game.
 *
 * a) A deck of cards has 52 unique cards (13 card ranks of 4 suits). Create
 * enumerations for the card rands (2, 3, 4, 5, 6, 7, 8, 9, 10, Jack, Queen,
 * King, Ace) and suits (clubs, diamonds, hearts, spades). Those enumerators
 * will not be used to index arrays.
 *
 * b) Each card will be represented by a struct named Card that contains a
 * rank and a suit. Create the struct.
 *
 * c) Create a printCard() function that takes a const Card reference as a
 * parameter and prints the card rank and suit as a 2-letter code (e.g. the
 * jack of spades would print as JS).
 *
 * d) A deck of cards has 52 cards. Create an array (using std::array) to
 * represent the deck of cards, and initialize it with one of each card. Do
 * this in a function named createDeck() and call createDeck from main.
 * createDeck should return the deck to main.
 *
 * e) Write a function named printDeck() that takes the deck as a const
 * reference parameter and prints the cards in the deck. Use a range-based
 * for-loop. When you can printDeck with the deck you generated in the previous
 * task, the output should be:
 *
 * 	2C 3C 4C 5C 6C 7C 8C 9C TC JC QC KC AC 2D 3D 4D 5D 6D 7D 8D 9D TD JD QD
 * 	KD AD 2H 3H 4H 5H 6H 7H 8H 9H TH JH QH KH AH 2S 3S 4S 5S 6S 7S 8S 9S TS
 * 	JS QS KS AS
 *
 * f) Write a function named shuffleDeck to shuffle the deck of cards using
 * std::shuffle. Update your main function to shuffle the deck and print out
 * the shuffled deck.
 * Reminder: Only seed your random number generator once.
 *
 * g) Write a function named getCardValue() that returns the value of a Card
 * (e.g. a 2 is worth 2, a then, jack, queen, or king, is worth 10. Assume an
 * Ace is worth 11).
*/
#include <iostream>
#include <array>
#include <cstddef> // std::size_t

// Answer for a) -- Start
enum class CardRank
{
	two,
	three,
	four,
	five,
	six,
	seven,
	eight,
	nine,
	ten,
	jack,
	queen,
	king,
	ace,

	max_ranks
};

enum class CardSuit
{
	clubs,
	diamonds,
	hearts,
	spades,

	max_suits
};
// Answer for a) -- End

// Answer for b) -- Start
struct Card
{
	CardRank rank{};
	CardSuit suit{};
};

// Answer for b) -- End

// Answer for c) -- Start
// Prints two-letter code indicating card rank and suit
void printCard(const Card& card)
{
	char rank_code{};
	char suit_code{};

	switch (card.rank)
	{
		case CardRank::two:
			rank_code = '2';
			break;
		case CardRank::three:
			rank_code = '3';
			break;
		case CardRank::four:
			rank_code = '4';
			break;
		case CardRank::five:
			rank_code = '5';
			break;
		case CardRank::six:
			rank_code = '6';
			break;
		case CardRank::seven:
			rank_code = '7';
			break;
		case CardRank::eight:
			rank_code = '8';
			break;
		case CardRank::nine:
			rank_code = '9';
			break;
		case CardRank::ten:
			rank_code = 'T';
			break;
		case CardRank::jack:
			rank_code = 'J';
			break;
		case CardRank::queen:
			rank_code = 'A';
			break;
		case CardRank::king:
			rank_code = 'K';
			break;
		case CardRank::ace:
			rank_code = 'A';
			break;
		default:
			rank_code = '?';
	}

	switch (card.suit)
	{
		case CardSuit::clubs:
			suit_code = 'C';
			break;
		case CardSuit::diamonds:
			suit_code = 'D';
			break;
		case CardSuit::hearts:
			suit_code = 'H';
			break;
		case CardSuit::spades:
			suit_code = 'S';
			break;
		default:
			suit_code = '?';
	}

	std::cout << rank_code << suit_code;
}
// Answer for c) -- End

// Answer for d) -- Start
// Don't want to pollute the global namespace, so the following deck info
// is put in its own namespace
namespace DeckInfo
{
	constexpr int num_cards{ static_cast<int>(CardRank::max_ranks) * static_cast<int>(CardSuit::max_suits) };
	using deck_t = std::array<Card, num_cards>;
	using deck_index_t = std::size_t;
}

DeckInfo::deck_t createDeck()
{
	DeckInfo::deck_t deck{};

	DeckInfo::deck_index_t card_index{ 0 };
	int num_ranks{ static_cast<int>(CardRank::max_ranks) };
	int num_suites{ static_cast<int>(CardSuit::max_suits) };

	for (int rank{ 0 }; rank < num_ranks; ++rank)
	{
		for (int suit{ 0 }; suit < num_suites; ++suit)
		{
			deck[card_index].suit = static_cast<CardSuit>(suit);
			deck[card_index].rank = static_cast<CardRank>(rank);
			++card_index;
		}
	}

	return deck;
}
// Answer for d) -- End
int main()
{
	auto deck{ createDeck() };
	return 0;
}
