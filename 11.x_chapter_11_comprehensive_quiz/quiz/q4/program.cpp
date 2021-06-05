/*
 * Start by copying the original program into your IDE, and then commenting out
 * everything except the #include lines.
 *
 * a) Let’s start by making Card a class instead of a struct. The good news is
 * that the Card class is pretty similar to the Monster class from the previous
 * quiz question. 
 *
 * First, create private members to hold the rank and suit (name them m_rank and
 * m_suit accordingly). 
 *
 * Second, create a public constructor for the Card class so we can initialize
 * Cards. 
 *
 * Third, make the class default constructible, either by adding a default
 * constructor or by adding default arguments to the current constructor.
 *
 * Finally, move the printCard() and getCardValue() functions inside the class
 * as public members (remember to make them const!).
 *
 *
 * b) Okay, now let’s work on a Deck class. The deck needs to hold 52 cards, so
 * use a private std::array member to create a fixed array of 52 cards named
 * m_deck. Second, create a constructor that takes no parameters and initializes
 * m_deck with one of each card (modify the code from the original createDeck()
 * function). Third, move printDeck into the Deck class as a public member.
 * Fourth, move shuffleDeck into the class as a public member.
*
* The trickiest part of this step is initializing the deck using the modified
* code from the original createDeck() function. The following hint shows how to
* do that.
*
* The following test program should compile:
*
* int main()
* {
*   Deck deck{}; deck.print(); deck.shuffle(); deck.print(); return 0;
* }
*
*
* c) Now we need a way to keep track of which card is next to be dealt (in the
* original program, this is what nextCardIndex was for).
*
* First, add a member named m_cardIndex to Deck and initialize it to 0.
*
* Create a public member function named dealCard(), which should return a const
* reference to the current card and advance m_cardIndex to the next index.
* shuffle() should also be updated to reset m_cardIndex (since if you shuffle
* the deck, you’ll start dealing from the top of the deck again).
*
* The following test program should compile:
*
* int main()
* {
*   Deck deck{};
*
*   deck.shuffle(); deck.print();
*
*   std::cout << "The first card has value: " << deck.dealCard().value() <<
*   '\n'; std::cout << "The second card has value: " << deck.dealCard().value()
*   << '\n';
*
*   return 0;
* }
*/
#include <algorithm>
#include <array>
#include <cassert>
#include <ctime>
#include <iostream>
#include <random>

enum class CardSuit
{
  SUIT_CLUB,
  SUIT_DIAMOND,
  SUIT_HEART,
  SUIT_SPADE,

  MAX_SUITS
};

enum class CardRank
{
  RANK_2,
  RANK_3,
  RANK_4,
  RANK_5,
  RANK_6,
  RANK_7,
  RANK_8,
  RANK_9,
  RANK_10,
  RANK_JACK,
  RANK_QUEEN,
  RANK_KING,
  RANK_ACE,

  MAX_RANKS
};

class Card
{
private:
  CardRank m_rank{};
  CardSuit m_suit{};

public:
  Card() = default;

  Card(CardRank rank, CardSuit suit)
      : m_rank{rank}, m_suit{suit}
  {
  }

  void print() const
  {
    switch (m_rank)
    {
    case CardRank::RANK_2:
      std::cout << '2';
      break;
    case CardRank::RANK_3:
      std::cout << '3';
      break;
    case CardRank::RANK_4:
      std::cout << '4';
      break;
    case CardRank::RANK_5:
      std::cout << '5';
      break;
    case CardRank::RANK_6:
      std::cout << '6';
      break;
    case CardRank::RANK_7:
      std::cout << '7';
      break;
    case CardRank::RANK_8:
      std::cout << '8';
      break;
    case CardRank::RANK_9:
      std::cout << '9';
      break;
    case CardRank::RANK_10:
      std::cout << 'T';
      break;
    case CardRank::RANK_JACK:
      std::cout << 'J';
      break;
    case CardRank::RANK_QUEEN:
      std::cout << 'Q';
      break;
    case CardRank::RANK_KING:
      std::cout << 'K';
      break;
    case CardRank::RANK_ACE:
      std::cout << 'A';
      break;
    default:
      std::cout << '?';
      break;
    }

    switch (m_suit)
    {
    case CardSuit::SUIT_CLUB:
      std::cout << 'C';
      break;
    case CardSuit::SUIT_DIAMOND:
      std::cout << 'D';
      break;
    case CardSuit::SUIT_HEART:
      std::cout << 'H';
      break;
    case CardSuit::SUIT_SPADE:
      std::cout << 'S';
      break;
    default:
      std::cout << '?';
      break;
    }
  }

