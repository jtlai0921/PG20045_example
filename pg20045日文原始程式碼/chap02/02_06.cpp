#include	<iostream.h>

int main(void)
{
	int	 month;

	cout << "ŒŽ‚ð“ü—Í‚µ‚Ä‚­‚¾‚³‚¢F";
	cin >> month;

	if (month >= 3 && month <= 5)
		cout << month << "ŒŽ‚Ít‚Å‚·B\n";
	else if (month >= 6 && month <= 8)
		cout << month << "ŒŽ‚Í‰Ä‚Å‚·B\n";
	else if (month >= 9 && month <= 11)
		cout << month << "ŒŽ‚ÍH‚Å‚·B\n";
	else
		cout << month << "ŒŽ‚Í“~‚Å‚·B\n";

	return (0);
}

/*
ŽÀs—á
ŒŽ‚ð“ü—Í‚µ‚Ä‚­‚¾‚³‚¢F3¥
3ŒŽ‚Ít‚Å‚·B
*/
