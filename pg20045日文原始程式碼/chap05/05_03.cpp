#include	<iostream.h>

//--- 浮動小数点数xのn乗を返却する ---//
double power(double x, int n)
{
	double	a = 1.0;

	if (n > 0)				// nが0より大きい場合
		for (int i = 0 ; i < n ; i++)
			a *= x;
	else					// nが0以下の場合
		for (int i = 0 ; i > n ; i--)
			a /= x;

	return (a);
}

int main(void)
{
	double	a;
	int		b;

	cout << "実数値を入力せよ：";
	cin >> a;

	cout << "整数値を入力せよ：";
	cin >> b;

	cout << a << "の" << b << "乗は" << power(a, b) << "です。\n";

	return (0); 
}

/*
実行例（1）
実数値を入力せよ：3.3▼
整数値を入力せよ：2▼
3.3の2乗は10.89です。

実行例（2）
実数値を入力せよ：5.0▼
整数値を入力せよ：-2▼
5.0の-2乗は0.04です。

実行例（3）
実数を入力せよ：2.5▼
整数値を入力せよ：0▼
2.5の0乗は1です。
*/
