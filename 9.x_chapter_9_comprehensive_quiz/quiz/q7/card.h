#ifndef CARD_H
#define CARD_H

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

struct Card
{
	CardRank rank{};
	CardSuit suit{};
};

// Prototypes
void printCard(const Card& card);
int getCardValue(const Card& card);

#endif // CARD_H
