#include	<iostream.h>

//--- 引数x, yの最大公約数を返却する ---//
int gcd(int x, int y)
{
	int	 a = (x > y) ? x : y;
	int	 b = (x > y) ? y : x;

	if (b == 0)
		return (a);
	else
		return (gcd(b, a % b));
}

int main(void)
{
	int	 x, y;

	cout << "整数値ｘを入力せよ：";
	cin >> x;

	cout << "整数値ｙを入力せよ：";
	cin >> y;

	cout << x << "と" << y << "の最大公約数は" << gcd(x, y) << "です。\n";

	return (0);
}

/*
実行例
整数値ｘを入力せよ：22▼
整数値ｙを入力せよ：8▼
22と6の最大公約数は2です。
*/