  int value() const
  {
    if (m_rank <= CardRank::RANK_10)
    {
      return (static_cast<int>(m_rank) + 2);
    }

    switch (m_rank)
    {
    case CardRank::RANK_JACK:
    case CardRank::RANK_QUEEN:
    case CardRank::RANK_KING:
      return 10;
    case CardRank::RANK_ACE:
      return 11;
    default:
      assert(false && "should never happen");
      return 0;
    }
  }
};

class Deck
{
public:
  using deck_type = std::array<Card, 52>;
  using index_type = deck_type::size_type;

private:
  deck_type m_deck{};
  index_type m_cardIndex{0};

public:
  Deck()
  {
    index_type card{0};

    auto suits{static_cast<index_type>(CardSuit::MAX_SUITS)};
    auto ranks{static_cast<index_type>(CardRank::MAX_RANKS)};

    for (index_type suit{0}; suit < suits; ++suit)
    {
      for (index_type rank{0}; rank < ranks; ++rank)
      {
        m_deck[card] = Card{static_cast<CardRank>(rank), static_cast<CardSuit>(suit)};
        ++card;
      }
    }
  }

  void print()
  {
    for (const auto &card : m_deck)
    {
      card.print();
      std::cout << ' ';
    }

    std::cout << '\n';
  }

  void shuffle()
  {
    static std::mt19937 mt{static_cast<std::mt19937::result_type>(std::time(nullptr))};

    std::shuffle(m_deck.begin(), m_deck.end(), mt);
    m_cardIndex = 0; // reset the index after shuffling
  }

  const Card &dealCard()
  {
    return m_deck[m_cardIndex++];
  }
};

// The following test program should compile:
int main()
{
  Deck deck{};

  deck.shuffle();
  deck.print();

  std::cout << "The first card has value: " << deck.dealCard().value() << '\n';
  std::cout << "The second card has value: " << deck.dealCard().value()
            << '\n';

  return 0;
}
// struct Player
// {
//   int score{};
// };

// // Maximum score before losing.
// constexpr int maximumScore{ 21 };

// // Minium score that the dealer has to have.
// constexpr int minimumDealerScore{ 17 };

// bool playerWantsHit()
// {
//   while (true)
//   {
//     std::cout << "(h) to hit, or (s) to stand: ";

//     char ch{};
//     std::cin >> ch;

//     switch (ch)
//     {
//     case 'h':
//       return true;
//     case 's':
//       return false;
//     }
//   }
// }

// // Returns true if the player went bust. False otherwise.
// bool playerTurn(const deck_type& deck, index_type& nextCardIndex, Player& player)
// {
//   while (true)
//   {
//     std::cout << "You have: " << player.score << '\n';

//     if (player.score > maximumScore)
//     {
//       return true;
//     }
//     else
//     {
//       if (playerWantsHit())
//       {
//         player.score += getCardValue(deck[nextCardIndex++]);
//       }
//       else
//       {
//         // The player didn't go bust.
//         return false;
//       }
//     }
//   }
// }

// // Returns true if the dealer went bust. False otherwise.
// bool dealerTurn(const deck_type& deck, index_type& nextCardIndex, Player& dealer)
// {
//   while (dealer.score < minimumDealerScore)
//   {
//     dealer.score += getCardValue(deck[nextCardIndex++]);
//   }

//   return (dealer.score > maximumScore);
// }

// bool playBlackjack(const deck_type& deck)
// {
//   index_type nextCardIndex{ 0 };

//   Player dealer{ getCardValue(deck[nextCardIndex++]) };

//   std::cout << "The dealer is showing: " << dealer.score << '\n';

//   Player player{ getCardValue(deck[nextCardIndex]) + getCardValue(deck[nextCardIndex + 1]) };
//   nextCardIndex += 2;

//   if (playerTurn(deck, nextCardIndex, player))
//   {
//     return false;
//   }

//   if (dealerTurn(deck, nextCardIndex, dealer))
//   {
//     return true;
//   }

//   return (player.score > dealer.score);
// }

// int main()
// {
//   auto deck{ createDeck() };

//   shuffleDeck(deck);

//   if (playBlackjack(deck))
//   {
//     std::cout << "You win!\n";
//   }
//   else
//   {
//     std::cout << "You lose!\n";
//   }

//   return 0;
// }