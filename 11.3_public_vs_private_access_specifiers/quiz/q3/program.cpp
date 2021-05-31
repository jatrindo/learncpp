/*
 * Now let's try something a little more complex. Let's write a class that
 * implements a simple stack from scratch.
 *
 * The class should be named Stack, and should contain:
 * 	- A private fixed array of integers of length 10
 * 	- A private integer to keep track of the size of the stack
 * 	- A public member function named reset() that sets the size to 0
 * 	- A public member function named push() that pushes a value on the
 * 	stack. push() should return false if the array is already full, and true
 * 	otherwise
 * 	- A public member function named pop() that pops a value off the stack
 * 	and returns it. If there are no values on the stack, the code should
 * 	exit via an assert.
 * 	- A public member function named print() that prints all the values in
 * 	the stack.
 *
 * Make sure the following main() program executes correctly.
 *
 * This should print:
 * ( )
 * ( 5 3 8 )
 * ( 5 3 )
 * ( )
*/
int main()
{
	Stack stack;
	stack.reset();

	stack.print();

	stack.push(5);
	stack.push(3);
	stack.push(8);
	stack.print();

	stack.pop();
	stack.print();

	stack.pop();
	stack.pop();

	stack.print();

	return 0;
}
