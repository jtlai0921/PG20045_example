#include	<iostream.h>

int main(void)
{
	int	 x;

	cout << "整数値ｘを入力せよ：";
	cin >> x;

	if (x % 3)
		cout << "ｘは３で割り切れません。\n";

	return (0);
}

/*
実行例（1）
整数値ｘを入力せよ：5▼
ｘは３で割り切れません。
実行例（2）
整数値ｘを入力せよ：6▼
*/