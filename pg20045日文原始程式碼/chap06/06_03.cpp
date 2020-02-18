#include	<iostream.h>

//--- ２乗する（テンプレート版） ---//
template <class Type> Type square(Type x)
{
	return (x * x);
}

int main(void)
{
	int	 a;

	cout << "整数値を入力してください：";
	cin >> a;
	cout << a << "の２乗は" << square(a) << "です。\n";

	double	b;

	cout << "実数値を入力してください：";
	cin >> b;
	cout << b << "の２乗は" << square(b) << "です。\n";

	return (0);
}

/*
実行例
整数値を入力してください：5▼
5の２乗は25です。
実数値を入力してください：1.2▼
1.2の２乗は1.44です。
*/