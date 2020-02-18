#include	<iostream.h>

int main(void)
{
	int	 a;

	cout << "®”‚ğ“ü—Í‚µ‚Ä‚­‚¾‚³‚¢F";

	cin >> a;

	int* x = new int(a);

	cout << "*x = " << *x << '\n';

	delete x;

	return (0);
}

/*
Às—á
®”‚ğ“ü—Í‚µ‚Ä‚­‚¾‚³‚¢F8¥
*x = 8
*/
