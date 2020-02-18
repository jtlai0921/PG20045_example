#include	<iostream.h>

//--- ２つの整数a,bの最小値を返却する ---//
int minof(int a, int b)
{
	return (a < b ? a : b);
}

//--- ３つの整数a,b,cの最小値を返却する ---//
int minof(int a, int b, int c)
{
	int	 min = a;
	if (b < min) min = b;
	if (c < min) min = c;
	return (min);
}

//--- 要素数ｎの配列ｘの最小値を返却する ---//
int minof(int x[], int n)
{
	int	 min = x[0];
	for (int i = 1; i < n; i++)
		if (x[i] < min)
			min = x[i];
	return (min);
}

int main(void)
{
	int	 x, y, z;

	cout << "ｘの値を入力してください：";
	cin >> x;

	cout << "ｙの値を入力してください：";
	cin >> y;

	cout << "ｘとｙの小さい方の値は" << minof(x, y) << "です。\n\n";

	cout << "ｚの値を入力してください：";
	cin >> z;

	cout << "ｘ,ｙ,ｚの最小値は" << minof(x, y, z) << "です。\n\n";

	const int  max = 5;
	int  a[max];

	cout << max << "個の値を入力してください：\n";
	for (int i = 0; i < max; i++) {
		cout << "a[" << i << "] = ";
		cin >> a[i];
	}
	cout << "配列ａの要素の値の最小値は" << minof(a, max) << "です。\n";

	return (0);
}

/*
実行例
ｘの値を入力してください：10▼
ｙの値を入力してください：5▼
ｘとｙの小さい方の値は5です。

ｚの値を入力してください：8▼
ｘ,ｙ,ｚの最小値は5です。

5個の値を入力してください：
a[0] = 10▼
a[1] = 20▼
a[2] = 50▼
a[3] = 30▼
a[4] = 5▼
配列ａの要素の値の最小値は5です。
*/
