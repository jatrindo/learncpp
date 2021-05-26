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
