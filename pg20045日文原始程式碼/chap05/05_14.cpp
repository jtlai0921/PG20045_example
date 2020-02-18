#include	<iostream.h>

//--- nの階乗を求める ---//
int factorial(int n)
{
	if (n != 0)
		return (n * factorial(n-1));
	return (1);
}

int main(void)
{
	int x;

	cout << "整数ｘを入力せよ：";
	cin >> x;

	cout << "ｘの階乗は" << factorial(x) << "です。\n";

	return (0);
}

/*
実行例（1）
整数ｘを入力せよ：5▼
ｘの階乗は120です。

実行例（2）
整数ｘを入力せよ：0▼
ｘの階乗は1です。
*/
