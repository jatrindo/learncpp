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

// TD: Change to card_t
struct Card
{
	CardRank rank{};
	CardSuit suit{};
};

// TD: Enclose this in a 'Card' namespace
// Prototypes
void printCard(const Card& card);
int getCardValue(const Card& card);

#endif // CARD_H
