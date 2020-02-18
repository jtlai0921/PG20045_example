#include	<iostream.h>

int main(void)
{
	int		x;
	double	a;

	cout << "ｘのアドレス：" << &x << '\n';
	cout << "ｙのアドレス：" << &a << '\n';

	return (0);
}

/*
実行結果一例
ｘのアドレス：FFFD
ｙのアドレス：FFFC
*/
