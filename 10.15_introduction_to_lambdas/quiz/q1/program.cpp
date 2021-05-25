/*
 * Create a struct Student that stores the name and points of a student.
 *
 * Create an array of students and use std::max_element to find the student
 * with the most points, then print the student's name.
 *
 * std::max_element takes the begin and end of a list, and a function that
 * takes 2 parameters and returns true if the first argument is less than the
 * second.
 *
 * Given the following array:
 *
 * 	std::array<Student, 8> arr{
 * 		{
 * 		  { "Albert", 3 },
 * 		  { "Ben", 5 },
 * 		  { "Christine", 2 },
 * 		  { "Dan", 8 }, // Dan has the most points (8).
 * 		  { "Enchilada", 4 },
 * 		  { "Francis", 1 },
 * 		  { "Gred", 3 },
 * 		  { "Hagrid", 5 }
 * 		}
 * 	};
 *
 * Your program should print:
 *
 * 	Dan is the best student
*/
#include <iostream>
#include <array>
#include <algorithm>

struct Student
{
	std::string name{};
	int points{ 0 };
};

int main()
{
	std::array<Student, 8> arr{
		{
			{ "Albert", 3 },
			{ "Ben", 5 },
			{ "Christine", 2 },
			{ "Dan", 8 }, // Dan has the most points (8).
			{ "Enchilada", 4 },
			{ "Francis", 1 },
			{ "Gred", 3 },
			{ "Hagrid", 5 }
		}
	};

	// Note: The function you give std::max_element has to be written such
	// that is returns 'true' if the first argument is __less than__ the
	// second
	const auto most_points_student{
		std::max_element(arr.begin(), arr.end(),
				[](const auto& first, const auto& second) -> bool
				{
					return first.points < second.points;
				})
	};

	// Note: std::max_element returns an iterator
	std::cout << most_points_student->name << " is the best student\n";

	return 0;
}
