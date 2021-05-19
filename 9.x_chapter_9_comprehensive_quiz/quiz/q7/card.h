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

struct card_t
{
	CardRank rank{};
	CardSuit suit{};
};

namespace Card
{
	void printCard(const card_t& card);
	int getCardValue(const card_t& card);
}

#endif // CARD_H
