#include	<iostream.h>

//--- x,yの平均値を返却する ---//
double aveof(int x, int y)
{
	return (double(x + y) / 2);
}

int main(void)
{
	int	 a, b;

	cout << "整数値を入力せよ：";
	cin >> a;

	cout << "整数値を入力せよ：";
	cin >> b;

	cout << "平均値は" << aveof(a, b) << "です。\n";

	return (0);
}

/*
実行例
整数値を入力せよ：10▼
整数値を入力せよ：29▼
平均値は19.5です。
*/
