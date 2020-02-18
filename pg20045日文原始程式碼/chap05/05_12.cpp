#include	<iostream.h>

//--- 要素数ｎの配列ｘの中から値ｋを見つけだし、その添え字を返却 ---//
int search(int x[], int n, int k)
{
	for (int i = 0; i < n; i++)
		if (x[i] == k)
			return (i);
	return (-1);
}

int main(void)
{
	const int n = 5;
	int a, x[n];

	cout << "配列ｘの各要素の値を入力せよ：\n";
	for (int i = 0; i < n; i++) {
		cout << "x[" << i << "] = ";
		cin >> x[i];
	}
	cout << "探索したい値を入力せよ：";
	cin >> a;

	int pos = search(x, n, a);
	if (pos == -1)
		cout << "その数は配列ｘ中にありません。\n";
	else
		cout << "その数はx[" << pos << "]と等しいです。\n";

	return (0);
}

/*
実行例
配列ｘの各要素の値を入力せよ：
x[0] = 10▼
x[1] = 50▼
x[2] = 60▼
x[3] = 25▼
x[4] = 50▼
探索したい値を入力せよ：50
その数はx[1]と等しいです。
*/
