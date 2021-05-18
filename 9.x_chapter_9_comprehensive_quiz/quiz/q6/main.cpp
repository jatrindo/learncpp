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

#include "deck.h"

int main()
{
	auto deck{ createDeck() };
	shuffleDeck(deck);
	printDeck(deck);

	return 0;
}
