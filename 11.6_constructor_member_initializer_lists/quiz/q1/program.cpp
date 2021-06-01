/*
 * Write a class named RGBA that contains 4 member variables of type
 * std::uint_fast8_t named m_red, m_green, m_blue, and m_alpha
 * (#include cstdint to access type std::uint_fast8_t).
 *
 * Assign default values of 0 to m_red, m_green, and m_blue, and 255 to m_alpha.
 *
 * Create a constructor that uses a member initializer list that allows the user
 * to initialize values for m_red, m_blue, m_green, and m_alpha.
 *
 * Include a print() function that outputs the value of the member variables.
 *
 * The following (main()) code should run and produce the result:
 *
 * 	r=0 g=127 b=127 a=255
*/
int main()
{
	RGBA teal{ 0, 127, 127 };
	teal.print();

	return 0;
}
