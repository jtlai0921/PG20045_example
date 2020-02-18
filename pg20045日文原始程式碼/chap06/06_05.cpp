#include	<iostream.h>

int x = 555;

void print_x(void)							/*--- ‡@ ---*/
{
	cout << "x" << x << '\n';						// (f)
}

int main(void)
{
	cout << "x" << x << '\n';						// (a)

	int x = 333;							/*--- ‡A ---*/

	cout << "x" << x << '\n';						// (b)

	for (int i = 0; i < 5; i++) {
		int x = i * 100;					/*--- ‡B ---*/
		cout << "x" << x << '\n';					// (c)
	}

	cout << "x" << x << '\n';						// (d)
	cout << "::x" << ::x << '\n';					// (e)

	print_x();

	return (0);
}

