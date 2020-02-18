#include	<iostream.h>

//--- ‚˜‚ğ‚Qæ‚µ‚½’l‚ğ•Ô‹p‚·‚é ---//
inline double square(double x)
{
	return (x * x);
}

//--- ‚˜‚ğ‚Ræ‚µ‚½’l‚ğ•Ô‹p‚·‚é ---//
inline double cube(double x)
{
	return (x * x * x);
}

int main(void)
{
	double  a;

	cout << "À”’l‚ğ“ü—Í‚µ‚Ä‚­‚¾‚³‚¢F";
	cin >> a;

	cout << a << "‚Ì‚Qæ‚Í" << square(a) << "‚Å‚·B\n";
	cout << a << "‚Ì‚Ræ‚Í" << cube(a)   << "‚Å‚·B\n";

	return (0);
}

/*
Às—á
À”’l‚ğ“ü—Í‚µ‚Ä‚­‚¾‚³‚¢F4.2¥
4‚Ì‚Qæ‚Í17.64‚Å‚·B
4‚Ì‚Ræ‚Í74.088‚Å‚·B
*/
