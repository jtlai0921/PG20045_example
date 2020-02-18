#include	<iostream.h>

//--- x,yの大きい方の値を返却する ---//
int maxof(int x, int y)
{
	if (x > y)
		return (x);
	return (y);
}

int main(void)
{
	int	 a, b;

	cout << "整数値を入力せよ：";
	cin >> a;

	cout << "整数値を入力せよ：";
	cin >> b;

	cout << "大きい方は" << maxof(a, b) << "です。\n";

	return (0);
}

/*
実行例
整数値を入力せよ：10▼
整数値を入力せよ：20▼
大きい方は20です。
*/
