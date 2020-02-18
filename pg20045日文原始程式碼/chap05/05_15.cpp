#include	<iostream.h>

//--- 異なるｎ個からｒ個を取り出す組み合わせの数を返却する ---//
int combination(int n, int r)
{
	if (r == 0 || r == n)
		return (1);
	else if (r == 1)
		return (n);
	return (combination(n - 1, r - 1) + combination(n - 1, r));
}

int main(void)
{
	int		n, r;

	cout << "整数値ｎを入力せよ："; cin >> n;
	cout << "整数値ｒを入力せよ："; cin >> r;

	cout << "combination(" << n << ',' << r << ")= " << combination(n, r) << '\n';

	return (0);
}

/*
実行例
整数値ｎを入力せよ：5▼
整数値ｒを入力せよ：3▼
combination(5,3)= 10
*/
