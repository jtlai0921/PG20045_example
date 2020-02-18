#include	<iostream.h>

int main(void)
{
	int	 a;

	cout << "整数値を入力せよ：";
	cin >> a;

	if (a > 0) {						// 読み込んだ整数値が正であれば…
		do {
			cout << a % 10;				// もっとも下の桁の数字を出力
			a = a / 10;					// 右に１桁ずらす
		} while (a > 0);
		cout << '\n';
	}

	return (0);
}

/*
実行例
整数値を入力せよ：1235▼
5321
*/