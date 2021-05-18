#include <vector>
#include "blackjack.h"
#include "player.h"

// Player names
const std::string player_name{ "PLAYER" };
const std::string dealer_name{ "DEALER" };
// Blackjack game parameters
constexpr int bust_limit{ 21 };
constexpr int dealer_stand_limit{ 17 };

bool playBlackjack(deck_t& deck)
{
	// Initialize players
	player_t player{};	
	player.name = player_name;
	player_t dealer{};
	dealer.name = dealer_name;

	// PLAYER'S TURN
	// Player gets two cards to start
	Player::drawCardFromDeck(player, deck);
	Player::drawCardFromDeck(player, deck);

	return false;

	// TD: Implement the below

	//// Player does their thing (ask input from user to hit or stand)
	//// returns true if the player hits and wants to continue
	//// returns false if the player stands or busts, ending their turn
	//askPlayerToHitOrStand(player);


	//// DEALER'S TURN
	//// Dealer gets one card to start
	//drawCardForPlayer(dealer);

	//// Dealer auto-plays (repeatedly draws until they reach a score of 17
	//// or more, at which point they stand)
	//while (getSumOfHand(dealer) <= dealer_stand_limit) {
	//	player_hit(dealer);
	//}

	//// Did the dealer bust?
	//if (getSumOfHand(dealer) > bust_limit)
	//{
	//	// player wins!
	//	return declareWinner(player);
	//}
	//else
	//{
	//	// dealer stands
	//	player_stand(dealer);
	//}

	//// neither the player nor dealer busted, see who wins
	//if (getSumOfHand(player) > getSumOfHand(dealer))
	//	return declareWinner(player);
	//else
	//	return declareWinner(dealer);
}

