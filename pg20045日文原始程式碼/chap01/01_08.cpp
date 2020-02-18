#include	<iostream.h>

int main(void)
{
	/* 変数名は問題の指示通りではありません */
	int	    a, b;		// a,bはint型
	double  x, y;		// x,yはdouble型

	cout << "sizeof(int    + int   )：" << sizeof(a + b) << '\n';
	cout << "sizeof(double + double)：" << sizeof(x + y) << '\n';
	cout << "sizeof(int    + double)：" << sizeof(a + x) << '\n';

	return (0);
}

/*
実行結果一例
sizeof(int    + int   )：2
sizeof(double + double)：8
sizeof(int    + double)：8
*/
