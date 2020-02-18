#include	<iostream.h>

int main(void)
{
	int	 a;
	int	 keta = 0;

	cout << "整数値を入力せよ：";
	cin >> a;

	do {
		a = a / 10;
		keta++;
	} while (a);

	cout << "その数は" << keta << "桁です。\n";

	return (0);
}

/*
実行例
整数値を入力せよ：123▼
その数は3桁です。
*/