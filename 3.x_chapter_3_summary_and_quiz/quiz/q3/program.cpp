/*
 * What does the call stack look like in the following program when the point
 * of execution is on line 4 (note: 8 in this file)?
*/
#include <iostream>

void d()
{ // here
}

void c()
{
}

void b()
{
	c();
	d();
}

void a()
{
	b();
}

int main()
{
	a();

	return 0;
}
