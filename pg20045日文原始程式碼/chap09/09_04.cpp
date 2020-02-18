#include	<iostream.h>

int main(void)
{
	int	  asize;
	int	  i;
	int*  a;

	cout << "要素数を入力してください：";
	cin >> asize;

	a = new int[asize];

	for (i = 0; i < asize; i++)
		a[i] = i;

	for (i = 0; i < asize; i++)
		cout << "a[" << i << "] = " << a[i] << '\n';

	delete[] a;

	return (0);
}

/*
実行例
要素数を入力してください：5▼
a[0] = 0
a[1] = 1
a[2] = 2
a[3] = 3
a[4] = 4
*/