#include	<iostream.h>

int main(void)
{
	int*  x = new int;

	cout << "®”‚ð“ü—Í‚µ‚Ä‚­‚¾‚³‚¢F";

	cin >> *x;

	cout << "*x = " << *x << '\n';

	delete x;

	return (0);
}

/*
ŽÀs—á
®”‚ð“ü—Í‚µ‚Ä‚­‚¾‚³‚¢F5¥
*x = 5
*/
