#include	<iostream.h>

int main(void)
{
	int	 x;
	cout << "int型の大きさ：" << sizeof(int) << '\n';
	cout << "変数xの大きさ：" << sizeof(x)   << '\n';

	double	a;
	cout << "double型の大きさ：" << sizeof(double) << '\n';
	cout << "変 数 a の大きさ：" << sizeof(a)      << '\n';

	return (0);
}

/*
実行結果一例
int型の大きさ：2
変数xの大きさ：2
double型の大きさ：8
変 数 a の大きさ：8
*/

