/*
 * Given the array in question 1:
 *
 * Ask the user for a number between 1 and 9. If the user does not enter a
 * number between 1 and 9, repeatedly ask for an integer value until they do.
 *
 * Once they have entered a number between 1 and 9, print the array. Then
 * search the array for the value that the user entered and print the index
 * of that element.
 *
 * You can test std::cin for invalid input by using the following code:
 *
 *	// if the user entered something invalid
 *	if (std::cin.fail())
 *	{
 *	std::cin.clear();
 *	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // ignore any characters in the input buffer
 *	}
*/
