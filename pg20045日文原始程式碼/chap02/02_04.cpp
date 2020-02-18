#include	<iostream.h>

int main(void)
{
	int	 a, b;

	cout << "整数値ａを入力せよ：";
	cin >> a;

	cout << "整数値ｂを入力せよ：";
	cin >> b;

	cout << "a <  b : " << (a <  b) << '\n';
	cout << "a >  b : " << (a >  b) << '\n';
	cout << "a <= b : " << (a <= b) << '\n';
	cout << "a >= b : " << (a >= b) << '\n';

	return (0);
}

/*
実行例（1）
整数値ａを入力せよ：7▼
整数値ｂを入力せよ：12▼
a <  b : 1
a >  b : 0
a <= b : 1
a >= b : 0
実行例（2）
整数値ａを入力せよ：5▼
整数値ｂを入力せよ：5▼
a <  b : 0
a >  b : 0
a <= b : 1
a >= b : 1
*/