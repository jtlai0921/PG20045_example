#include	<iostream.h>

//--- ４つの引数の最大値を返却する ---//
unsigned maxof(unsigned a, unsigned b, unsigned c = 0, unsigned d = 0)
{
	int	 max = a;
	if (b > max) max = b;
	if (c > max) max = c;
	if (d > max) max = d;
	return (max);
}

int main(void)
{
	unsigned  a, b, c, d;

	cout << "非負の整数値を入力せよ：\n";
	cout << "a = "; cin >> a;		cout << "b = "; cin >> b;
	cout << "c = "; cin >> c;		cout << "d = "; cin >> d;

	cout << "maxof(a, b ,c ,d) = " << maxof(a, b ,c ,d) << '\n';
	cout << "maxof(a, b ,c)    = " << maxof(a, b ,c)    << '\n';
	cout << "maxof(a, b)       = " << maxof(a, b)       << '\n';

	return (0);
}

/*
実行結果
非負の整数値を入力せよ：
a = 10▼
b = 20▼
c = 30▼
d = 40▼
maxof(a, b, c, d) = 40
maxof(a, b, c)    = 30
maxof(a, b)       = 20
*/
