/*
 * Write the following program:
 *
 * Create a struct that holds a student's first name and grade (on a scale
 * of 0-100).
 *
 * Ask the user how many students they want to enter. Create a std::vector to
 * hold all of the sutdents. Then prompt the user for each name and grade.
 *
 * Once the user has entered all the names and grade pairs sort the list by
 * grade (highest first).
 *
 * Then print all the names and grades in sorted order.
 *
 * For the following input:
 *
 * 	Joe
 * 	82
 * 	Terry
 * 	73
 * 	Ralph
 * 	4
 * 	Alex
 * 	94
 * 	Mark
 * 	88
 *
 * The output should look like this:
 * 
 * 	Alex got a grade of 94
 * 	Mark got a grade of 88
 * 	Joe got a grade of 82
 * 	Terry got a grade of 73
 * 	Ralph got a grade of 4
 *
 * You can assume that names don't contain spaces and that input extraction doesn't fail.
*/
#include <iostream>
#include <algorithm> // std::sort
#include <vector>

struct Student
{
	std::string name{};
	int grade{};
};

// Eh. I want to do error checking anyways -- would be good practice!
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

// Loops until a name string has been successfully extracted
std::string askName(const std::string_view prompt)
{
	while(true)
	{
		std::cout << prompt;
		std::string name;
		std::cin >> name;

		checkCinAndClearBuffer();

		if (name != "")
			return name;

		std::cout << "Invalid input\n";
	}

}

// Loops until a number within range [min, max] is successfully entered
// Failed extractions result in a grade of 0
int askNumInRange(int min, int max, const std::string_view prompt)
{
	while (true)
	{
		std::cout << prompt;
		int grade{};
		std::cin >> grade;

		checkCinAndClearBuffer();

		if (grade >= min && grade <= max)
			return grade;

		std::cout << "Invalid input\n";
	}
}

Student askStudent()
{
	const int minGrade{ 0 };
	const int maxGrade { 100 };

	Student s{};
	s.name = askName("Enter the student's name: ");
	s.grade = askNumInRange(minGrade, maxGrade,
				"Enter a grade (0 to 100, inclusive): ");
	return s;
}

void printStudentInfo(Student& student)
{
	std::cout << student.name << " got a grade of "
		  << student.grade << '\n';
}

// Returns true if the 1st student has a higher grade than the 2nd student
bool hasHigherGrade(Student& s1, Student &s2)
{
	return s1.grade > s2.grade;
}

int main()
{

	std::cout << "How many students do you want to enter?: ";
	std::size_t numStudents{};
	std::cin >> numStudents;

	std::cout << "Okay! Asking for " << numStudents << " students\n";

	std::vector<Student> students(numStudents);

	// Read in each student in to the vector
	for (auto ptr{ students.begin() }; ptr != students.end(); ++ptr)
	{
		*ptr = askStudent();
	}

	// Sort the list
	std::sort(students.begin(), students.end(), hasHigherGrade);

	// Newline to separate the input from the output

	std::cout << '\n';
	// Print out each student's information
	for (Student student: students)
	{
		printStudentInfo(student);
	}


	return 0;
}
