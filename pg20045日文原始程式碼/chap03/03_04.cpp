#include	<iostream.h>

int main(void)
{
	int	 a;

	cout << "正の整数値を入力せよ：";
	cin >> a;

	while (a >= 0) {
		cout << a << ' ';				// ａを出力
		a--;								// ａをデクリメント
	}
	cout << '\n';						// 改行する

	return (0);
}

/*
実行例
正の整数値を入力せよ：5▼
5 4 3 2 1 0
*/