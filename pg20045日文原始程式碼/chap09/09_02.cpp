#include	<iostream.h>

int main(void)
{
	int*  x = new int;

	cout << "整数を入力してください：";

	cin >> *x;

	cout << "*x = " << *x << '\n';

	delete x;

	return (0);
}

/*
実行例
整数を入力してください：5▼
*x = 5
*/
