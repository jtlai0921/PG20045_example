#include	<iostream.h>

int main(void)
{
	double  sum;

	for (int i = 0; i <= 1000; i++)
		sum += i / 1E+3;

	cout << "0.000から1.000の和：" << sum << '\n';

	return (0);
}
/*
実行結果
0.000から1.000の和：500.5
*/
