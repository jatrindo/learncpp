#include <iostream>

#include "card.h"

// Prints two-letter code indicating card rank and suit
void printCard(const Card& card)
{
	char rank_code{};
	char suit_code{};

	switch (card.rank)
	{
		case CardRank::two:	rank_code = '2'; break;
		case CardRank::three:	rank_code = '3'; break;
		case CardRank::four:	rank_code = '4'; break;
		case CardRank::five:	rank_code = '5'; break;
		case CardRank::six:	rank_code = '6'; break;
		case CardRank::seven:	rank_code = '7'; break;
		case CardRank::eight:	rank_code = '8'; break;
		case CardRank::nine:	rank_code = '9'; break;
		case CardRank::ten:	rank_code = 'T'; break;
		case CardRank::jack:	rank_code = 'J'; break;
		case CardRank::queen:	rank_code = 'Q'; break;
		case CardRank::king:	rank_code = 'K'; break;
		case CardRank::ace:	rank_code = 'A'; break;
		default:
			rank_code = '?';
	}

	switch (card.suit)
	{
		case CardSuit::clubs:		suit_code = 'C'; break;
		case CardSuit::diamonds:	suit_code = 'D'; break;
		case CardSuit::hearts:		suit_code = 'H'; break;
		case CardSuit::spades:		suit_code = 'S'; break;
		default:
			suit_code = '?';
	}

	std::cout << rank_code << suit_code;
}

// Returns the card's value based on its rank
int getCardValue(const Card& card)
{
	int value{};
	switch (card.rank)
	{
		case CardRank::two:	value = 2; break;
		case CardRank::three:	value = 3; break;
		case CardRank::four:	value = 4; break;
		case CardRank::five:	value = 5; break;
		case CardRank::six:	value = 6; break;
		case CardRank::seven:	value = 7; break;
		case CardRank::eight:	value = 8; break;
		case CardRank::nine:	value = 9; break;
		case CardRank::ten:
		case CardRank::jack:
		case CardRank::queen:
		case CardRank::king:
					value = 10; break;
		case CardRank::ace:	value = 11; break;
		default:
			value = 0; // Should never happen
	}
	return value;
}
