#include	<iostream.h>

int main(void)
{
	int	 a;

	cout << "整数を入力してください：";

	cin >> a;

	int* x = new int(a);

	cout << "*x = " << *x << '\n';

	delete x;

	return (0);
}

/*
実行例
整数を入力してください：8▼
*x = 8
*/
