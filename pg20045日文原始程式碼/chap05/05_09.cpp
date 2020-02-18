#include	<iostream.h>

//--- 要素数ｎの配列ｘの最小値を返却する ---//
int minof(int x[], int n)
{
	int	 min = x[0];
	for (int i = 1; i < n; i++)
		if (x[i] < min) min = x[i];
	return (min);
}

int main(void)
{
	const int  max = 5;						// 配列aの要素数
	int a[max];

	for (int i = 0; i < max; i++) {			// 配列aに値を読み込む
		cout << "a[" << i << "] = ";
		cin >> a[i];
	}

	cout << "最小値：" << minof(a, max) << '\n';

	return (0);
}

/*
実行例
a[0] = 10▼
a[1] = 12▼
a[2] = 100▼
a[3] = 95▼
a[4] = 82▼
最小値：10
*/
