#include	<iostream.h>

int main(void)
{
	double  sum;

	for (int i = 0; i <= 1000; i++)
		sum += i / 1E+3;

	cout << "0.000����1.000�̘a�F" << sum << '\n';

	return (0);
}
/*
���s����
0.000����1.000�̘a�F500.5
*/
