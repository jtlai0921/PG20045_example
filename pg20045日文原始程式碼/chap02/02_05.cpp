#include	<iostream.h>

int main(void)
{
	int	 a;

	cout << "整数値を入力せよ：";
	cin >> a;

	if (a)
		cout << "非０です。\n";
	else
		cout << "０です。\n";

	return (0);
}

/*
実行例（1）
整数値を入力せよ：7▼
非０です。
実行例（2）
整数値を入力せよ：0▼
０です。
*/