#include	<iostream.h>

int main(void)
{
	double  sum;

	for (int i = 0; i <= 1000; i++)
		sum += i / 1E+3;

	cout << "0.000‚©‚ç1.000‚Ì˜aF" << sum << '\n';

	return (0);
}
/*
ŽÀsŒ‹‰Ê
0.000‚©‚ç1.000‚Ì˜aF500.5
*/
