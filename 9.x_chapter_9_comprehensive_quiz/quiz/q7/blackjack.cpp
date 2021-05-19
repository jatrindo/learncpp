#include <iostream>
#include <vector>
#include "blackjack.h"
#include "player.h"

// Player names
const std::string player_name{ "PLAYER" };
const std::string dealer_name{ "DEALER" };
// Blackjack game parameters
constexpr int bust_limit{ 21 };
constexpr int dealer_stand_limit{ 17 };

// Imported from Q2 solution
// Checks the status of cin and clears its buffer
void checkCinAndClearBuffer()
{
        if (std::cin.eof())
		std::exit(0); // User closed the stream. Exit the program


	if (std::cin.fail())
		std::cin.clear(); // Extraction failed, clear out error flags

	// Regardless of failure, ignore any extraneous characters still left
	// in the buffer so that the next extraction won't be affected
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void reportPlayerTurn(player_t& player)
{
	std::cout << "===== " << player.name << "'s turn =====\n";
}

// true if the player's hand bust
bool checkBusted(player_t& player)
{
	int hand_value{ Hand::getHandValue(player.hand) };
	std::cout << player.name << "'s current hand value: "
		  << hand_value << '\n';
	if (hand_value > bust_limit)
	{
		std::cout << player.name << " has BUST!\n";
		return true;
	}
	return false;
}

void declareWinner(player_t& player)
{
	std::cout << "===== " << player.name << " wins! =====\n";
}


int doHit(player_t& player, deck_t& deck)
{
	// Player wants to hit, so have them draw a card and return their
	// updated hand value
	card_t card{ Player::drawCardFromDeck(player, deck) };
	int updated_value { Hand::getHandValue(player.hand) };

	// Report the hit
	std::cout << player.name << " hits, drawing a ";
	Card::printCard(card);
	std::cout << " (value = " << Card::getCardValue(card)
		  << "), bringing their total to "
		  << updated_value << '\n';

        return updated_value;
}

void doStand(player_t& player)
{
	std::cout << player.name << " stands\n";
}

// Returns true if the player will continue
// Returns false if the player will not continue (either chooses to stand
// or busts)
bool askHitOrStand(player_t& player, deck_t& deck)
{
	checkBusted(player);

	char response{};
	do
	{
		std::cout << "Would you like to [h]it or [s]tand?: ";
		std::cin >> response;
		checkCinAndClearBuffer();
	} while (response != 'h' && response != 's');

	if (response == 'h')
	{
		return (doHit(player, deck) <= bust_limit);
	}

	// The player chose not to continue
	doStand(player);
	return false;
}

bool playBlackjack(deck_t& deck)
{
	// Initialize players
	player_t player{};	
	player.name = player_name;
	player_t dealer{};
	dealer.name = dealer_name;

	// PLAYER'S TURN
	reportPlayerTurn(player);
	// Player gets two cards to start
	Player::drawCardFromDeck(player, deck);
	Player::drawCardFromDeck(player, deck);

	// Ask the player to hit or stand until they either stand or bust
	while (askHitOrStand(player, deck)) {}

	if (checkBusted(player))
	{
		declareWinner(dealer);
		return false;
	}

	// DEALER'S TURN
	reportPlayerTurn(dealer);

	// Dealer gets one card to start
	Player::drawCardFromDeck(dealer, deck);

	// This call is just to report the dealer's current hand score
	checkBusted(dealer);

	while(doHit(dealer, deck) < dealer_stand_limit) {}

	if (checkBusted(dealer))
	{
		declareWinner(player);
		return true;
	}

	// If the dealer didn't bust, than they stand
	doStand(dealer);

	// At this point neither player busted, so compare the score to see
	// who won
	return (Hand::getHandValue(player.hand) > Hand::getHandValue(dealer.hand));
}
