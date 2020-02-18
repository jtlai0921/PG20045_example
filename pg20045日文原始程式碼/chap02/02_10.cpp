#include	<iostream.h>

int main(void)
{
	int	 a;

	cout << "正の整数値を入力せよ：";
	cin >> a;

	switch (a % 2) {
	 case  0: cout << "偶数です。\n";  break;
	 default: cout << "奇数です。\n";  break;
	}

	return (0);
}

/*
実行例（1）
正の整数値を入力せよ：7▼
奇数です。
実行例（2）
正の整数値を入力せよ：4▼
偶数です。
*/
