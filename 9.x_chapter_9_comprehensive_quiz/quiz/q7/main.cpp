/*
 * Alright, challenge time! Let's write a simplified version of Blackjack.
 *
 * (...Blackjack rules explanation...)
 *
 * In our simplified version of Blackjack, we're not going to keep track of
 * which specific cards that player and dealer have dealt. We'll only track
 * the sum of the values of the cards they have been dealt for the player and
 * dealer. This keeps things simpler.
 *
 * Start with the code you wrote in quiz #6. Create a function named
 * playBlackjack(). The function should:
 * 
 * 	- Accept a shuffled deck of cards as a parameter.
 * 	- Implement Blackjack as defined above.
 * 	- Returns true if the player won, and false if they lost.
 *
 * Also, write a main() function to play a single game of Blackjack.
*/
#include <iostream>

#include "deck.h"
#include "blackjack.h"

int main()
{
	// Create and shuffle a deck
	auto deck{ Deck::createDeck() };
	Deck::shuffleDeck(deck);

	// Play some Blackjack
	if (playBlackjack(deck))
		std::cout << "The player won the game of Blackjack!\n";
	else
		std::cout << "The player lost the game of Blackjack :(\n";

	return 0;
}
