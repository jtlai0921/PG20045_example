#include	<iostream.h>

int main(void)
{
	int	 a;

	cout << "整数値を入力せよ：";
	cin >> a;

	int	 pow2 = a * a;					// ２乗値
	int	 pow4 = pow2 * pow2;			// ４乗値

	cout << a << "の２乗は" << pow2 << "です。\n";		// ２乗を表示
	cout << a << "の４乗は" << pow4 << "です。\n";		// ４乗を表示

	return (0);
}

/*
実行例
正の整数値を入力せよ：3▼
3の２乗は9です。
3の４乗は81です。
*/