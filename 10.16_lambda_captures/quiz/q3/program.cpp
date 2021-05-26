/*
 * We're going to write a little game with square numbers (numbers which can
 * be created by multiplying an integer with itself (1, 4, 9, 16, 25, ...)).
 *
 * Ask the user to input 2 numbers, the first is the square root of the number
 * to start at, the second is the amount of numbers to generate.
 *
 * Generate a random integer from 2 to 4, and square numbers in the range that
 * was chosen by the user. Multiply each square number by the random number. You
 * can assume that the user enters valid numbers.
 *
 * The user has to calculate which numbers have been generated. The program
 * checks if the user guessed correctly and removes the guessed number from the
 * list. If the user guessed wrong, the game is over and the program prints the
 * number that was closest to the user's final guess, but only if the final
 * guess was not off by more than 4.
 *
 * Here are a couple of sample sessions to give you a better understanding of
 * how the game works:
 *
 * 	-----------------------------------------------------------------------
 *
 * 	Start where? 4
 * 	How many? 8
 * 	I generated 8 square numbers. Do you know what each number is after
 * 	multiplying it by 2?
 * 	> 32
 * 	Nice! 7 number(s) left.
 * 	> 72
 * 	Nice! 6 number(s) left.
 * 	> 50
 * 	Nice! 5 number(s) left.
 * 	> 126
 * 	126 is wrong! Try 128 next time.
 *
 * 	-----------------------------------------------------------------------
 *
 * 	Start where? 1
 * 	How many? 3
 * 	I generated 3 square numbers. Do you know what each number is after
 * 	multiplying it by 4?
 * 	> 4
 * 	Nice! 2 number(s) left.
 * 	> 16
 * 	Nice! 1 number(s) left.
 * 	> 36
 * 	Nice! You found all numbers, good job!
 *
 * 	-----------------------------------------------------------------------
 *
 * 	Start where? 2
 * 	How many? 2
 * 	I generated 2 square numbers. Do you know what each number is after
 * 	multiplying it by 4?
 * 	> 21
 * 	21 is wrong!
 *
 * 	-----------------------------------------------------------------------
*/
#include <iostream>
#include <algorithm> // std::find
#include <vector>
#include <random> // std::mt19937
#include <ctime> // std::time
#include <cmath> // std::abs

using list_t = std::vector<int>;

namespace Config
{
	constexpr int factorMin{ 2 };
	constexpr int factorMax{ 4 };
	constexpr int distForHint{ 4 };
}

int askStart()
{
	std::cout << "Start where?: ";
	int start{};
	std::cin >> start;
	return start;
}

int askHowMany()
{
	std::cout << "How many?: ";
	int how_many{};
	std::cin >> how_many;
	return how_many;
}

int genRandomFactor()
{
	static std::mt19937 mersenne_gen{
		static_cast<std::mt19937::result_type>(std::time(nullptr))
	};

	std::uniform_int_distribution die{Config::factorMin, Config::factorMax};

	return die(mersenne_gen);
}

int askGuess()
{
	std::cout << "> ";
	int guess{};
	std::cin >> guess;
	return guess;
}

// Initializes the squares array given as first argument
void initFactoredSquares(list_t& squares, int start, int how_many, int factor)
{
	// Resize the array to fit the squares
	squares.resize(static_cast<std::size_t>(how_many));

	int i{ start };
	for (auto& square: squares)
	{
		square = (( i * i ) * factor);
		++i;
	}
}

// Returns value of the element that is the closest numerical distance to val
// across all elements of vect
int findClosestValue(list_t& vect, int val)
{
	auto closest{
		std::min_element(vect.begin(), vect.end(),
			[val](const int a, const int b) {
				return std::abs(a - val) < std::abs(b - val);
			})
	};

	// Array was empty
	if (closest == vect.end())
		return 0;

	return *closest;
}

// Returns true if found and removed, false otherwise
bool findAndRemove(list_t& vect, int val)
{
	auto found{ std::find(vect.begin(), vect.end(), val) };

	if (found == vect.end())
		return false; // Not found

	// Found, so remove
	vect.erase(found);
	return true;
}

int main()
{

	const int start{ askStart() };
	const int how_many{ askHowMany() };
	const int factor{ genRandomFactor() };

	// Initialize the squares, already multiplied by the factor
	list_t squares{};
	initFactoredSquares(squares, start, how_many, factor);

	// Report to users
	std::cout << "I generated " << how_many << " square numbers. Do you "
		  "know what each number is after multiplying it by " << factor
		  << "?\n";

	// Guessing loop
	for (int turns_left{ how_many - 1 }; turns_left >= 0; --turns_left)
	{
		// Ask for the user's guess
		int guess{ askGuess() };

		// See if the user's guess is in the factored_squares
		if (findAndRemove(squares, guess))
		{
			// User's guess found!
			if (turns_left > 0)
			{
				std::cout << "Nice! " << turns_left << " number(s) left.\n";
			}
			else
			{
				std::cout << "Nice! You found all the numbers, good job!\n";
				// End the game
				break;
			}
		}
		else
		{
			std::cout << guess << " is wrong!";

			// Find the closest numerical distance to guess, and
			// determine if we should mention a hint
			int closest{ findClosestValue(squares, guess) };
			if (closest <= Config::distForHint)
			{
				// If the user was close, let them know what to try next time
				std::cout << " Try " << closest << " next time.\n";
			}
			else
			{
				std::cout << '\n';
			}

			// One wrong guess ends the game
			break;
		}
	}

	return 0;
}
